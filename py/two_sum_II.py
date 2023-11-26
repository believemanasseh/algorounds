"""python 3.10.12

Time complexity: O(n)
Space complexity: O(1)
"""


def solution(nums, target):
    low, high = 0, len(nums) - 1
    while nums[low] + nums[high] != target:
        if nums[low] + nums[high] < target:
            low += 1
        else:
            high -= 1
    return [low + 1, high + 1]


print(solution([2, 7, 11, 15], 9))
