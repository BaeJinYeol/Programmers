// 기출문제, 지폐 접기,레벨 1, 9번
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int min_wallet = min(wallet[0],wallet[1]);
    int max_wallet = max(wallet[0],wallet[1]);
    
    while(1) {
        int min_bill = min(bill[0],bill[1]);
        int max_bill = max(bill[0],bill[1]);

        if (min_bill <= min_wallet && max_bill <= max_wallet) break;

        if (bill[0] > bill[1]) bill[0] /= 2;
        else bill[1] /= 2;

        answer++;
    }

    return answer;
}