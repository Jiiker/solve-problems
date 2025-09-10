#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int n = queue1.size();
    long long dest_sum = 0;
    long long sum = 0;
    int cnt = 0;
    vector<int> circled_Q;
    int l = 0, r = n - 1;
    
    for (int i = 0; i < n; i++) {
        dest_sum += queue1[i];
        dest_sum += queue2[i];
    }
    
    if (dest_sum % 2 == 1) return answer;
    dest_sum /= 2;
    
    for (int i = 0; i < n; i++) {
        circled_Q.push_back(queue1[i]);
        sum += queue1[i];
    }
    for (int i = 0; i < n; i++) {
        circled_Q.push_back(queue2[i]);
    }
    
    while (sum != dest_sum && cnt < 3 * n) {
        if (sum < dest_sum) {
            r++;
            cnt++;
            if (r == 2 * n) r = 0;
            sum += circled_Q[r];
        } else {
            sum -= circled_Q[l];
            l++;
            cnt++;
            if (l == 2 * n) l = 0;
        }
    }
    
    if (sum == dest_sum) answer = cnt;
    
    return answer;
}