const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.split(" ").map(Number));

const [N, K] = input[0];

const dp = new Array(K + 1).fill(0);

for (let i = 1; i <= N; i++) {
  const [w, v] = input[i];

  for (let j = K; j >= w; j--) {
    dp[j] = Math.max(dp[j], dp[j - w] + v);
  }
}

console.log(dp[K]);