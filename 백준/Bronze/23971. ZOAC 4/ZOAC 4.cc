#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W, N, M;
  int row, col;
  cin >> H >> W >> N >> M;

  row = W / (M + 1);
  if (W % (M + 1) != 0)
    row++;
  col = H / (N + 1);
  if (H % (N + 1))
    col++;

  cout << row * col;

  return 0;
}