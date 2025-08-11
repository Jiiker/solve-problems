from collections import deque

def solution(n, edge):
    answer = 0
    vis = [0] * 20001
    line = [[] for _ in range(20001)]
    max_len = 0
    
    for value in edge:
        line[value[0]].append(value[1])
        line[value[1]].append(value[0])
    
    Q = deque()
    Q.append(1)
    vis[1] = 1
    
    while Q:
        cur = Q.popleft()
        
        for value in line[cur]:
            np = value
            
            if (vis[np] > 0):
                continue
            
            Q.append(np)
            vis[np] = vis[cur] + 1
            if (vis[np] > max_len):
                max_len = vis[np]
                
    for value in vis:
        if (value == max_len):
            answer += 1
            
    return answer