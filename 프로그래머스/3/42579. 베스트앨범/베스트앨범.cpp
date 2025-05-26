#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genres_plays;
    map<string, int> genres_choosed;
    vector<pair<pair<int, string>, int>> plays_ranking;
    vector<pair<int, string>> genres_ranking;
    
    for (int i = 0; i < genres.size(); i++) {
        plays_ranking.push_back({{plays[i], genres[i]}, i});
        genres_plays[genres[i]] += plays[i];
    }
    
    sort(plays_ranking.begin(), plays_ranking.end(), [](const auto& a, const auto& b) {
        if (a.first.first != b.first.first)
            return a.first.first > b.first.first;
        else
            return a.second < b.second;
    });
    
    for (const auto& [key, value] : genres_plays) {
        genres_ranking.push_back({value, key});
    }
    
    sort(genres_ranking.begin(), genres_ranking.end(), greater<>());
    
    for (int i = 0; i < genres_ranking.size(); i++) {
        string cur_genres = genres_ranking[i].second;
        genres_choosed[cur_genres] = 0;
        
        for (int j = 0; j < plays_ranking.size(); j++) {
            if (plays_ranking[j].first.second != cur_genres) continue;
            if (genres_choosed[cur_genres] == 2) continue;
            
            answer.push_back(plays_ranking[j].second);
            genres_choosed[cur_genres]++;
        }
    }
    
    return answer;
}