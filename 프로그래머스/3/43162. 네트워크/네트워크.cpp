#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int vis[200] = { 0 };
    queue<int> Q;
    
    for (int i = 0; i < n; i++) {
        if (vis[i])
            continue;
        
        Q.push(i);
        vis[i] = 1;
        
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            
            for (int j = 0; j < computers[i].size(); j++) {
                if (!computers[cur][j] || cur == j)
                    continue;
                if (vis[j])
                    continue;
                
                Q.push(j);
                vis[j] = 1;
            }
        }
        answer++;
    }
    
    return answer;
}