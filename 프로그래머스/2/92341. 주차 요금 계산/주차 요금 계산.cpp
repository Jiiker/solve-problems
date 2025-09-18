#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, char sep) {
    vector<string> result;
    int start_idx = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == sep) {
            result.push_back(str.substr(start_idx, i - start_idx));
            start_idx = i + 1;
        } else if (i == str.length() - 1) {
            result.push_back(str.substr(start_idx));
        }
    }
    
    return result;
}

int time_dif_min (string t1, string t2) {
    int t2_hr = stoi(t2.substr(0, 2));
    int t2_min = stoi(t2.substr(3, 2));
    int t1_hr = stoi(t1.substr(0, 2));
    int t1_min = stoi(t1.substr(3, 2));
    
    return ((t2_hr * 60) + t2_min) - ((t1_hr * 60) + t1_min);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> result;
    map<string, string> pk;
    
    for (int i = 0; i < records.size(); i++) {
        bool isExist = false;
        int prevIndex = -1;
        vector<string> record = split(records[i], ' ');
        
        if (record[2] == "IN") {
            pk[record[1]] = record[0];
        } else {
            string in_time = pk[record[1]];
            string out_time = record[0];
            int stale_time = time_dif_min(in_time, out_time);
            
            for (int i = 0; i < result.size(); i++) {
                if (result[i].first == record[1]) {
                    isExist = true;
                    prevIndex = i;
                }
            }
            
            if (isExist) {
                result[prevIndex].second += stale_time;
            } else {
                result.push_back({record[1], stale_time});
            }
            
            pk.erase(record[1]);
        }
    }
    
    for (auto &p : pk) {
        bool isExist = false;
        int prevIndex = -1;
        string in_time = p.second;
        string out_time = "23:59";
        int stale_time = time_dif_min(in_time, out_time);
        
        for (int i = 0; i < result.size(); i++) {
            if (result[i].first == p.first) {
                isExist = true;
                prevIndex = i;
            }
        }
        
        if (isExist) {
            result[prevIndex].second += stale_time;
        } else {
            result.push_back({p.first, stale_time});
        }
    }
    
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << " || " << result[i].second << '\n';
    }
    
    for (int i = 0; i < result.size(); i++) {
        float extra_time = 0;
        int fee = 0;
        
        if (result[i].second > fees[0]) {
            extra_time = result[i].second - fees[0];
        }
        
        fee = fees[1] + (ceil(extra_time / fees[2]) * fees[3]);
        answer.push_back(fee);
    }
    
    return answer;
}