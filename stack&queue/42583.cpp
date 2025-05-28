// 큐, 다리를 지나는 트럭, 레벨 2, 차가 못올라가면 0을 푸쉬
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int time = 0, bridge_w = 0, i = 0;

    while (i < truck_weights.size()) {
        time++;

        // 다리 길이만큼 지나면 트럭 한 대 pop
        if (bridge.size() == bridge_length) {
            bridge_w -= bridge.front();
            bridge.pop();
        }

        // 다음 트럭을 올릴 수 있는지 확인
        if (bridge_w + truck_weights[i] <= weight) {
            bridge.push(truck_weights[i]);
            bridge_w += truck_weights[i];
            i++;
        } else {
            // 트럭 못올리면 0을 올림
            bridge.push(0);
        }
    }

    // 마지막으로 push한 트럭 시간 추가
    return time + bridge_length;
}