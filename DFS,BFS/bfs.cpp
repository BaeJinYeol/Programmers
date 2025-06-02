#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> maps(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];  // 1 또는 0이 들어온다고 가정
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int groupCount = 0;                   // 총 덩어리 개수
    vector<int> groupSizes;               // 각 덩어리의 크기를 저장하고 싶다면

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 아직 방문하지 않았고, 값이 1이면 새 덩어리를 발견한 것
            if (!visited[i][j] && maps[i][j] == 1) {
                groupCount++;
                int cnt = 0;             // 이 덩어리에 속한 칸 개수

                // BFS로 연결된 모든 1을 방문 처리
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    cnt++;

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if (visited[nx][ny]) continue;
                        if (maps[nx][ny] != 1) continue;

                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }

                groupSizes.push_back(cnt);
            }
        }
    }

    // 결과 출력 예시
    cout << "총 그룹 개수: " << groupCount << "\n";
    cout << "각 그룹 크기: ";
    for (int sz : groupSizes) {
        cout << sz << " ";
    }
    cout << "\n";

    return 0;
}