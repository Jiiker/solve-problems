#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int last_cnt = 0;
    vector<int> V[20005];
    int vis[20005] = { 0 };
    queue<int> Q;
    
    for (int i = 0; i < edge.size(); i++) {
        V[edge[i][0]].push_back(edge[i][1]);
        V[edge[i][1]].push_back(edge[i][0]);
    }
     
    Q.push(1);
    vis[1] = 1;
        
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        
        for (int i = 0; i < V[cur].size(); i++) {
            if (vis[V[cur][i]])
                continue;
            
            vis[V[cur][i]] = vis[cur] + 1;
            Q.push(V[cur][i]);
            last_cnt = vis[V[cur][i]];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (vis[i] == last_cnt)
            answer++;
    }
    
    return answer;
}