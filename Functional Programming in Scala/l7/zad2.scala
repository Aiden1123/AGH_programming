case class People(name: String, fname: String, age: Int) {
  override def toString(): String = {
    "Person(" ++ name ++ "," ++ fname ++ "," ++ age.toString ++ ")"
  }
}

case class Company(name: String,origin: String) {
  override def toString(): String = {
    "Company(" ++ name ++ "," ++ origin ++ ")"
  }
}


object zad2 extends App{

  def evalMap(map: Map[String,String]) = {
    if (map.contains("company") && map.contains("origin")) new Company(map("company"),map("origin"))
    else if (map.contains("name") && map.contains("fname") && map.contains("age")) new People(map("name"),map("fname"),map("age").toInt)
    else None
  }


  def getObj(el: Any) = {
    el match {
      case map: Map[String,String] => evalMap(map)
      case _ => None
    }
  }

  def extr(data: List[Any]) = {
    val gen = for{el <- data} yield getObj(el)
    gen.toList.filter(arg => arg != None)
  }

  def onlyPeople(data: List[Any]) = {
    val gen = for{el <- data} yield getPeople(el)
    gen.toList.filter(arg => arg != None)
  }

  def getPeople(el: Any) = {
    el match {
      case p: People => p
      case _ => None
    }
  }

  def onlyComp(data: List[Any]) = {
    val gen = for{el <- data} yield getCompany(el)
    gen.toList.filter(arg => arg != None)
  }

  def getCompany(el: Any) = {
    el match {
      case c: Company => c
      case _ => None
    }
  }

  val data = List( Map("name" -> "John", "fname" -> "Smith", "age" -> "45"),
    Map("company" -> "ABB", "origin" -> "Sweden"),
    Map("name" -> "Kate", "fname" -> "Newsmith", "age" -> "45"),
    Map("company" -> "F4", "origin" -> "Poland"),
    List("Something", "else"),
    Map("company" -> "Saline Genovese", "origin" -> "Italy"),
    Map("company" -> "AGH", "origin" -> "Poland"),
    Map("name" -> "Christopher", "fname" -> "Blacksmith", "age" -> "14")
  )

  val p = extr(data)
  println(p)
  println(onlyPeople(p))
  println(onlyComp(p))
}
