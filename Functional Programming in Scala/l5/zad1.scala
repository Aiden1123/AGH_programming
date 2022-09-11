object zad1 {
  def main(args: Array[String]): Unit = {
    val lA = List(1, 2, 3, 4)
    val lB = List(10, 9, 8, 7)
    val lC = List(-1, -2, 1) // has only 3 elements
    val lD = List(100, 90, 80, 70, 60, 50) // has more elements
    val output = merge(List(lA, lB, lC, lD))
    println(output.mkString(", "))
  }

  def merge(l: List[List[Any]]): List[Any] = {

    @scala.annotation.tailrec
    def getHeads(l: List[List[Any]], res: List[Any]): List[Any] = {
      if (l.isEmpty) res
      else {
        val newRes = res ++ (if (l.head.isEmpty) List(null) else List(l.head.head))
        getHeads(l.tail, newRes)
      }
    }

    @scala.annotation.tailrec
    def getTails(l: List[List[Any]], res: List[List[Any]]): List[List[Any]] = {
      if (l.isEmpty) res
      else {
        val newRes = res ++ List(l.head.tail)
        getTails(l.tail, newRes)
      }
    }

    @scala.annotation.tailrec
    def mergeRec(l: List[List[Any]], res: List[Any]): List[Any] = {
      val heads = getHeads(l, List[Any]())
      if (heads.contains(null)) res
      else {
        val newRes = res ++ heads
        val tails = getTails(l, List[List[Any]]())
        mergeRec(tails, newRes)
      }
    }

    mergeRec(l, List[Any]())
  }

}