#include<iostream>
#include<string>
using namespace std;

int solution(string name) {
	int answer = 0, i = 0;

	//A�� ������ ȭ��
	string tmp(name.length(), 'A');

	while (1) {
		//�ٲٰ� �ִ� ȭ�鿡 �ݿ��ϰ�
		tmp[i] = name[i];
		//�� �߿� �����ɷ� ����� �߰�
		name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';

		//�ٲ� �� ���ڿ��� �����ϴٸ� ��� ����
		if (tmp == name)
			break;

		//�������� ���� ���������� ����
		for (int mv = 1;mv < name.length();mv++) {
			//������ �̵��� �����ٸ� ���������� �̵��ϰ� �̵�Ƚ�� �ݿ�
			if (name[(i + mv) % name.length()] != tmp[(i + mv) % name.length()]) {
				i = (i + mv) % name.length();
				answer += mv;
				break;
			}

			//�������� �̵��� �����ٸ� �������� �̵��ϰ� �̵�Ƚ�� �ݿ�
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