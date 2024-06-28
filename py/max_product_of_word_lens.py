"""python 3.10.12

Time complexity: O(n^2)
Space complexity: O(n)
"""


def solution(words: list[str]) -> int:
    res = 0
    hashmap = {}

    for word in words:
        s = set(word)
        hashmap[word] = s

    for word1 in words:
        for word2 in words:
            s1 = hashmap[word1]
            s2 = hashmap[word2]
            disjoint = s1.isdisjoint(s2)
            mult = len(word1) * len(word2)

            if disjoint and mult > res:
                res = mult

    return res


words = ["abcw","baz","foo","bar","xtfn","abcdef"]
print(solution(words))
