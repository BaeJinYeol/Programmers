// DFS, 여행경로, 레벨 3
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> answer;

bool dfs(string curr, vector<string> &path, unordered_map<string, vector<string>> &airport, unordered_map<string, vector<bool>> &used, int ticket) {
    if (ticket == 0) {
        answer = path;
        return true;
    }

    for (int i = 0; i < airport[curr].size(); i++) {
        if (!used[curr][i]) {
            used[curr][i] = true;
            path.push_back(airport[curr][i]);

            if (dfs(airport[curr][i], path, airport, used, ticket - 1)) return true;

            used[curr][i] = false;
            path.pop_back();
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<string>> airport;
    unordered_map<string, vector<bool>> used;

    for (auto ti : tickets) {
        airport[ti[0]].push_back(ti[1]);
        used[ti[0]].push_back(false);
    }

    for (auto &pair : airport) {
        sort(pair.second.begin(), pair.second.end());
    }

    vector<string> path = {"ICN"};
    dfs("ICN", path, airport, used, tickets.size());

    return answer;
}