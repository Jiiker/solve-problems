#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int total = tangerine.size();
    map<int, int> num_of_size; // 사이즈(key), 개수(value) 순서
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> size_rank; // {개수, 사이즈} 형식으로 저장
    
    for (int i = 0; i < total; i++) {
        num_of_size[tangerine[i]]++;
    }
    
    for (const auto& [size, num]: num_of_size) {
        size_rank.push({num, size});
    }
    
    while (k <= total) {
        pair<int, int> cur = size_rank.top();
        size_rank.pop();
        
        total -= cur.first;
    }
    
    answer = size_rank.size() + 1;
    
    return answer;
}