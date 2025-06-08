// 기출문제, 완전탐색, 공원, 레벨 1, 10번
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check_mat(vector<vector<string>> park, vector<int> mats,int i, int j) {
    for (int mat : mats) {
        if (i + mat - 1 >= park.size() || j + mat - 1 >= park[0].size()) continue;

        bool flag = true;
        for (int k = 0; k < mat && flag; k++) // flag를 for문 조건문에 넣어 2중 for문 바로 탈출
            for (int l = 0; l < mat && flag; l++)
                if (park[i+k][j+l] != "-1") flag = false;

        if (flag) return mat;
    }
    return -1;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(),mats.end(), greater<>());
    int answer = -1;
    int n = park.size();
    int m = park[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (park[i][j] == "-1")
                answer = max(answer,check_mat(park,mats,i,j));
                
    return answer;
}