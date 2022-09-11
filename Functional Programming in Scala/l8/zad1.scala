abstract class expr

case class Value(value: Double) extends expr
case class Sum(a: expr, b: expr) extends expr
case class Divide(a: expr, b: expr) extends expr
case class Subtract(a: expr, b: expr) extends expr
case class Multiply(a: expr, b: expr) extends expr

object zad1 extends App{
  def evaluate(expression: expr): Double = {
    expression match {
      case v: Value => v.value
      case s: Sum => evaluate(s.a) + evaluate(s.b)
      case d: Divide => evaluate(d.a) / evaluate(d.b)
      case sub: Subtract => evaluate(sub.a) - evaluate(sub.b)
      case m: Multiply => evaluate(m.a) * evaluate(m.b)
    }
  }

  println(evaluate(Divide( Subtract( Multiply( Sum(Value(1), Value(2)), Value(3)),  Value(7))  , Value(3))))
}
