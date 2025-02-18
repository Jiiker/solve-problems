const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map(Number);

const n = input[0];

for (let i = 1; i <= n; i++) {
  const num = input[i];
  let sum = 0;
  let DP = [
    [0, 0, 0],
    [1, 0, 0],
    [1, 1, 0],
    [2, 0, 1],
  ];

  for (let j = 4; j <= num; j++) {
    let start_one = DP[j - 1][0] + DP[j - 1][1] + DP[j - 1][2];
    let start_two = DP[j - 2][1] + DP[j - 2][2];
    let start_three = DP[j - 3][2];

    DP.push([start_one, start_two, start_three]);
  }

  for (let j = 0; j < 3; j++) {
    sum += DP[num][j];
  }

  console.log(sum);
}
