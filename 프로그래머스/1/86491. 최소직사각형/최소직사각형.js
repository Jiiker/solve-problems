function solution(sizes) {
    var answer = 0;
    let max_width = 0;
    let max_height = 0;
    
    for (let i = 0; i < sizes.length; i++) {
        let w;
        let h;
        
        if (sizes[i][0] > sizes[i][1]) {
            w = sizes[i][0];
            h = sizes[i][1];
        } else {
            h = sizes[i][0];
            w = sizes[i][1];
        }
        
        if (w > max_width) max_width = w;
        if (h > max_height) max_height = h;
    }
    
    answer = max_width * max_height;
    
    return answer;
}