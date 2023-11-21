/*kotlin 1.8.0

Time complexity: O(n)
Space complexity: O(n)
 */

fun main() {
  val strings = listOf("abcabccb", "dorime", "hopjol")
  for (string in strings) {
    println(solution(string))
  }
}

fun solution(string: String): Int {
  var count = 0
  val temp: MutableList<Char> = mutableListOf()

  for ((index, ch) in string.withIndex()) {
    if (ch !in temp) {
      temp.add(ch)
    } else {
      if (temp.size > count) {
        count = temp.size
      }
      temp.clear()
      temp.add(ch)
    }
    if (index == string.length - 1 && count == 0) {
      return temp.size
    }
  }
  return count
}
