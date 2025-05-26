// 그리디, 체육복, 레벨 1, find 사용법

#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (auto it = lost.begin(); it != lost.end(); ) {
        auto found = find(reserve.begin(), reserve.end(), *it);
        if (found != reserve.end()) {
            reserve.erase(found);
            it = lost.erase(it);
        } else {
            ++it;
        }
    }

    int answer = n - lost.size();

    for (int lo : lost) {
        auto left = find(reserve.begin(), reserve.end(), lo-1);
        if (left != reserve.end()) {
            reserve.erase(left);
            answer++;
            continue;
        }

        auto right = find(reserve.begin(), reserve.end(), lo+1);
        if (right != reserve.end()) {
            reserve.erase(right);
            answer++;
        }
    }

    return answer;
}