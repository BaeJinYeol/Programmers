// 브루트, 모의고사, 레벨 1

#include <vector>
using namespace std;

vector<int> solution(vector<int> answers) {
    int user1[] = {1,2,3,4,5,0};
    int user2[] = {2,1,2,3,2,4,2,5,0};
    int user3[] = {3,3,1,1,2,2,4,4,5,5,0};

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == user1[i % 5]) user1[5]++;
        if (answers[i] == user2[i % 8]) user2[8]++;
        if (answers[i] == user3[i % 10]) user3[10]++;
    }
    
    vector<int> answer;
    int max_val = max(max(user1[5],user2[8]),user3[10]);

    if (max_val == user1[5]) answer.push_back(1);
    if (max_val == user2[8]) answer.push_back(2);
    if (max_val == user3[10]) answer.push_back(3);
    
    return answer;
}