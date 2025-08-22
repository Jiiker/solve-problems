#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int table[105][105] = { 0 };
    
    for (int i = 0; i < results.size(); i++) {
        table[results[i][0]][results[i][1]] = 1;
        table[results[i][1]][results[i][0]] = -1;
    }
    
    for (int node = 1; node <= n; node++) {
        for (int i = 1; i <= n; i++) {
            if (table[i][node] == 0) continue;
            
            for (int j = 1; j <= n; j++) {
                if (table[i][node] == table[node][j]) {
                    table[i][j] = table[i][node];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int zero_cnt = 0;
        
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (table[i][j] == 0) zero_cnt++;
        }
        
        if (zero_cnt == 0) answer++;
    }
    
    return answer;
}