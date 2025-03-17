#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    int idx;
    
    bool operator<(const Node& other) const {
        return value < other.value;
    }
};

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();
    int arr[4] = { 0, 0, 0, 0 };
    Node prev_fst = { 0, 0 };
    int prev_snd = 0;
    
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            for (int j = 0; j < 4; j++) {
                if (j != prev_fst.idx) {
                    land[i][j] += prev_fst.value;
                } else {
                    land[i][j] += prev_snd;
                }
            }
        }
        
        priority_queue<Node> pq;
        
        for (int j = 0; j < 4; j++) {
            pq.push({land[i][j], j});
        }
        
        prev_fst = { pq.top().value, pq.top().idx }; pq.pop();
        prev_snd = pq.top().value;
    }
    
    answer = max(max(land[N-1][0], land[N-1][1]), max(land[N-1][2], land[N-1][3]));

    return answer;
}