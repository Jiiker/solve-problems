#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> dup_check;
    int cur_people = 1;
    int cycle = 1;
    string prev_word = "";
    
    answer.push_back(0);
    answer.push_back(0);
    
    for (int i = 0; i < words.size(); i++) {
        if (i > 0 && 
            (prev_word[prev_word.length() - 1] != words[i][0] ||
            dup_check.find(words[i]) != dup_check.end())) {
            answer[0] = cur_people;
            answer[1] = cycle;
            break;
        }
        
        cur_people++;
        if (cur_people > n) {
            cur_people = 1;
            cycle++;
        }
        prev_word = words[i];
        dup_check.insert(words[i]);
    }

    return answer;
}