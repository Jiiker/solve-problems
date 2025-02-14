const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((el) => el.split(" ").map(Number));

const dx = [-1, 0, 1, 1];
const dy = [1, 1, 1, 0];

function isWinner(x, y, t) {
  for (let dir = 0; dir < 4; dir++) {
    let nx = x;
    let ny = y;
    let count = 0;

    while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && input[nx][ny] === t) {
      nx += dx[dir];
      ny += dy[dir];
      count++;
    }

    if (count === 5) {
      let px = x - dx[dir];
      let py = y - dy[dir];

      if (px >= 0 && px < 19 && py >= 0 && py < 19 && input[px][py] === t) {
        continue;
      }

      return true;
    }
  }

  return false;
}

for (let i = 0; i < 19; i++) {
  for (let j = 0; j < 19; j++) {
    if (input[i][j] !== 0 && isWinner(i, j, input[i][j])) {
      console.log(`${input[i][j]}\n${i + 1} ${j + 1}`);
      process.exit(0);
    }
  }
}

console.log(0);
