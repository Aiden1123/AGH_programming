case class Person(name: String,lastname: String, age: Int, sex: String)

object zad1 extends App{
  val people = List( Person("John", "Doe", 23, "male"), Person("Joan", "Doe", 23, "female"),
    Person("Steve", "Jenkins", 24, "male"), Person("Eva", "Robinson", 25, "female"),
    Person("Ben", "Who", 22, "male"), Person("Janet", "Reed", 21, "female"),
    Person("Rob", "Jenkins", 26, "male"), Person("Ella", "Dawson", 27, "female") )

  //- Print all people name + family name, wiht M/F before each. (in single pass - easy)
  println(people.collect(x => (if(x.sex=="male") "M " else "F ") ++ x.name ++ " " + x.lastname))

  //- Count, simultaneously all males & famales. (in single pass, so so)
  println(people.foldLeft((0,0))((tuple,person) => if (person.sex=="male")
                                                        (tuple._1,tuple._2 + 1)
                                                   else (tuple._1 + 1,tuple._2)))
  //- Obtain average age. (in single pass, hard)
  val age = people.foldLeft((0.0,0.0))((tuple,person) => (tuple._1 + person.age,tuple._2 + 1))
  println("age: " ++ (age._1/age._2).toString)

  //- Obtain average age for males and females. (in slingle pass, killer)
  val ages = people.foldLeft((0.0,0.0,0.0,0.0))((tuple,person) =>
                                          if (person.sex=="male")
                                               (tuple._1,tuple._2 + person.age,tuple._3,tuple._4 + 1)
                                          else (tuple._1 + person.age,tuple._2,tuple._3 + 1,tuple._4))

  println("males: " ++ (ages._2/ages._4).toString)
  println("females: " ++ (ages._1/ages._3).toString)
}
