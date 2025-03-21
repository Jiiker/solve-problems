#include <bits/stdc++.h>

using namespace std;

vector<int> num_to_bit (long long num) {
    vector<int> bit;
    
    while (num > 0) {
        bit.push_back(num % 2);
        num = num / 2;
    }
    
    return bit;
}

long long bit_to_num (vector<int> bit) {
    long long power = 1;
    long long num = 0;
    
    while (!bit.empty()) {
        int temp = bit.front(); bit.erase(bit.begin());
        
        num += temp * power;
        power = power * 2;
    }
    
    return num;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i = 0; i < numbers.size(); i++) {
        vector<int> bit;
        bit = num_to_bit(numbers[i]);
        bool isAllOne = true;
        
        for (int j = 0; j < bit.size(); j++) {
            if (bit[j] == 0) {
                isAllOne = false;
                break;
            }
        }
        
        if (isAllOne) {
            bit.push_back(1);
            bit[bit.size() - 2] = 0;
        } else if (bit[0] == 0) {
            bit[0] = 1;
        } else {
            for (int j = 0; j < bit.size(); j++) {
                if (bit[j] == 0) {
                    bit[j] = 1;
                    bit[j-1] = 0;
                    break;
                }
            }
        }
        
        answer.push_back(bit_to_num(bit));
    }
    
    return answer;
}


// 111 -> 1011
// 110 -> 111
// 101 -> 110
// 1100 -> 1101
// 1001 -> 1010
// 1010 -> 1011