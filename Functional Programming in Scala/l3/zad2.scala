object zad2 {

  def main(args: Array[String]): Unit = {
    <("Hellow world") // just ptints to

    <(3)("Hellow world") // prints the string preceeding it by 3 spaces

    println(invokeAndAccumulate(3, (x: Int) => 2+x ,  4)) // no recusion needed, 3 is an innitial value of arg passed to function, 4 number of repetitions

    println(invokeAndAccumulate(2, (x: Int) => x*x ))

    println(max(4)(5))

  }

  def $less(message: String): Unit = {
    println(message)
  }

  def $less(count: Int)(message: String): Unit = {
    println(" "*count + message)
  }

  def max(arg: Int)= {
    (x: Int) => if (x>=arg) x else arg
  }

  def invokeAndAccumulate(initial: Int, fun: (Int) => Int, count: Int = 1): Int = {
    var x = initial
    for(i <- 1 to count) {x = fun(x)}
    return x
  }

}
