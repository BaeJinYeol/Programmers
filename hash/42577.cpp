// 해시, 전화번호 목록, 레벨 2

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> phones(phone_book.begin(), phone_book.end());

    for (string num : phone_book) {
        string prefix = "";
        for (int i = 0;  i < num.size() - 1; i++) {
            prefix += num[i];
            if (phones.find(prefix) != phones.end())
                return false;
        }
    }

    return true;
}