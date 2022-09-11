import scala.util.{Random, Try}
import scala.concurrent._
import scala.concurrent.duration._
//import scala.concurrent.ExecutionContext.Implicits.global

object zad1 extends App{
  implicit val ec: scala.concurrent.ExecutionContext = scala.concurrent.ExecutionContext.global

  val randomString1 = Random.alphanumeric take 100 mkString ""
  val randomString2 = Random.alphanumeric take 100 mkString ""
  val message = randomString1 + "abc" + randomString2

  def psearch(s: String,target: String): Future[Boolean] = {
    val parts = 10
    val singleLength: Int = s.length/parts

    Future[Boolean]{
      var str = s
      var splits = List[String]()

      while(str.nonEmpty) {
        splits = splits :+ str.take(singleLength)
        str = str.takeRight(str.length - singleLength)
      }

      val mapped_split = splits.map{ split => Future[Boolean](split.contains(target))}
      Future.sequence(mapped_split).value.get.get.fold(false)((a,b) => a || b)

      //mapped_split.map{ f => f.value}.foldLeft(false)((a,b) => a || b.get.get)

      /*
      for(split <- splits) {

        val curr = Future[Boolean] {
          split.contains(target)
        }
        Await.ready(curr, Duration(10,"seconds"))
        curr.onComplete {
          x => res = res || x.get
        }
      }
     res
      */
    }
  }

  val search = psearch(message,"abc")
  Await.ready(search, Duration(10,"seconds"))
  search.onComplete {
    x => println(x)
  }
}
