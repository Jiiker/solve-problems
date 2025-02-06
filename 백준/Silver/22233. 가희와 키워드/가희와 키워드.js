const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

let N, M;
const S = new Set();
const result = [];
let lineCount = 0;

rl.on("line", (line) => {
  if (lineCount === 0) {
    [N, M] = line.split(" ").map(Number);
  } else if (lineCount <= N) {
    S.add(line);
  } else {
    line.split(",").forEach((el) => S.delete(el.trim()));
    result.push(S.size);
  }
  lineCount++;

  if (lineCount === N + M + 1) {
    console.log(result.join("\n"));
    rl.close();
  }
});
