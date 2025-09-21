#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void draw_width_line(int (&coordinate)[105][105], pair<int, int> p1, pair<int, int> p2) {
    for (int i = p1.first; i <= p2.first; i++) {
      coordinate[i][p1.second] = 1;  
    }
}

void draw_height_line(int (&coordinate)[105][105], pair<int, int> p1, pair<int, int> p2) {
    for (int i = p1.second; i <= p2.second; i++) {
      coordinate[p1.first][i] = 1;  
    }
}

void draw_line(int (&coordinate)[105][105], vector<vector<int>> rectangle) {
    for (int i = 0; i < rectangle.size(); i++) {
        pair<int, int> left_bot = {2*rectangle[i][0], 2*rectangle[i][1]};
        pair<int, int> left_top = {2*rectangle[i][0], 2*rectangle[i][3]};
        pair<int, int> right_bot = {2*rectangle[i][2], 2*rectangle[i][1]};
        pair<int, int> right_top = {2*rectangle[i][2], 2*rectangle[i][3]};
        
        draw_height_line(coordinate, left_bot, left_top);
        draw_height_line(coordinate, right_bot, right_top);
        draw_width_line(coordinate, left_top, right_top);
        draw_width_line(coordinate, left_bot, right_bot);
    }
}

void draw_inner_zero(int (&coordinate)[105][105], vector<vector<int>> rectangle) {
    for (int i = 0; i < rectangle.size(); i++) {
        pair<int, int> left_bot = {2*rectangle[i][0], 2*rectangle[i][1]};
        pair<int, int> right_top = {2*rectangle[i][2], 2*rectangle[i][3]};
        
        for (int i = left_bot.first + 1; i < right_top.first; i++) {
            for (int j = left_bot.second + 1; j < right_top.second; j++) {
                coordinate[i][j] = 0;
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int coordinate[105][105] = { 0 };
    int vis[105][105] = { 0 };
    queue<pair<int, int>> Q;
    int resized_ix = 2*itemX;
    int resized_iy = 2*itemY;
    
    draw_line(coordinate, rectangle);
    draw_inner_zero(coordinate, rectangle);
    
    Q.push({2*characterX, 2*characterY});
    vis[2*characterX][2*characterY] = 1;
    
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        
        if (cur.first == resized_ix && cur.second == resized_iy) break;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 0 || nx > 104 || ny < 0 || ny > 104) continue;
            if (vis[nx][ny] || !coordinate[nx][ny]) continue;
            
            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
        }
    }
    
    answer = vis[resized_ix][resized_iy] / 2;
    
    return answer;
}