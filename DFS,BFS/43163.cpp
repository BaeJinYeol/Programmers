// bfs, 단어변환, 레벨 3
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool canConvert(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i]) diff++;
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string,int>> q;
    vector<bool> visited(words.size(), false);

    q.push({begin, 0});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int i = 0; i < words.size(); i++) {
            if (canConvert(cur.first, words[i]) && !visited[i]) {
                if (words[i] == target) return cur.second + 1;

                q.push({words[i], cur.second + 1});
                visited[i] = true;

            }
        }

    }

    return 0;
}