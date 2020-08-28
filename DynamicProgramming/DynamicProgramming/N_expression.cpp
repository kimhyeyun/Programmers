#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int answer = 9;

void dfs(int N, int number, int count, int currentNumber) {
    //일정횟수 이상 갔다면 리턴
    if (count >= 9)
        return;
    //현재 수가 number와 같다면 작은 횟수를 answer에 저장 후 리턴
    if (currentNumber == number) {
        answer = min(answer, count);
        return;
    }

    int tmp = 0;
    //초대 N의 사용 횟수는 9번까지므로 이때까지 반복
    for (int i = 0;i + count < 9;i++) {
        tmp = tmp * 10 + N;
        //더하기 빼기 곱하기 나누기
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