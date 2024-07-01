/*kotlin 1.8.0

Kadane's algorithm: https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm

Time complexity: O(n)
Space complexity: O(1)
 */


fun main() {
    val arr: IntArray = intArrayOf(-2, 1, -3, 4, -1, 2, 1, -5, 4)
    println(solution(arr))
}

fun solution(nums: IntArray): Int {
    var maxSum = nums[0]
    var currSum = 0

    for (num in nums) {
        currSum = listOf(num, currSum + num).max()
        maxSum = listOf(currSum, maxSum).max()
    }

    return maxSum
}