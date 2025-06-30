// dijkstra, 합승 택시 요금
#include <queue>
#include <vector>
#include <climits>
using namespace std;

vector<int> dijkstra(int start, int n, vector<vector<pair<int,int>>> &graph) {
    vector<int> distance(n+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    distance[start] = 0;
    pq.push({0, start}); // 비용 ,노드

    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        // 이미 더 짧은 거리로 방문했다면 무시
        if (distance[now] < dist) continue;

        for (auto [next, cost] : graph[now]) {
            int nextDist = dist + cost;
            if (nextDist < distance[next]) {
                distance[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<pair<int,int>>> graph(n+1);

    for (auto &f : fares) {
        int u = f[0], v = f[1], w = f[2];
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    
    vector<int> from_s = dijkstra(s, n, graph);
    vector<int> from_a = dijkstra(a, n, graph);
    vector<int> from_b = dijkstra(b, n, graph);

    int answer = INT_MAX;

    for (int k = 1; k <= n; k++) {
        if (from_s[k] == INT_MAX || from_a[k] == INT_MAX || from_b[k] == INT_MAX) continue;
        answer = min(answer, from_s[k] + from_a[k] + from_b[k]);
    }
    
    return answer;
}