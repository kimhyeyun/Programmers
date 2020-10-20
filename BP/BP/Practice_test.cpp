#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> m1 = { 1,2,3,4,5 };
	vector<int> m2 = { 2,1,2,3,2,4,2,5 };
	vector<int> m3 = { 3,3,1,1,2,2,4,4,5,5 };

	int c1 = 0, c2 = 0, c3 = 0;

	int size = answers.size();

	for (int i = 0;i < size;i++) {
		int i1 = i % 5, i2 = i % 8, i3 = i % 10;

		if (answers[i] == m1[i1])
			c1++;
		if (answers[i] == m2[i2])
			c2++;
		if (answers[i] == m3[i3])
			c3++;
	}

	int max_cnt = max(c1, max(c2, c3));

	if (max_cnt == c1)
		answer.push_back(1);
	if (max_cnt == c2)
		answer.push_back(2);
	if (max_cnt == c3)
		answer.push_back(3);

	return answer;
}

int main() {
	vector<int> as = { 1,2,3,4,5 };
	vector<int> a = solution(as);

	for (int i = 0;i < a.size();i++)
		cout << a[i] << " ";
}