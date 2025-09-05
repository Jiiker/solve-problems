#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void measure_dist(int N, int (&space)[20][20], int (&dist)[20][20], pair<int, int> cur_shark_loc, int shark_size) {
  queue<pair<int, int>> Q;

  Q.push(cur_shark_loc);
  dist[cur_shark_loc.first][cur_shark_loc.second] = 1;

  while(!Q.empty()) {
    pair<int, int> cur = Q.front(); Q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
      if (dist[nx][ny] != 0) continue;
      if (space[nx][ny] > shark_size) continue;

      Q.push({nx, ny});
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
    }
  }

  return;
}

pair<int, int> search_close_fish(int N, int (&space)[20][20], int (&dist)[20][20], int shark_size) {
  int fish_x = -1, fish_y = -1, min_dist = INT_MAX;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (space[i][j] == 0 || space[i][j] == 9) continue;
      if (space[i][j] >= shark_size) continue;
      if (dist[i][j] == 0) continue;
      
      if (dist[i][j] < min_dist) {
        min_dist = dist[i][j];
        fish_x = i;
        fish_y = j;
      }
    }
  }

  return {fish_x, fish_y};
}

int main() {
  int N;
  int space[20][20] = { 0 };
  int time = 0;
  pair<int, int> cur_shark_loc;
  pair<int, int> shark_size = {2, 0};

  cin >> N;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int num;
      cin >> num;
      space[i][j] = num;
      if (num == 9) {
        cur_shark_loc = {i, j};
      }
    }
  }

  while (1) {
    int dist[20][20] = { 0 };
    pair<int, int> next_fish;

    measure_dist(N, space, dist, cur_shark_loc, shark_size.first);
    next_fish = search_close_fish(N, space, dist, shark_size.first);

    if (next_fish.first == -1) {
      break;
    }
    
    space[cur_shark_loc.first][cur_shark_loc.second] = 0;
    space[next_fish.first][next_fish.second] = 9;
    cur_shark_loc = next_fish;
    shark_size.second++;
    if (shark_size.first == shark_size.second) {
      shark_size.first++;
      shark_size.second = 0;
    }

    time += dist[next_fish.first][next_fish.second] - 1;
  }

  cout << time;

  return 0;
}