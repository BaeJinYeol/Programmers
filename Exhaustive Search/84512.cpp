// 수학적, 모음사전, 레벨 2
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    vector<int> weight = {781, 156, 31, 6, 1}; // 각 자리수 가중치
    string alpha = "AEIOU";
    int answer = 0;

    for (int i = 0; i <word.size(); i++) {
        int idx = alpha.find(word[i]);
        answer += weight[i] * idx;
    }

    return answer + word.length();
}