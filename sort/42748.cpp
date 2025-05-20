// 정렬, K번째 수, 레벨 1

#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int i, j, k;
    for (int n = 0; n < commands.size(); n++){
        i = commands[n][0]; j = commands[n][1]; k = commands[n][2];
        vector<int> tmp(array.begin() + (i - 1), array.begin() + j);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k-1]);
    }
    return answer;
}