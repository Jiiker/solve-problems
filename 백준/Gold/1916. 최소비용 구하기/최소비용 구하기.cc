#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  vector<vector<pair<int, int>>> path; // path[출발지] = [{ 도착지, 가중치 }, { 도착지, 가중치 }, ... ]
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // { 가중치, 도착지 }
  int cost[1005];
  int start, end;

  fill(cost, cost + 1005, INT_MAX);

  cin >> N >> M;

  for (int i = 0; i <= N; i++) {
    vector<pair<int, int>> temp;
    path.push_back(temp);
  }

  for (int i = 0; i < M; i++) {
    int s, e, w;

    cin >> s >> e >> w;

    path[s].push_back({e, w});
  }

  cin >> start >> end;

  cost[start] = 0;
  pq.push({0, start});

  while(!pq.empty()) {
    pair<int, int> cur = pq.top(); pq.pop();
    int cur_node = cur.second;
    int cur_cost = cur.first;

    if (cost[cur_node] != cur_cost) continue;

    for (int dir = 0; dir < path[cur_node].size(); dir++) {
      int next = path[cur_node][dir].first;
      int weight = path[cur_node][dir].second;

      if (cur_cost + weight >= cost[next]) continue;
      
      pq.push({cur_cost + weight, next});
      cost[next] = cur_cost + weight;
    }
  }

  cout << cost[end];

  return 0;
}