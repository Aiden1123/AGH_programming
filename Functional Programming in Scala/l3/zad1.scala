import math._

object zad1 {
  def main(args: Array[String]) = {
    //part 1

    val N = 1000000
    print("pi: ")
    println(4.0*countInsideCircle(arrayOfPoints(N))/N)

    //part 2

    def y(x: Double): Double = {1 + x*x}
    val M = 100000
    print("Integral: ")
    println(10.0 * pointsUnderFunc(y,arrayOfPointsBox(M,1,10))/M)
  }

  def countInsideCircle(arr: Array[(Double,Double)]): Int = {
    (for {x<- arr; if (x._1*x._1 + x._2*x._2 < 1)} yield x).toArray.length
  }

  def arrayOfPoints(N: Int) = {
    (for{ x <- 0 to N} yield (random(),random())).toArray
  }

  def arrayOfPointsBox(N: Int,dim1: Int,dim2: Int ) = {
    (for{ x <- 0 to N} yield (dim1*random(),dim2*random())).toArray
  }

  def pointsUnderFunc(f: (Double) => Double,arr: Array[(Double,Double)]): Int = {
    (for{x <- arr; if (x._2 < f(x._1))}yield x).length
  }

}
