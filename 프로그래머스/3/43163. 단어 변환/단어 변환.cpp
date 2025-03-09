#include <bits/stdc++.h>

using namespace std;

int str_dif(string str, string dest) {
    int count = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != dest[i]) count++;
    }
    
    return count;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int vis[50] = { 0 };
    queue<pair<string, int>> Q;
    
    Q.push({begin, 0});
    
    while(!Q.empty()) {
        pair<string, int> cur = Q.front(); Q.pop();
        
        if (cur.first == target) {
            answer = cur.second;
            break;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (str_dif(cur.first, words[i]) != 1) continue;
            if (vis[i] == 1) continue;
            
            Q.push({words[i], cur.second + 1});
            vis[i] = 1;
        }
    }
    
    return answer;
}