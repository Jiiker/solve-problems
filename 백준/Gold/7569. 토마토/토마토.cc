#include <bits/stdc++.h>

using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int M = 0, N = 0, H = 0;
  int box[105][105][105] = { 0 };
  int vis[105][105][105] = { 0 };
  queue<pair<int, pair<int, int>>> Q;
  int day = 0;
  int isAllRiped = 1;

  cin >> M >> N >> H;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        cin >> box[i][j][k];

        if (box[i][j][k] == 1) {
          Q.push({i, {j, k}});
          vis[i][j][k] = 1;
        }
      }
    }
  }

  while (!Q.empty()) {
    pair<int, pair<int, int>> cur = Q.front(); Q.pop();

    for (int dir = 0; dir < 6; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second.first + dy[dir];
      int nz = cur.second.second + dz[dir];

      if (nx < 0 || nx >= H || ny < 0 || ny >= N || nz < 0 || nz >= M) continue;
      if (vis[nx][ny][nz] != 0) continue;
      if (box[nx][ny][nz] == 1 || box[nx][ny][nz] == -1) continue;
      
      Q.push({nx, {ny, nz}});
      box[nx][ny][nz] = 1;
      vis[nx][ny][nz] = vis[cur.first][cur.second.first][cur.second.second] + 1;
      day = vis[nx][ny][nz] - 1;
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (box[i][j][k] == 0)
          isAllRiped = 0;
      }
    }
  }

  if (!isAllRiped) {
    cout << -1;
  } else {
    cout << day;
  }

  return 0;
}