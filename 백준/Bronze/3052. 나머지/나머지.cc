#include <bits/stdc++.h>

using namespace std;

int main() {
    int remainder[42] = { 0 };
    int count = 0;
    
    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        
        remainder[num % 42]++;
    }
    
    for (int i = 0; i < 42; i++) {
        if (remainder[i])
            count++;
    }
    
    cout << count;
    
    return 0;
}