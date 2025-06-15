#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> left;
    map<int, int> right;
    
    for (int i = 0; i < topping.size(); i++) {
        if (right.find(topping[i]) == right.end()) {
            right.insert({topping[i], 1});
        } else {
            right[topping[i]]++;
        }
    }
    
    for (int i = 0; i < topping.size(); i++) {
        int cur = topping[i];
        
        right[cur]--;
        
        if (left.find(cur) == left.end()) {
            left.insert({cur, 1});
        } else {
            left[cur]++;
        }
        
        if (right[cur] == 0) {
            right.erase(cur);
        }
        
        if (right.size() == left.size()) answer++;
    }
    
    return answer;
}