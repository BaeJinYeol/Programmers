// bfs, 게임 맵 최단거리, 레벨 2
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;
    distance[0][0] = 1;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny] || maps[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            distance[nx][ny] = distance[x][y] + 1;
            q.push({nx, ny});
        }
    }

    if (distance[n-1][m-1] == 0) return -1;
    return distance[n-1][m-1];
}