/*C++17

Time complexity: O(n)
Space complexity: O(m)
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
    int res = 0;
    unordered_map<int, int> counter;

    for (const auto &num : nums) {
        counter[num]++;
    }

    for (int i = 0; i < nums.size() - 1; i++) {
        if (counter[nums[i] + 1] > 0) {
            res++;
        }
    }
    return res;
}

int main() {
    cout << solution({1, 2, 3}) << endl;
    return 0;
}
