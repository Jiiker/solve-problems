#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  int arr[100005] = { 0 };
  int check[100005] = { 0 };
  int right = 0, left = 0;
  long long cnt = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    arr[i] = num;
  }

  while (right < N) {
    if (check[arr[right]] == 0) {
      check[arr[right]] = 1;
      cnt += right - left + 1;
      right++;
    } else {
      check[arr[left]] = 0;
      left++;
    }
  }

  cout << cnt;

  return 0;
}