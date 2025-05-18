// 스택 올바른 괄호, 레벨 2,

#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (char c : s)
    {
        if (c == '(')
            st.push(c);
        else if (c == ')' && !st.empty())
            st.pop();
        else if (c == ')' && st.empty())
            return false;
    }

    if (!st.empty())
        answer = false;

    return answer;
}