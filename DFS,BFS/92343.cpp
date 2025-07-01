// dfs, 양과 늑대
#include <vector>
#include <algorithm>
using namespace std;

int max_sheep = 0;

void dfs(int sheep, int wolf, vector<int> &info, vector<vector<int>> &tree, vector<int> available) {
    max_sheep = max(max_sheep, sheep);

    for (int i = 0; i < available.size(); i++) {
        int next = available[i];

        // 방문 시 양/늑대 수 계산
        int nsheep = sheep + (info[next] == 0 ? 1 : 0);
        int nwolf = wolf + (info[next] == 1 ? 1 : 0);

        // 늑대 수가 같거나 더 많아지면 해당 경로는 탐색하지 않음
        if (nsheep <= nwolf) continue;

        // 다음 탐색 가능한 노드 목록 업데이트
        vector<int> next_available = available;
        next_available.erase(next_available.begin() + i);
        for (int child : tree[next])
            next_available.push_back(child);

        // DFS 탐색
        dfs(nsheep, nwolf, info, tree, next_available);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> tree(info.size());
    for (auto &e : edges)
        tree[e[0]].push_back(e[1]);

    dfs(0, 0, info, tree, {0});

    return max_sheep;
}
