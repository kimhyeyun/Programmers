#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0;i < completion.size();i++) {
		if (participant[i] != completion[i])
			return participant[i];
	}
	return participant.back();
}

int main() {
	vector<string> par = { "leo","kiki","eden" };
	vector<string> com = { "eden","kiki" };

	cout << solution(par, com) << "\n";
}