// 스택, 기능개발, 레벨 2, cmath ceil올림
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> complete;

    for (int i = 0; i < progresses.size(); i++) {
        // int x = (99 - progresses[i]) / speeds[i] + 1;
        int x = ceil((100.0 - progresses[i]) / speeds[i]); // 소수점 올림
        complete.push_back(x);
    }

    int day = complete[0];
    answer.push_back(1);
    for (int i = 1; i < complete.size(); i++) {
        if (day < complete[i]) {
            day = complete[i];
            answer.push_back(1);
        }
        else {
           answer.back()++;
        }
    }

    return answer;
}