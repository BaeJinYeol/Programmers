// 그리디, 조이스틱, 레벨 2
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (char c : name) {
        if (c - 'A' <= 13) 
            answer += c - 'A';
        else 
            answer += 26 - (c - 'A');
    }

    int move = name.size() - 1;

    for (int i = 0; i < name.size(); i++) {
        int j = i + 1;
        while (j < name.size() && name[j] == 'A') j++;

        // i는 지금까지 오른쪽으로 간 거리, j는 연속된 A 이후 인덱스
        int leftright = i * 2 + (name.size() - j);
        int rightleft = i + 2 * (name.size() - j); 

        move = min(min(move, leftright), rightleft);
    }
    answer += move;
    return answer;
}