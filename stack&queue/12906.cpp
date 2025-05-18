// 스택 ,같은 숫자는 싫어 ,레벨 1, unique와 erase로 연속되는 중복값 삭제

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// vector<int> solution(vector<int> arr)
// {
//     stack<int> s;
//     vector<int> result;

//     for (int i = 0; i < arr.size(); i++)
//         if (s.empty() || s.top() != arr[i])
//         {
//             s.push(arr[i]);
//             result.push_back(arr[i]);
//         }

//     return result;
// }

vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<int> answer = arr;
    return answer;
}