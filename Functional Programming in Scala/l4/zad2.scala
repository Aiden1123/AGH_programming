object zad2 {
  def main(args: Array[String]): Unit = {
    val x = List(-3,10, 90, 89, 12, 5, -5, 12, -16, 9908)
    val mm = minmax( x )
    print(mm)
  }

  def minmax(l: List[Int]): (Int,Int) = {
    if (l.length == 1) (l(0),l(0)) else findMinMax(l.slice(1,l.length),l(0),l(0))
  }

  @scala.annotation.tailrec
  def findMinMax(l: List[Int], min: Int, max: Int): (Int,Int) = {
    if (l.isEmpty) (min,max) else {
      val currMin = if (l.head < min) l.head else min
      val currMax = if (l.head > max) l.head else max
      findMinMax(l.tail, currMin, currMax)
    }
  }

}
