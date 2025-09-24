function solution(triangle) {
    var answer = 0;
    const DP = Array.from({length: triangle.length}, (_, i) => Array.from({length: i + 1}, (_, j) => triangle[i][j]));
    
    for (let i = 0; i < triangle.length - 1; i++) {
        for (let j = 0; j < triangle[i].length; j++) {
            if (DP[i+1][j] < DP[i][j] + triangle[i+1][j]) {
                DP[i+1][j] = DP[i][j] + triangle[i+1][j];
            }
            if (DP[i+1][j+1] < DP[i][j] + triangle[i+1][j+1]) {
                DP[i+1][j+1] = DP[i][j] + triangle[i+1][j+1];
            }
        }
    }
    
    for (let i = 0; i < DP[DP.length - 1].length; i++) {
        if (DP[DP.length - 1][i] > answer) {
            answer = DP[DP.length - 1][i];
        }
    }
    
    console.log('test');
    
    return answer;
}