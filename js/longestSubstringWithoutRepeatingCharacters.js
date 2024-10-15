/*node 18.12.1

Time complexity: O(n)
Space complexity: O(n)
*/

function solution(string) {
  let count = 0;
  let temp = [];

  for (let i = 0; i < string.length; i++) {
    if (!temp.includes(string[i])) {
      temp.push(string[i]);
    } else {
      if (temp.length > count) {
        count = temp.length;
      }
      temp.length = 0;
      temp.push(string[i]);
    }

    if (i == string.length - 1 && count == 0) {
      return temp.length;
    }
  }

  return count;
}

const strings = ["abcabccb", "dorime", "hokpol"];
for (string of strings) {
  console.log(solution(string));
}
