abstract class container(drink: String, volume: Double, price: Int, alcoholic: Boolean) {
  def isAlcoholic: Boolean = alcoholic
  def Volume: Double = volume
  def Drink: String = drink
}


case class Cup(drink: String, volume: Double, price: Int,alcoholic: Boolean) extends container(drink,volume,price,alcoholic)
case class Glass(drink: String, volume: Double, price: Int, alcoholic: Boolean) extends container(drink,volume,price,alcoholic)
case class Jug(drink: String, volume: Double, price: Int, alcoholic: Boolean) extends container(drink,volume,price,alcoholic)

object zad2 extends App{

  val l = List( Cup("Tea", 0.3, 5, false),
                Glass("Juice", 0.5, 10, false),
                Jug("Budviser", 2.6, 19, true),
                Glass("Burgundy", 0.2, 12, true),
                Glass("Fanta", 0.74, 10, false),
                Cup("Capuccino", 0.2, 12, false),
                Glass("Red wine", 0.4, 15, true))

  //- Calculate volume of all drinks in the list.
  val totalVolume = l.foldLeft(0.0)((res, drink) => res + drink.Volume)
  println(totalVolume)

  //- Obtain a list of alcoholic drinks
  val alcoholDrinks = l.filter( _.isAlcoholic ).collect( _.Drink )
  println(alcoholDrinks)

  //- Obtain a set of all kinds of drinks
  val allDrinks = l.collect( _.Drink ).toSet
  println(allDrinks)

  //- Obtain two containers with alcoholic and non-alcoholic drinks in one call
  val alcoSplit = l.partition( _.isAlcoholic )
  println(alcoSplit._1) //contains alcohol
  println(alcoSplit._2) //doesn't contain alcohol
}
