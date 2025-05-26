// 브루트, 최소직사각형, 레벨 1

#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a.front() > b.front();
}

int solution(vector<vector<int>> sizes) {
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1])
        swap(sizes[i][0], sizes[i][1]);
    }
    sort(sizes.begin(), sizes.end(), comp);
    
    int max = 0;
    for (vector<int> v : sizes) {
        if (v[1] > max) max = v[1];
    }

    return sizes[0][0] * max;

    /*
    int answer=0;

    int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));
        h=max(h,max(sizes[i][0],sizes[i][1]));
    }
    answer=w*h;

    return answer;
    */
}