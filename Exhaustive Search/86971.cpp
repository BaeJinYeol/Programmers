// dfs, 전력망 둘로 나누기, 레벨 2
#include <vector>
using namespace std;

int dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[node] = true;
    int count = 1;

    for (int next : graph[node])
        if (!visited[next])
            count += dfs(next, graph, visited);

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i= 0; i < wires.size(); i++) {
        // i번 간선을 제외한 임시 그래프
        vector<vector<int>> graph(n + 1);

        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue; // i번째 간선 제거
            int a = wires[j][0], b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 2. DFS로 한 쪽 네트워크 크기 구하기
        vector<bool> visited(n + 1, false);
        int part_size = dfs(1, graph, visited); // 아무 노드에서 시작

        // 3. 두 네트워크 크기 차이 계산
        int diff = abs(n - 2 * part_size);
        answer = min(answer, diff);
    }

    return answer;
}