#include <bits/stdc++.h>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int board[105][105] = { 0 };
    set<pair<int, int>> S;
    
    for (int i = 0; i < puddles.size(); i++) {
        S.insert({puddles[i][1], puddles[i][0]});
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                board[i][j] = 1;
                continue;
            }
            
            if (S.count({i, j})) {
                board[i][j] = 0;
                continue;
            }
            
            board[i][j] = (board[i-1][j] + board[i][j-1]) % 1000000007;
        }
    }
    
    cout << board[n][m];
    
    return board[n][m];
}