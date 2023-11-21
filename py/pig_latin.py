"""python 3.10.12

Time complexity: O(n + m)
Space complexity: O(n + m)
"""


def solution(string):
    vowels = ["a", "e", "i", "o", "u"]
    arr = string.split()
    res = ""
    for word in arr:
        if res:
            res += " "
        if word[0] in vowels:
            word += "way"
        else:
            word = word[1:] + word[0] + "ay"
        res += word
    return res


string = "hello world"
print(solution(string))
