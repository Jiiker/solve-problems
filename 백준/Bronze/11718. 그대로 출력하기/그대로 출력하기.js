const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

let lines = [];

readline.on('line', function(input) {
    lines.push(input); 
}).on('close', function(){
    for (let i = 0; i < lines.length; i++) {
        console.log(lines[i]);
    }
    process.exit();
})