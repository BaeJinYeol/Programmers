// multiset, 이중우선순위큐, 레벨 3, prev: iterator 반환
// multiset은 중복 원소를 허용하는 정렬된 컨테이너, 최댓값/최솟값 빠르게 접근 가능, 중복값도 insert로 모두 들어가며, erase로 한 개씩 삭제 가능
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for (auto op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            ms.insert(num);
        } else if (!ms.empty()) {
            if(op[2] == '1') {
                auto it = prev(ms.end()); // 최대값
                ms.erase(it);
            } else {
                auto it = ms.begin();   // 최소값
                ms.erase(it);
            }
        }
    }

    if (ms.empty()) return {0,0};

    return {*prev(ms.end()), *ms.begin()};
}