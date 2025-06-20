// 해시, 베스트앨범, 레벨 3
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> genres_sum;
    unordered_map<string, vector<pair<int, int>>> mp3;

    for (int i = 0; i < plays.size(); i++) {
        genres_sum[genres[i]] += plays[i];
        mp3[genres[i]].push_back({plays[i], i});
    }

    vector<pair<string,int>> sorted_genres(genres_sum.begin(), genres_sum.end());
    sort(sorted_genres.begin(), sorted_genres.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;  // 총 재생 수 기준 내림차순
         });

    // 각 장르별로 인기 순 정렬 후 2곡까지 선택
    for (const auto& genre : sorted_genres) {
        string g = genre.first;
        auto& songs = mp3[g];
        sort(songs.begin(), songs.end(), comp);  // 재생 수 > 고유 번호 순

        answer.push_back(songs[0].second);
        if (songs.size() > 1)
            answer.push_back(songs[1].second);
    }

    return answer;
}