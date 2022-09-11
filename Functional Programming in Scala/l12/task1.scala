import akka.actor.{Actor, ActorRef, ActorSystem, Props}
import akka.pattern.ask

case class FirstCarPosition(value: Int)
case class Parameters(pos: Int, step: Int)
case class Position(value: Int)

case class Move()
case class Print()
case class DistanceToLast()

class Car extends Actor {
  var behind: Option[ActorRef] = Option.empty[ActorRef]
  var pos: Int = 0
  var step: Int = 1
  def receive = {
    case param: Parameters=> pos = param.pos ; step = param.step
    case c: ActorRef => behind = Option(c)

    case DistanceToLast => if (behind.isDefined) behind.get ! FirstCarPosition(pos)
                       else println("There is only one car")

    case firstCar: FirstCarPosition => if (behind.isDefined) behind.get ! firstCar
                          else println("Distance is: " + (firstCar.value - pos).toString)

    case Print => {println("This car is at: " + pos.toString)
                     if (behind.isDefined) behind.get ! Print}

    case Move => pos+=step; if (behind.isDefined) behind.get ! Position(pos)
    case p: Position => if (pos + step < p.value) {
                          pos += step
                          if (behind.isDefined) behind.get ! Position(pos)
                        }
  }
}

object task1 extends App{

  val system = ActorSystem("system")

  val car1 = system.actorOf(Props[Car], name = "car1")
  val car2 = system.actorOf(Props[Car], name = "car2")
  val car3 = system.actorOf(Props[Car], name = "car3")
  val car4 = system.actorOf(Props[Car], name = "car4")

  car1 ! Parameters(0,2)
  car1 ! car2
  car2 ! Parameters(-1,1)
  car2 ! car3
  car3 ! Parameters(-5,3)
  car3 ! car4
  car4 ! Parameters(-10,2)

  for(i <- 1 to 10)
    car1 ! Move

  Thread.sleep(5000)

  car1 ! Print
  car1 ! DistanceToLast
}
