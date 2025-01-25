const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

let lines = [];

readline.on('line', function(input) {
    lines.push(input); 
}).on('close', function(){
    let isPalindrome = true;
    for (let i = 0; i < lines[0].length; i++) {
        if (lines[0][i] !== lines[0][lines[0].length - 1 - i]) {
            isPalindrome = false;
        }
    }
    
    if (isPalindrome) {
        console.log('1');
    } else {
        console.log('0');
    }
    
    process.exit();
})