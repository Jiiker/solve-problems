#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int order_index = 0;
    queue<int> main;
    stack<int> support;
    
    for (int i = 1; i <= order.size(); i++) {
        main.push(i);
    }
    
    while (!main.empty() || !support.empty()) {
        int cur_main;
        int cur_support;
        if (main.size()) {
            cur_main = main.front();
        }
        if (support.size()) {
            cur_support = support.top();
        }
        
        if (main.empty() && order[order_index] != cur_support) {
            break;
        }
        
        if (order[order_index] == cur_main) {
            answer++;
            main.pop();
            order_index++;
            if (order_index == order.size()) break;
            continue;
        }
            
        if (order[order_index] == cur_support) {
            answer++;
            support.pop();
            order_index++;
            if (order_index == order.size()) break;
            continue;
        }
        
        support.push(cur_main);
        main.pop();
    }
    
    return answer;
}