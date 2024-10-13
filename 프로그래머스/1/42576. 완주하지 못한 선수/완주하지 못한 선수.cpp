#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> retire;
    
    for (int i = 0; i < participant.size(); i++) {
        if (retire.count(participant[i]) > 0) {
            retire[participant[i]]++;
            continue;
        }
        retire.insert({participant[i], 1});
    }
    
    for (int i = 0; i < completion.size(); i++) {
        if (retire[completion[i]] > 1) {
            retire[completion[i]]--;
            continue;
        }
        retire.erase(completion[i]);
    }
    
    for (auto iter = retire.begin(); iter != retire.end(); ++iter) {
        answer = iter -> first;
    }
    
    return answer;
}