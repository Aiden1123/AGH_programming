
object zad2 extends App{
  def pow(x: Int): Int = { println("pow:"+x); x*x }
  def d2(x: Int): Int = { println("d2:"+x); x*2 }

  def powT(x: Int) = { ("pow:"+x.toString, x*x) }
  def d2T(x: Int) = { ("d2:"+x.toString, x*2) }


  def composeII(fun1: Int => Int,fun2: Int => Int): Int => Int = {
    (v: Int) => fun1(fun2(v))
  }

  def composeTT(fun1: Int => (String, Int),fun2: Int => (String, Int)): Int => (String, Int) = {
    def fun(v: Int) = {
      val res1 = fun1(v)
      val res2 = fun2(res1._2)
      (res1._1 ++ " -> " ++ res2._1, res2._2)
    }
    fun
  }

  val b = composeII( pow, d2)
  println(b(2))
  val c = composeTT( powT, d2T )
  println(c(2))
  val d = composeTT(c, powT)
  println(d(2))
}

