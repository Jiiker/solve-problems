const input = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : './input.txt')
  .toString()
  .trim()
  .split('\n');

const input_length = Number(input[0]);
let count = 0;

for (let i = 1; i <= input_length; i++) {
  let alpha_check = Array(26).fill(false);
  let prev = null;
  let flag = false;

  for (let j = 0; j < input[i].length; j++) {
    let charIndex = input[i].charCodeAt(j) - 'a'.charCodeAt(0);
    
    if (prev !== input[i][j] && alpha_check[charIndex]) {
      flag = true;
      break;
    }

    alpha_check[charIndex] = true;
    prev = input[i][j];
  }

  if (!flag) count++;
}

console.log(count);