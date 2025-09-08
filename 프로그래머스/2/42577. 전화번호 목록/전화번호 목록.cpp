#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> prefixes;
    
    for (int i = 0; i < phone_book.size(); i++) {
        string prefix = "";
        
        for (int j = 0; j < phone_book[i].length() - 1; j++) {
            prefix += phone_book[i][j];
            prefixes.insert(prefix);
        }
    }
    
    for (int i = 0; i < phone_book.size(); i++) {
        if (prefixes.count(phone_book[i])) {
            answer = false;
        }
    }
    
    return answer;
}