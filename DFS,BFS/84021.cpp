// dfs, 퍼즐 조각 채우기, 레벨 3, 너무 어려움
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> normalize(vector<pair<int,int>> block) {
    int minX = 1e9, minY = 1e9;
    for (auto [x ,y] : block) {
        minX = min(minX, x);
        minY = min(minY, y);
    }
    for (auto &p : block) {
        p.first -= minX;
        p.second -= minY;
    }
    sort(block.begin(), block.end()); // 비교를 위해 정렬
    return block;
}

vector<pair<int,int>> rotate90(const vector<pair<int,int>> &block) {
    vector<pair<int,int>> rotated;
    for (auto [x, y] : block)
        rotated.push_back({y, -x});
    return normalize(rotated);
}

bool match(vector<pair<int,int>> a, vector<pair<int,int>> b) { return a == b; }

void dfs(int x, int y ,vector<vector<int>> &board, vector<vector<bool>> &visited, vector<pair<int,int>> &block, int target) {
    int n = board.size();
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    visited[x][y] = true;
    block.push_back({x, y});

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (!visited[nx][ny] && board[nx][ny] == target) {
            dfs(nx, ny, board, visited, block, target);
        }
    }

}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<pair<int,int>>> empties, pieces;

    // 1. 빈칸 추출
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && game_board[i][j] == 0) {
                vector<pair<int,int>> block;
                dfs(i, j, game_board, visited, block, 0);
                empties.push_back(normalize(block));
            }

    // 2. 퍼즐 조각 추출
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j] && table[i][j] == 1) {
                vector<pair<int,int>> block;
                dfs(i, j, table, visited, block, 1);
                pieces.push_back(normalize(block));
            }   

    // 3. 조각 매칭
    vector<bool> used(pieces.size(), false);
    int answer = 0;

    for (auto empty : empties) {
        for (int i = 0; i < pieces.size(); i++) {
            if (used[i]) continue;

            auto shape = pieces[i];
            for (int r = 0; r < 4; r++) {
                if (match(empty, shape)) {
                    answer += shape.size();
                    used[i] = true;
                    break;
                }
                shape = rotate90(shape);
            }

            if (used[i]) break;
        }
    }

    return answer;
}