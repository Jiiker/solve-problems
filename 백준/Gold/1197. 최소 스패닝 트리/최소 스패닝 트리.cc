#include <bits/stdc++.h>

using namespace std;

int main() {
  int V, E;
  vector<vector<pair<int,int>>> path;
  int prim[10005];
  int vis[10005] = { 0 };
  long long result = 0;

  fill(prim, prim + 10005, INT_MAX);

  cin >> V >> E;

  for (int i = 0; i <= V; i++) {
    vector<pair<int, int>> temp;
    path.push_back(temp);
  }

  for (int i = 0; i < E; i++) {
    int start, end, weight;

    cin >> start >> end >> weight;

    path[start].push_back({end, weight});
    path[end].push_back({start, weight});
  }


  prim[1] = 0;
  for (int i = 0; i < V; i++) {
    int minWeight = INT_MAX;
    int minIndex = -1;

    for (int j = 1; j <= V; j++) {
      if (!vis[j] && prim[j] <= minWeight) {
        minWeight = prim[j];
        minIndex = j;
      }
    }

    if (minIndex == -1) {
      // 다 연결 못 한 경우
      break;
    }

    vis[minIndex] = 1;

    for (int j = 0; j < path[minIndex].size(); j++) {
      int next = path[minIndex][j].first;
      int weight = path[minIndex][j].second;
      
      if (vis[next]) continue;
      if (weight >= prim[next]) continue;

      prim[next] = weight;
    }
  }

  for (int i = 1; i <= V; i++) {
    result += prim[i];
  }

  cout << result;

  return 0;
}