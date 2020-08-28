#include<iostream>
#include <string>
#include <stack>
using namespace std;

string solution(string number, int k) {
	stack<char> stk;

	int sz = number.length() - k;

	for (int i = 0;i < number.length();i++) {
		char ch = number[i];

		for (;(!stk.empty()) && k > 0;k--) {
			char stk_top = stk.top();
			if (stk_top >= ch)
				break;
			stk.pop();
		}
		stk.push(ch);
	}

	while (stk.size() != sz) {
		stk.pop();
	}
	string answer;

	while (!stk.empty()) {
		char x = stk.top();
		answer = x + answer;
		stk.pop();
	}

	return answer;
}

int main() {
	cout << solution("1231234", 3);
}