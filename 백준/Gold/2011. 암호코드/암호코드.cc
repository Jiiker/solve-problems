#include <bits/stdc++.h>

using namespace std;

int main() {
    int prev = 0;
    vector<pair<int, int>> V;
    string str = "";
    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        int cur = str[i] - '0';
        
        if (i == 0) {
            if (cur == 0) {
                cout << 0;
                return 0; 
            }
            V.push_back({1, 0});
            prev = cur;
            continue;
        }
        
        int num = prev * 10 + cur;
        
        if (prev == 0) {
            if (cur == 0) {
                cout << 0;
                return 0; 
            }

            int together = V[i - 1].second;
            
            V.push_back({together, 0});
        } else if (num > 26) {
            if (cur == 0) {
                cout << 0;
                return 0; 
            }
            int alone = V[i - 1].first;
            int together = V[i - 1].second;
            
            V.push_back({alone + together % 1000000, 0});
        } else if (num <= 26 && num >= 11 && num != 20) {
            int alone = V[i - 1].first;
            int together = V[i - 1].second;
            
            V.push_back({alone + together % 1000000, alone});
        } else if (num == 10 || num == 20) {
            int alone = V[i - 1].first;
            int together = V[i - 1].second;
            
            V.push_back({0, alone});
        }
        
        prev = cur;
    }
    
    cout << (V[str.length() - 1].first + V[str.length() - 1].second) % 1000000;
    
    return 0;
}