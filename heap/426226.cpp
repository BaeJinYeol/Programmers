// 우선 순위 큐, 더 맵게, 레벨 2, greater은 오름차순, less는 내림차순

#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first, second;
    priority_queue<int, vector<int>, greater<>> pq (scoville.begin(), scoville.end());

    // for (int i = 0; i < scoville.size(); i++)
    //     pq.push(scoville[i]);

    if (K <= pq.top()) return 0;

    while (K > pq.top()) {
        if (pq.size() == 1) return -1;
        first = pq.top(); pq.pop();
        second = pq.top(); pq.pop();

        pq.push(first + second * 2);
        answer++;
    }

    return answer;
}