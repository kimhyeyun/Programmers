#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> maxs(progresses.size());

	float tmp;
	int max = 0;
	int cnt = 1;

	for (int i = 0;i < progresses.size();i++) {
		tmp = speeds[i];
		tmp = (100 - progresses[i]) / tmp;
		max = (int)ceil(tmp);
		maxs[i] = max;
	}

	max = maxs[0];

	for (int i = 1;i < maxs.size();i++) {
		if (max >= maxs[i])
			cnt++;
		else {
			answer.push_back(cnt);
			cnt = 1;
			max = maxs[i];
		}
	}
	answer.push_back(cnt);

	return answer;
}

int main() {
	vector<int> p = { 93,30,55 };
	vector<int> s = { 1,30,5 };

	vector<int> a = solution(p, s);

	for (int i = 0;i < a.size();i++)
		cout << a[i] << " ";
}