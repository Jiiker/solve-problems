const input = require('fs').readFileSync(process.platform === 'linux' ? 'dev/stdin' : '.input.txt')
.toString()
.trim();

const number = Number(input);

let i = 1;
let n = 1;

while (i + n <= number) {
  i += n;
  n++;
}

const num = n - (number - i);
const den = n + 1 - num;

if (n % 2 !== 0) {
  process.stdout.write(`${num}/${den}`);
} else {
  process.stdout.write(`${den}/${num}`);
}