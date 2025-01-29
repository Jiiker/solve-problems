const input = require('fs').readFileSync(process.platform === 'linux' ? 'dev/stdin' : './input.txt')
.toString()
.trim()
.split('\n')
.map(el => el.split(' '));

let credit_sum = 0.00;
let grade_sum = 0.00;

for (let i = 0; i < input.length; i++) {
    let score = 0.00;
    if (input[i][2][0] === 'P') {
        continue;   
    } else if (input[i][2][0] === 'A') {
        score += 4.00;
    } else if (input[i][2][0] === 'B') {
        score += 3.00;
    } else if (input[i][2][0] === 'C') {
        score += 2.00;
    } else if (input[i][2][0] === 'D') {
        score += 1.00;
    } else {
        credit_sum += parseFloat(input[i][1]);
        continue;
    }
    
    if (input[i][2][1] === '+') {
        score += 0.5;
    }
    
    credit_sum += parseFloat(input[i][1]);
    grade_sum += parseFloat(input[i][1]) * score;
}

process.stdout.write(`${grade_sum / credit_sum}`)