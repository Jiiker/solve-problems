#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<string> key;
    map<string, int> count;
    
    for (int i = 0; i < clothes.size(); i++)
    {
        count[clothes[i][1]]++;
        
        if (count[clothes[i][1]] == 1)
            key.push_back(clothes[i][1]);
    }
    
    for (int i = 0; i < key.size(); i++)
    {
        answer = answer * (count[key[i]] + 1);
    }
    
    answer = answer - 1;
    
    return answer;
}