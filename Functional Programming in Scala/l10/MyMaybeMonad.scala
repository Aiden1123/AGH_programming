class MyMaybe(private val value: Double, private var ok: Boolean) {

  def flatMap(f : Double => MyMaybe): MyMaybe = {
    if (!this.ok) MyMaybe(0,MyMaybe.FAILED)
    else f(value)
  }

  override def toString() : String = {
   if (ok) value.toString else "Calculation failed"
  }
}

object MyMaybe {
  def apply(v: Double): MyMaybe = {
    new MyMaybe(v,SUCCESS)
  }

  def apply(v: Double,valid: Boolean): MyMaybe = {
    new MyMaybe(v,valid)
  }

  def FAILED: Boolean = false
  def SUCCESS: Boolean = true
}
