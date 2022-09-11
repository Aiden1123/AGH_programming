class Memo[R,A](fun: (A) => R) {
  var memory: Map[A,R] = Map[A,R]()

  def apply(arg: A): R = {
    if (!memory.contains(arg)) memory = memory ++ Map[A,R](arg -> fun(arg))
    memory(arg)
  }
}

object cc extends App {

  def len(s:String) = {println("Calculating len of:"+ s); s.length }
  len("Hello")
  len("There")

  val mlen = new Memo(len _)
  mlen("a") // call
  mlen("a") // no call
  mlen("xyz") // do call
  mlen("dhgf")
  mlen("dhgf") // no call
  mlen("dhgf") // no call

  def repr(x:Int) = { println("string repr of " + x.toString); x.toString}
  val mrepr = new Memo(repr(_))
  mrepr(6)
  mrepr(56)
  mrepr(6) // should not happen
}