// 정렬, 가장 큰 수, 레벨 2

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), comp);

    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {
        answer.append(to_string(numbers[i]));
    }

    return answer[0] == '0' ? "0" : answer;
}