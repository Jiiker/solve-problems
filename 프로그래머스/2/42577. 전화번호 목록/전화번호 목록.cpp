#include <bits/stdc++.h>

using namespace std;

bool phone_cmp_fn(string num1, string num2) {
    if (num1.length() >= num2.length()) {
        for (int i = 0; i < num2.length(); i++) {
            if (num1[i] != num2[i])
                return false;
        }
    } else {
        for (int i = 0; i < num1.length(); i++) {
            if (num1[i] != num2[i])
                return false;
        }
    }
    
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++) {  
        if (phone_cmp_fn(phone_book[i], phone_book[i+1]))
            answer = false;
    }
    
    return answer;
}

