// DFS, 피로도, 레벨 2
#include <vector>
using namespace std;

int maxCount;

void dfs(int k, vector<vector<int>> &dungeons, vector<bool> &visited, int count) {
    maxCount = max(maxCount, count);

    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(k-dungeons[i][1], dungeons, visited, count + 1);
            visited[i] = false; // 백트래킹
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);

    dfs(k, dungeons, visited, 0);

    return maxCount;
}