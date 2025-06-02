// dfs, 타겟 넘버, 레벨 2
#include <vector>

using namespace std;

int count;
void dfs(vector<int> &numbers, int i, int sum, int target) {
    if (i == numbers.size()) {
        if (sum == target) count++;
        return;
    }

    dfs(numbers, i + 1, sum + numbers[i], target);
    dfs(numbers, i + 1, sum - numbers[i], target);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, 0, 0, target);
    
    int answer = count;
    return answer;
}