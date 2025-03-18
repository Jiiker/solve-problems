#include <bits/stdc++.h>

using namespace std;

struct Node {
    int sum;
    int depth;
};

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int N = numbers.size();
    queue<Node> Q;
    
    Q.push({0, 0});
    
    while (!Q.empty()) {
        Node cur = Q.front(); Q.pop();
        
        if (cur.depth == N) {
            if (cur.sum == target) {
                cout << cur.sum;
                answer++;
            }
            
            continue;
        }
        
        for (int i = 0; i < 2; i++) {
            int next_sum = cur.sum;
            if (i == 0) {
                next_sum += numbers[cur.depth];
            } else {
                next_sum -= numbers[cur.depth];
            }
            
            Q.push({next_sum, cur.depth + 1});
        }
    }
    
    
    return answer;
}