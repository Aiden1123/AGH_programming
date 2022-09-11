import scala.concurrent.{Await, Future}
import scala.concurrent.duration.Duration
import scala.util.Random

object zad2 extends App{
  implicit val ec: scala.concurrent.ExecutionContext = scala.concurrent.ExecutionContext.global

  val randomString1 = Random.alphanumeric take 100 mkString ""
  val randomString2 = Random.alphanumeric take 130 mkString ""
  val message = randomString1 + "ac" + randomString2

  val maxLength = 10

  def psearch(s: String,target: String,maxLength: Int): Future[Boolean] = {
    if (s.length <= maxLength)
    Future[Boolean]{
      s.contains(target)
    }
    else {
      val first = psearch(s.take(s.length/2),target,maxLength)
      val second = psearch(s.takeRight(s.length/2 + 1),target, maxLength)
      first.zipWith(second)((a,b)=> a || b)
    }
  }

  val search = psearch(message,"abc",maxLength)
  Await.ready(search, Duration(10,"seconds"))
  search.onComplete {
    x => println(x)
  }
}
