#include <bits/stdc++.h>

using namespace std;

// R vs T
// C vs F
// J vs M
// A vs N

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    char types[8] = { 'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N' };
    map<char, int> M;
    
    for (int i = 0; i < 8; i++) {
        M[types[i]] = 0;
    }
    
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] > 4) {
            M[survey[i][1]] += choices[i] - 4;
        } else {
            M[survey[i][0]] += 4 - choices[i];
        }
    }
    
    if (M['R'] >= M['T']) {
        answer += 'R';
    } else {
        answer += 'T';
    }
    if (M['C'] >= M['F']) {
        answer += 'C';
    } else {
        answer += 'F';
    }
    if (M['J'] >= M['M']) {
        answer += 'J';
    } else {
        answer += 'M';
    }
    if (M['A'] >= M['N']) {
        answer += 'A';
    } else {
        answer += 'N';
    }
    
    return answer;
}