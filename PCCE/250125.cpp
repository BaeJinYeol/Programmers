// 기출문제, 이웃한 칸, 레벨 1, 9번
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < 4; i++) {
        int nh = h + dx[i];
        int nw = w + dy[i];
        if (nh < 0 || nh >= n || nw < 0 || nw >= m) continue;
        if (board[h][w] == board[nh][nw]) answer++;
    }

    return answer;
}