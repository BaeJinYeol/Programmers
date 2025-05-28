// 해시, 의상, 레벨 2, unordered_map
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, vector<string>> clothes_map;

    for (auto& item : clothes) {
        string name = item[0];
        string type = item[1];
        clothes_map[type].push_back(name);
    }

    int mul = 1;
    for (auto& pair : clothes_map) mul *= pair.second.size() + 1;

    if (clothes_map.size() == 1) return clothes_map.begin()->second.size();

    return mul - 1;
}