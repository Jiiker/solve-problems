#include <bits/stdc++.h>

using namespace std;

char arr[6][3] = {
        { '+', '-', '*' },
        { '+', '*', '-' },
        { '-', '+', '*' },
        { '-', '*', '+' },
        { '*', '+', '-' },
        { '*', '-', '+' }
    };

long long calculate_expression(list<pair<string, char>> L, const char* priority) {
    for (int i = 0; i < 3; i++) {
        char priority_op = priority[i];

        for (auto it = L.begin(); it != L.end(); ) {
            char op = it->second;

            if (op != priority_op) { 
                ++it; 
                continue; 
            }

            auto next_it = next(it);
            if (next_it == L.end()) break;

            long long left  = stoll(it->first);
            long long right = stoll(next_it->first);
            long long result = 0;

            if (op == '+') result = left + right;
            else if (op == '-') result = left - right;
            else if (op == '*') result = left * right;

            it->first  = to_string(result);
            it->second = next_it->second;

            L.erase(next_it);
        }
    }

    return stoll(L.front().first);
}

long long solution(string expression) {
    long long answer = 0;
    list<pair<string, char>> L;
    string temp = "";
    
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            temp += expression[i];
        } else {
            L.push_back({temp, expression[i]});
            temp = "";
        }
        
        if (i == expression.length() - 1) {
            L.push_back({temp, '\0'});
        }
    }
    
    for (int i = 0; i < 6; i++) {
        char* priority = arr[i];
        long long result = calculate_expression(L, priority);
        
        if (answer < llabs(result)) answer = llabs(result);   
    }
    
    return answer;
}