const input = require("fs")
  .readFileSync(process.platform === "linux" ? "dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n");

let N, M;
const S = new Set();
const result = [];

input.forEach((line, index) => {
  if (index === 0) {
    [N, M] = line.split(" ").map(Number);
  } else if (index <= N) {
    S.add(line);
  } else {
    line.split(",").forEach((el) => S.delete(el.trim()));
    result.push(S.size);
  }
});

console.log(result.join("\n"));
