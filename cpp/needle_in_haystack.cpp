/*C++17

Time complexity: O(n)
Space complexity: O(1)
*/

#include <iostream>

using namespace std;

int solution(string haystack, string needle) {
    int count = 0;
    int index;

    if (needle.empty()) {
        return 0;
    }

    for (int i = 0; i < haystack.length(); i++) {
        if (haystack[i] == needle[count]) {
            count++;
            if (count == 1) {
                index = i;
            }
            if (count == needle.length()) {
                return index;
            }
        } else {
            if (haystack[i] == needle[count - 1]) {
                count = 1;
                index = i;
            } else {
                count = 0;
            }
        }
    }
    return -1;
}

int main() {
    cout << solution("hello", "lo") << endl;
    return 0;
}