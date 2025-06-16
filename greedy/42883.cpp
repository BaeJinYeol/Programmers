// 그리디, 큰 수 만들기, 레벨2
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> st;
    
    for (char c : number) {
        while (!st.empty() && st.top() < c && k > 0) {
            st.pop();
            k--;
        }
        st.push(c);
    }

    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    if (k > 0) answer = answer.substr(0, answer.size() - k);
    
    return answer;
}