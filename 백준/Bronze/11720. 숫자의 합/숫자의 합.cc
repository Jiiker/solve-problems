#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int sum = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char c;
        
        cin >> c;
        
        sum += c - '0';
    }
    
    cout << sum;
    
    return 0;
}