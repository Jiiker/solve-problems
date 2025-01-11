#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    int arr[105] = { 0 };
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int fst, snd;
        stack<int> S;
        
        cin >> fst >> snd;
        
        for (int i = fst; i <= snd; i++) {
            S.push(arr[i]);
        }
        for (int i = fst; i <= snd; i++) {
            int cur = S.top(); S.pop();
            arr[i] = cur;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << ' ';
    }
    
    return 0;
}