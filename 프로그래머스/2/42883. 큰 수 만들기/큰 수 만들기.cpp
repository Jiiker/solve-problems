#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int del_cnt = 0;
    vector<char> stack;
    
    for (int i = 0; i < number.length(); i++) {
        char cur = number[i];
        
        while (!stack.empty()) {
            if (del_cnt == k) break;
            
            if (stack.back() < cur) {
                stack.pop_back();
                del_cnt++;
            } else {
                break;
            }
        }
        
        stack.push_back(cur);
    }
    
    int len;
    len = min(stack.size(), number.length() - k);
    
    for (int i = 0; i < len; i++) {
        answer += stack[i];
    }
    
    return answer;
}