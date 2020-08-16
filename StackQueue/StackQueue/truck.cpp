#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int current_weight=0;

	queue<int> cnt, bridgeOn;
	//�ö��ִ� ��, ������ ���� �Ÿ�

	while (1) {
		//�߰��� ���� ���� ������ ����� �ٲ�� ������ ����
		int size = bridgeOn.size();

		for (int i = 0;i < size;i++) {
			int len = bridgeOn.front();
			bridgeOn.pop();

			//���� ���� ���̰� ���ٸ�
			if (len <= 1) {
				current_weight -= cnt.front();
				cnt.pop();
				continue;
			}

			else
				bridgeOn.push(len - 1);
		}

		//������� 1���̻� �ְ� ���ΰ� ���Ը� �ߵ��� �ִٸ�
		if (truck_weights.size() > 0 && current_weight + truck_weights.at(0) <= weight) {
			cnt.push(truck_weights.at(0));
			//Ʈ�� �ø���
			current_weight += truck_weights.at(0);
			bridgeOn.push(bridge_length);
			truck_weights.erase(truck_weights.begin());
		}

		//�ð� ����
		answer++;

		//���ο� �ö��ִ� ���� ������� ���ٸ� �ݺ��� Ż��
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