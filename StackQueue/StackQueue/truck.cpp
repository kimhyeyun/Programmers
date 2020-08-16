#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int current_weight=0;

	queue<int> cnt, bridgeOn;
	//올라가있는 차, 차마다 남은 거리

	while (1) {
		//중간에 차가 빠져 나가면 계산이 바뀌기 때문에 고정
		int size = bridgeOn.size();

		for (int i = 0;i < size;i++) {
			int len = bridgeOn.front();
			bridgeOn.pop();

			//도로 남은 길이가 없다면
			if (len <= 1) {
				current_weight -= cnt.front();
				cnt.pop();
				continue;
			}

			else
				bridgeOn.push(len - 1);
		}

		//대기차가 1대이상 있고 도로가 무게를 견딜수 있다면
		if (truck_weights.size() > 0 && current_weight + truck_weights.at(0) <= weight) {
			cnt.push(truck_weights.at(0));
			//트럭 올리기
			current_weight += truck_weights.at(0);
			bridgeOn.push(bridge_length);
			truck_weights.erase(truck_weights.begin());
		}

		//시간 증가
		answer++;

		//도로에 올라가있는 차와 대기차가 없다면 반복문 탈출
		if (truck_weights.size() == 0 && cnt.size() == 0)
			break;
	}
	return answer;
}

int main() {
	int b = 100;
	int w = 100;
	vector<int> t = { 10,10,10,10,10,10,10,10,10,10 };

	cout << solution(b, w, t);
}