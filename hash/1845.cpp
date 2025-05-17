// 해시, 폰켓몬, 레벨 1, unordered_set 해시 집합?

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// int solution(vector<int> nums)
// {
//     vector<int> dex;
//     sort(nums.begin(), nums.end());
//     dex.push_back(nums[0]);

//     int j = 0;
//     for (int i = 1; i < nums.size(); i++)
//         if (dex[j] < nums[i])
//         {
//             dex.push_back(nums[i]);
//             j++;
//         }

//     int answer;
//     if (dex.size() <= nums.size() / 2)
//         answer = dex.size();
//     else
//         answer = nums.size() / 2;

//     return answer;
// }

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}
