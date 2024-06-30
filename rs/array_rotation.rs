"""rustc 1.71.0

Time complexity: O(n)
Space complexity: O(1)
"""

use std::iter::Iterator;

fn solution(nums: &mut [i32], n: usize) -> &mut [i32] {
    let size = nums.len();

    for (index, num) in nums.iter_mut().enumerate() {
        let prev = nums[(index + n) % size];
        nums[(index + n) % size] = nums[index];
        nums[index] = prev;
    }
    
    return nums;
}

fn main() {
    let nums = &mut [1, 2, 3, 4, 5];
    println!("{:?}", solution(nums, 8));
}
