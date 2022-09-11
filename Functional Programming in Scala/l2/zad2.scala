import scala.math.sqrt

object zad2 {
  def main(args: Array[String]):Unit = {
    val N = if (args.length > 0) args(0).toInt else 50
    println(NotSquares(N).toArray.mkString(" "))
  }

  def NotSquares(N: Int): IndexedSeq[Int] = {
    return for{x <- 1 to N; if sqrt(x)%1 != 0} yield x
  }
}
