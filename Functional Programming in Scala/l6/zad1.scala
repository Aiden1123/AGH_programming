import java.util.Calendar

abstract class PrintThing {
  def pprint(text: String): Unit
}

class Loger extends PrintThing {
  override def pprint(text: String): Unit = { print(text) }
}

/*
object Loger {
  def apply(): Loger = new Loger
}
*/

trait Quote extends Loger{
  abstract override def pprint(text: String): Unit = { print("\""); super.pprint(text) ; print("\"") }
}

trait TimeStamp extends Loger {
  abstract override def pprint(text: String): Unit = {print(Calendar.getInstance().getTime())
                                                      ;print(" "); super.pprint(text)}
}

object zad1 {
  def main(args: Array[String]): Unit = {
    val logger = new Loger with Quote with TimeStamp
    logger.pprint("Hello there")

    //Tue Dec 01 14:13:23 CET 2017 "Hello world"
  }
}
