// 그리디, 구명보트, 레벨 2
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() - 1;
    while(left <= right) {
        if (people[left] + people[right] <= limit) left++;
        answer++;
        right--;
    }

    return answer;
}