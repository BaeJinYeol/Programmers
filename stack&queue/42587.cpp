// 큐 우선선위 큐, 프로세스, 레벨 2
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,bool>> q;
    priority_queue<int> pq;
    for (int i = 0; i < priorities.size(); i++) {
        q.push(make_pair(priorities[i], i == location));
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        if (cur.first == pq.top()) {
            pq.pop();
            answer++;
            if(cur.second) break;
        }
        else q.push(cur);
    }

    return answer;
}