const input = require('fs').readFileSync(process.platform === 'linux' ? 'dev/stdin' : './input.txt')
.toString()
.trim()
.split('\n')
.map(el => el.split(' ').map(Number));

const n = input[0][0];
const budget = input[2][0];
let sum = 0;

for (let i = 0; i < input[1].length; i++) {
  sum += input[1][i];
}

if (sum <= input[2][0]) {
  console.log(Math.max(...input[1]));
} else {
  let limit = Math.floor(budget / n);

  while (1) {
    let modified_sum = 0;
    for (let i = 0; i < input[1].length; i++) {
      if (input[1][i] <= limit) {
        modified_sum += input[1][i];
      } else {
        modified_sum += limit;
      }
    }

    if (modified_sum > budget) {
      limit--;
      break;
    }

    limit++;
  }

  console.log(limit);
}