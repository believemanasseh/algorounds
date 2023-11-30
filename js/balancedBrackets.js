/*node 18.12.1

Time complexity: O(n)
Space complexity: O(n)
*/

function solution(string) {
  const map = {"[": "]", "{": "}", "(": ")"};
  const closed = [")", "}", "]"];
  const stack = [];

  if (string.length % 2 !== 0) {
    return false;
  }

  for (char of string) {
    if (stack.length === 0) {
      stack.push(char);
    } else {
      if (map[stack[stack.length - 1]] === char) {
        stack.pop();
      } else {
        if (closed.includes(char)) {
          return false;
        }
        stack.push(char);
      }
    }
  }
  return true;
}

console.log(solution("{[]}[]())"));
