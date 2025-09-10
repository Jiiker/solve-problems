#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int n = queue1.size();
    long long q1_sum = 0, q2_sum = 0;
    long long dest_sum = 0;
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        q1_sum += queue1[i];
        q2_sum += queue2[i];
    }
    
    if ((q1_sum + q2_sum) % 2 == 1) return answer;
    dest_sum = (q1_sum + q2_sum) / 2;
    
    while (q1_sum != dest_sum && cnt < n * 3) {
        if (q1_sum < dest_sum) {
            queue1.push_back(queue2[0]);
            q1_sum += queue2[0];
            queue2.erase(queue2.begin());
        } else {
            q1_sum -= queue1[0];
            queue2.push_back(queue1[0]);
            queue1.erase(queue1.begin());
        }
        cnt++;
    }
    
    if (q1_sum == dest_sum)  {
        answer = cnt;
    }
    
    return answer;
}