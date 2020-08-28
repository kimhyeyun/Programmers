#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;

int solution(int n, vector<int>lost, vector<int> reserve) {
	vector<int> student(n, 1);

	for (int i = 0;i < lost.size();i++)
		student[lost[i] - 1]--;
	for (int i = 0;i < reserve.size();i++)
		student[reserve[i] - 1]++;

	for (int i = 0;i < student.size();i++) {
		if (student[i] == 0) {
			if (student[i - 1] == 2) {
				student[i - 1]--;
				student[i]++;
			}
			else if (student[i + 1] == 2) {
				student[i + 1]--;
				student[i]++;
			}
		}
	}

	int answer = 0;
	for (int i = 0;i < student.size();i++) {
		if (student[i] != 0)
			answer++;
	}
	return answer;

}

int main() {
	vector<int> l = { 2,4 };
	vector<int> r = { 1,3,5 };

	cout << solution(5, l, r);
}