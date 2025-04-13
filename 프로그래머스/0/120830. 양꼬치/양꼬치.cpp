#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    k = k - (n / 10);
    
    answer = (2000 * k) + (12000 * n);
    
    return answer;
}