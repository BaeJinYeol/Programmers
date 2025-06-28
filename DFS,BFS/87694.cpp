// BFS, 아이템 줍기, 레벨 3
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY){
    const int MAX = 102; // 스케일 2배 (내 외부 구별)

    vector<vector<int>> board(MAX, vector<int>(MAX, 0));
    vector<vector<int>> visited(MAX, vector<int>(MAX, false));

    // 맵 채우기
    for (auto r : rectangle){
        int x1 = r[0] * 2, y1 = r[1] * 2, x2 = r[2] * 2, y2 = r[3] * 2;

        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                board[i][j] = 1;
    }
    // 내부 지우기
    for (auto r : rectangle){
        int x1 = r[0] * 2 + 1, y1 = r[1] * 2 + 1, x2 = r[2] * 2 - 1, y2 = r[3] * 2 - 1;

        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                board[i][j] = 0;
    }

    queue<pair<int, int>> q;
    queue<int> dist;

    visited[characterX * 2][characterY * 2] = true;
    q.push({characterX * 2, characterY * 2});
    dist.push(0);

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        int d = dist.front(); dist.pop();

        if (x == itemX * 2 && y == itemY * 2) return d / 2;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] != 1) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
            dist.push(d + 1);
        }
    }

    return 0;
}