#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int answer = 9;

void dfs(int N, int number, int count, int currentNumber) {
    //����Ƚ�� �̻� ���ٸ� ����
    if (count >= 9)
        return;
    //���� ���� number�� ���ٸ� ���� Ƚ���� answer�� ���� �� ����
    if (currentNumber == number) {
        answer = min(answer, count);
        return;
    }

    int tmp = 0;
    //�ʴ� N�� ��� Ƚ���� 9�������Ƿ� �̶����� �ݺ�
    for (int i = 0;i + count < 9;i++) {
        tmp = tmp * 10 + N;
        //���ϱ� ���� ���ϱ� ������
        dfs(N, number, count + 1 + i, currentNumber + tmp);
        dfs(N, number, count + 1 + i, currentNumber - tmp);
        dfs(N, number, count + 1 + i, currentNumber * tmp);
        dfs(N, number, count + 1 + i, currentNumber / tmp);
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if (answer == 9)
        return -1;
    return answer;
}

int main() {
    cout << solution(5, 12);
}