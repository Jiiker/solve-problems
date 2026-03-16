function solution(n, lost, reserve) {
    var answer = 0;
    let lost_man = new Set();
    let reserve_man = new Set();
    
    for (let i = 0; i < reserve.length; i++) {
        reserve_man.add(reserve[i]);
    }
    
    for (let i = 0; i < lost.length; i++) {
        if (reserve_man.has(lost[i])) reserve_man.delete(lost[i]);
        else lost_man.add(lost[i]);
    }
    
    for (let num = 1; num <= n; num++) {
        if (lost_man.has(num)) continue;
        if (!reserve_man.has(num)) continue;
        
        if (lost_man.has(num - 1)) {
            lost_man.delete(num - 1);
            reserve_man.delete(num);
        }  else if (lost_man.has(num + 1)) {
            lost_man.delete(num + 1);
            reserve_man.delete(num);
        } 
    }
    
    answer = n - lost_man.size;
    
    return answer;
}