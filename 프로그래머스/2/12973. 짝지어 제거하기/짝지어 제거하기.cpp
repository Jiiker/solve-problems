#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string result = "";
    vector<char> prev;
    
    for (int i = 0; i < s.length(); i++) {
        if (prev.size() != 0 && prev[prev.size() - 1] == s[i]) {
            prev.pop_back();
            continue;
        }
            
        prev.push_back(s[i]);
    }
    
    for (int i = 0; i < prev.size(); i++) {
        result += prev[i];
    }
    
    if (result.length() != 0) answer = 0;
    else answer = 1;

    return answer;
}