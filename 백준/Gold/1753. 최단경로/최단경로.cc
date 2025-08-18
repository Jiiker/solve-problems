#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<vector<pair<int, int>>> path;
  int V, E, S;
  priority_queue<pair<int, int>, 
  vector<pair<int, int>>, 
  greater<pair<int, int>>
  > pq;
  int length[20005];
  
  fill(length, length + 20005, INT_MAX);

  cin >> V >> E >> S;

  for (int i = 0; i <= V; i++) {
    vector<pair<int, int>> temp;
    path.push_back(temp);
  }

  for (int i = 0; i < E; i++) {
    int start, end, value;

    cin >> start >> end >> value;
    path[start].push_back({end, value});
  }

  pq.push({0, S});
  length[S] = 0;

  while (!pq.empty()) {
    pair<int, int> cur = pq.top(); pq.pop();
    int loc = cur.second;
    int len = cur.first;

    if (len != length[loc]) continue;

    for (int i = 0; i < path[loc].size(); i++) {
      int next = path[loc][i].first;
      int weight = path[loc][i].second;

      if (weight + len >= length[next]) continue;

      pq.push({weight + len, next});
      length[next] = weight + len;
    }
  }

  for (int i = 1; i <= V; i++) {
    if (length[i] != INT_MAX) {
      cout << length[i];
    } else {
      cout << "INF";
    }
    cout << '\n';
  }

  return 0;
}