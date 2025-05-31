// 스텍, 주식 가격, 레벨 2

#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {
        int time = 0;
        for (int j = i + 1; j < prices.size(); j++) {
            time++;
            if (prices[i] > prices[j]) break;
        }
        answer.push_back(time);
    }
    return answer;
}

/* stack을 index로 사용하여 시간 복잡도 O(n)
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}
*/