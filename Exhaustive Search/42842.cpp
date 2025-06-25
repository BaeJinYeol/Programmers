#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    for (int height = 3; height <= sqrt(total); height) {
        if (total % height != 0) continue;

        int width = total / height;
        if ((width - 2) * (height -2) == yellow)
            return {width, height};
    }
    return {0,0};
}