"""python 3.10.12

Time complexity: O(nlogn)
Space complexity: O(nm)
"""


def solution(arr):
    anagrams = {}
    res = []

    for ar in arr:
        sorted_str = "".join(sorted(ar))
        if anagrams.get(sorted_str):
            anagrams[sorted_str].append(ar)
        else:
            anagrams[sorted_str] = [ar]

    for anagram in anagrams.values():
        res.append(anagram)

    return res


print(solution(["eat", "tea", "tan", "ate", "nat", "bat"]))
