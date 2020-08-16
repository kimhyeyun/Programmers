#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	for (int i = 0;i < prices.size();i++) {
		int p = prices[i];
		int tmp = 0;

		for (int j = i + 1;j < prices.size();j++) {
			if (prices[j] >= p)
				tmp++;
			else {
				tmp++;
				break;
			}
		}
		answer.push_back(tmp);
	}
	return answer;
}

int main() {
	vector<int> p = { 1,2,3,2,3 };
	vector<int> a = solution(p);

	for (int i = 0;i < a.size();i++)
		cout << a[i] << " ";
}