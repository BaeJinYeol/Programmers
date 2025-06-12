// dfs, 소수 찾기, 레벨 2, next_permutation으로도 가능 <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

void dfs(string current, vector<bool>& visited, const string& numbers, set<int>& result) {
    if (!current.empty())
        result.insert(stoi(current));

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(current + numbers[i], visited, numbers, result);
            visited[i] = false;
        }
    }
}

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    vector<bool> visited(numbers.size(), false);

    dfs("", visited, numbers, s);

    for (int i : s)
        if (isPrime(i)) answer++;

    return answer;
}

/*
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(string numbers) {
    set<int> s;
    sort(numbers.begin(), numbers.end());  // 사전순 정렬 (next_permutation 사용을 위함)

    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0, i));
            s.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    int answer = 0;
    for (int num : s)
        if (isPrime(num)) answer++;

    return answer;
}
*/