#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> M;
    map<string, int> mailed;
    set<string> S;
    
    for (int i = 0; i < id_list.size(); i++) {
        M[id_list[i]] = vector<string> {};
        mailed.insert({id_list[i], 0});
    }
    
    for (int i = 0; i < report.size(); i++) {
        S.insert(report[i]);
    }
    
    for (int i = 0; i < report.size(); i++) {
        if (S.find(report[i]) == S.end()) {
            continue;
        } else {
            S.erase(report[i]);
        }
        
        string from = "";
        string to = "";
        int flag = 1;
        
        for (int j = 0; j < report[i].length(); j++) {
            if (report[i][j] == ' ') {
                flag = 0;
                continue;
            }
            
            if (flag) {
                from += report[i][j];
            } else {
                to += report[i][j];
            }
        }
        
        M[to].push_back(from);
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        if (M[id_list[i]].size() >= k) {
            for (int j = 0; j < M[id_list[i]].size(); j++) {
                mailed[M[id_list[i]][j]]++;
            }
        }
    }
    
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(mailed[id_list[i]]);
    } 
    
    return answer;
}