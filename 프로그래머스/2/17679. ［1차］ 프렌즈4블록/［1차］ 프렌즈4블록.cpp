#include <bits/stdc++.h>

using namespace std;
int dx[3] = { 1, 1, 0 };
int dy[3] = { 0, 1, 1 };

void move_block(vector<string> &board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (board[i][j] != '0') continue;

            int ni = i;
            
            while (ni > 0) {
                ni--;
                
                if (board[ni][j] != '0') break;
            }

            if (board[ni][j] != '0') {
                board[i][j] = board[ni][j];
                board[ni][j] = '0';
            }
        }
    }
}

int delete_block(vector<string> &board) {
    set<pair<int, int>> S;
    int deletedNum = 0;
    
    for (int i = 0; i < board.size() - 1; i++) {
        for (int j = 0; j < board[i].size() - 1; j++) {
            bool isFourBlock = true;
            char friends = board[i][j];
            
            if (friends == '0') continue;
            
            for (int k = 0; k < 3; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if (board[nx][ny] != friends) {
                    isFourBlock = false;
                    break;
                }
            }
            
            if (isFourBlock) {
                S.insert({i, j});
                S.insert({i+1, j});
                S.insert({i+1, j+1});
                S.insert({i, j+1});
            }
        }
    }
    
    while(!S.empty()) {
        pair<int, int> front = *S.begin();
        S.erase(S.begin());
        
        board[front.first][front.second] = '0';
        
        deletedNum++;
    }
    
    return deletedNum;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (1) {
        int num = delete_block(board);
        
        if (num == 0) {
            break;
        } else {
            answer += num;
        }
        
        move_block(board);
    }
    
    return answer;
}