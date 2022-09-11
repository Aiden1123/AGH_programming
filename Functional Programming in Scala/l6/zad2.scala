class A{
  override def toString: String = "A"
}



class B( val x: Int) extends A{
  override def toString: String = "B:"+x.toString
}



class C( x: Int) extends B(x){
  override def toString: String = "C:"+x.toString
}

class TwistedMonoPair[+T](val first: T,val second: T) {
  override def toString: String = "(" ++ first.toString ++ "," ++ second.toString ++ ")"

  def apply(index: Int) = {
    if (index == 0) first else second
  }

  def replace[U >: T](index: Int)(replacement: U): TwistedMonoPair[U] = {
    if (index == 0) new TwistedMonoPair[U](replacement,second)
    else new TwistedMonoPair[U](first,replacement)
  }
}

object zad2 {
  def main(arr: Array[String]): Unit = {
    val a: TwistedMonoPair[A] = new TwistedMonoPair[A](new B(7), new A)
    println(a(0))
    println(a(1))
    println(a)
    val b: TwistedMonoPair[A] = new TwistedMonoPair[B](new B(9), new C(77)) // covariantness
    println(b)
    // val c: TwistedMonoTuple[A] = new TwistedMonoTuple[B](new B(9), new A) // should not compile (because of covariantness)

    val d1 = b.replace(0)(new A) // converts to TwistedMonoPair[A]
    println(d1)
    val tA : TwistedMonoPair[A] = d1
    //val tB : TwistedMonoPair[B] = d1// should be an error due to covariantness

    val d2 = b.replace(1)(new A) // replacing 2nd element
    println(d2)

  }
}
