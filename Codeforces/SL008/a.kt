import kotlin.io.Console
	
fun main(args: Array<String>) {
  val line = Console.readLine()
  val lineArr = line.split(' ')
  val a = Integer.parseInt(lineArr[0])
  val x = Integer.parseInt(lineArr[1])
  val y = Integer.parseInt(lineArr[2])
  println(a.toString()+' '+x+' '+y)
}
