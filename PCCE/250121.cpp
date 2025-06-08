// 기출문제, 데이터 분석, 레벨 1, 10번, 람다식 사용
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    int flag = 0;
    int order_flag = 0;

    if (ext == "code") flag = 0;
    else if (ext == "date") flag = 1;
    else if (ext == "maximum") flag = 2;
    else flag = 3;

    if (sort_by == "code") order_flag = 0;
    else if (sort_by == "date") order_flag = 1;
    else if (sort_by == "maximum") order_flag = 2;
    else order_flag = 3;

    vector<vector<int>> new_data;
    for (int i = 0; i < data.size(); i++) 
        if (data[i][flag] < val_ext)
            new_data.push_back(data[i]);

    sort(new_data.begin(), new_data.end(), [order_flag](vector<int> a, vector<int> b) 
        {return a[order_flag] < b[order_flag];});

    return new_data;
}