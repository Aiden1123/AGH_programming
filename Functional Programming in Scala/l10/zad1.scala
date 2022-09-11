import MyMaybe._

object temat extends App {

  val a = MyMaybe(9.0)
  def fail(arg: Double) : MyMaybe = MyMaybe(arg, FAILED)

  val unsuccessful = a.flatMap((x: Double) => {println("multiplying");MyMaybe(x*2)})
    .flatMap(fail _)
    .flatMap((x: Double) => {println("mult again"); MyMaybe(x*2)})
  println(unsuccessful)

  val successful = a.flatMap(x => MyMaybe(x*2)).flatMap(x => MyMaybe(x*2))
  println(successful)

}