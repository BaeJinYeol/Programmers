// DFS, 네트워크, 레벨 3
#include <vector>
#include <queue>
using namespace std;

void dfs(int cur, vector<vector<int>> &computers, vector<bool> &visited)
{
    visited[cur] = true;

    for (int i = 0; i < computers.size(); i++)
    {
        // 연결되어 있고, 아직 방문하지 않은 컴퓨터라면
        if (computers[cur][i] == 1 && !visited[i])
            dfs(i, computers, visited);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    vector<bool> visited(n, false);
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}