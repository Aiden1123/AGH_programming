class MapPoint(val name: String,val latitude: Double,val longitude: Double) {
  override def toString(): String = {name + " " +latitude.toString + " " + longitude.toString}

  def -(point: MapPoint): MapPoint = {MapPoint(name + "-" + point.name,
                                   latitude - point.latitude,
                                   longitude - point.longitude)}

  def distanceTo(point: MapPoint): (Double, Double) = {((latitude - point.latitude).abs,
                                                        (longitude - point.longitude).abs)}

  def move(shiftLatitude: Double,shiftLongitude: Double): MapPoint = {
    MapPoint(name, latitude + shiftLatitude, longitude + shiftLongitude)
  }
}

object MapPoint {
  def apply(name: String,latitude: Double, longitude: Double): MapPoint =
  {new MapPoint(name: String,latitude: Double, longitude: Double)}
}

class Route(var arr: Array[MapPoint]) {
  def addStop(point: MapPoint): Unit = {
    arr = arr :+ point
  }

  override def toString(): String = {
    var res = ""
    for(point <- arr) {
      res = res ++ point.toString
      res = res ++ "\n"
    }
    res
  }
}

object Route {
  def apply(points: MapPoint*): Route = {
    val res = new Route(new Array[MapPoint](0))
    for(point <- points)
      res.addStop(point)
    res
  }
}

object zad extends App {

  val krk = MapPoint( "Krakow", 50.061389, 19.938333 );
  println( krk );
  val nyc = MapPoint( "NYC", 40.7127, -74.0059 );
  println( nyc );
  val porto = MapPoint( "Porto", 41.162142, -8.621953 );
  val irkutsk = MapPoint( "Irkutsk",  52.283333, 104.283333 );

  println( irkutsk );
  println( porto - irkutsk )
  println( krk - irkutsk )
  println( krk.distanceTo(porto) )

  val r = Route( krk, nyc, porto )
  println( r );
  r.addStop( porto.move( 1, 1 ) )
  r.addStop( irkutsk )
  println( r ) // 5 stops trip should be printed here

}