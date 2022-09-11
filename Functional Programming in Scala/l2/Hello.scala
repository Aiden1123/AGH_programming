object Hello {

  def main(args: Array[String]):Unit = {
   val desiredLength = args(0).toInt
    args(0) = (args.length - 1).toString
    printLength(desiredLength, args)
  }

  def printLength(len: Int,arr: Array[String]): Unit = {
    val spacesPerGap = ((len - charCount(arr))/(arr.length-1)).toInt
    print(arr.mkString(" " * spacesPerGap))
    println(" " * (len - charCount(arr) - spacesPerGap * arr.length))
  }

  def charCount(arr: Array[String]): Int = {
    return (for {x <- arr} yield x.length).toArray.sum
  }
}
