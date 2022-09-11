class Expense(val cost: Double,val name: String,val category: String) {}

object Expense{
  def apply(cost: Double, name: String, category: String) = new Expense(cost,name,category)
}

class ExpensesList(var list: List[Expense]) {
  def +=(newExpense: Expense): ExpensesList = {list = list :+ newExpense; this}
  def printList(): Unit = {
    for (i <- list) {
      print(i.name); print(", ")
      print(i.category); print(", ")
      println(i.cost)
    }
  }
  def sum: Double = {
    var sum = 0.0
    for (i <- list) {
      sum = sum + i.cost
    }
    sum
  }

  def max: Double = {
    var max = list.head.cost
    for (i <- list) {
      if(i.cost>max) max = i.cost
    }
    max
  }
}

object ExpensesList {
  def apply() = new ExpensesList(List[Expense]())
}

object zad2 {
  def main(args: Array[String]): Unit = {

    val el = ExpensesList()

    el += Expense(5, "Bread", "food") // amount, item name, category
    el += Expense(7, "Butter", "food")
    el += Expense(3.2, "Tomatoes", "food")
    el += Expense(18, "Star Wars ticket", "entertainment")

    el.printList()

    println( el.sum )
    println( el.max )
  }
}


