import math._

class Point( val x: Double, val y: Double, val z: Double) {}
object Point {
  def apply(x: Double, y: Double, z: Double) : Point = {new Point(x,y,z)}
}

trait Dist extends Point{

  def compare(point: Dist): Int = {
    val length1 = math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z)
    val length2 = math.sqrt(point.x * point.x + point.y * point.y + point.z * point.z)

    if (length1 > length2) return 1
    if (length1 < length2) return -1
    0
  }

}

object zad2 {
  def main(args: Array[String]): Unit = {
    class OrdredPoint(x: Double, y: Double, z: Double) extends Point(x, y, z) with Dist with Ordered[Dist]

    val oPointA = new OrdredPoint(9, 0, 2)
    val oPointB = new OrdredPoint(3, 2, 4)

    print("A < B", oPointA < oPointB)
    print("A < A", oPointA < oPointA)
    print("A == A", oPointA == oPointA)
    print("A != A", oPointA != oPointA)
    print("A == B", oPointA < oPointB)

    //val pointA = new Point(9, 0, 2)
    //val pointB = new Point(3, 2, 4)
    //print("A<B", pointA < pointB)


    // neither this, i.e. the comparison functionality shold only come with Dist trait


  }
}

//class OrderedPointS (x: Double, y: Double, z: Double) extends Point(x,y,z) with Ordered[Dist] {
//  override def d: Double = math.hypot(math.hypot(x, y), z) // IMPORTANT HINT HERE
//}
