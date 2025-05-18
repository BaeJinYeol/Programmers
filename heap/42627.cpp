// 큐, 디스크 컨트롤러, 레벨 3, priority_queue

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int ms = 0;    // 현재 시간
    int idx = 0;   // 작업 인덱스
    int total = 0; // 총 소요 시간
    int count = 0; // 완료한 작업 수

    while (count < jobs.size())
    {
        while (idx < jobs.size() && jobs[idx][0] <= ms)
        {
            pq.push({jobs[idx][1], jobs[idx][0]}); // 작업 시간, 요청 시점
            idx++;
        }

        if (!pq.empty())
        {
            pair<int, int> cur = pq.top();
            pq.pop();
            ms += cur.first;
            total += ms - cur.second;
            count++;
        }
        else
            ms = jobs[idx][0];
    }

    return total / jobs.size();
}