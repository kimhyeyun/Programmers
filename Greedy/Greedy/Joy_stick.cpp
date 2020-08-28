#include<iostream>
#include<string>
using namespace std;

int solution(string name) {
	int answer = 0, i = 0;

	//A로 구성된 화면
	string tmp(name.length(), 'A');

	while (1) {
		//바꾸고 있는 화면에 반영하고
		tmp[i] = name[i];
		//둘 중에 적은걸로 결과로 추가
		name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';

		//바꾼 후 문자열이 동일하다면 계산 종료
		if (tmp == name)
			break;

		//왼쪽으로 갈지 오른쪽으로 갈지
		for (int mv = 1;mv < name.length();mv++) {
			//오른쪽 이동이 빠르다면 오른쪽으로 이동하고 이동횟수 반영
			if (name[(i + mv) % name.length()] != tmp[(i + mv) % name.length()]) {
				i = (i + mv) % name.length();
				answer += mv;
				break;
			}

			//왼쪽으로 이동이 빠르다면 왼쪽으로 이동하고 이동횟수 반영
			else if (name[(i + name.length() - mv) % name.length()] !=
				tmp[(i + name.length() - mv) % name.length()]) {
				i = (i + name.length() - mv) % name.length();
				answer += mv;
				break;
			}
		}
	}
	return answer;
}

int main() {
	cout << solution("JEROEN");
}