#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool* primeArr;

void Eratos(int num) {
    primeArr = new bool[num + 1];

    primeArr[0] = false;
    primeArr[1] = false;

    for (int i = 2;i <= num;i++)
        primeArr[i] = true;

    for (int i = 2;i * i <= num;i++) {
        if (primeArr[i]) //만약 처음수가 true 이면(소수이면)
            for(int j=i*i;j<=num;j+=i)
               primeArr[j] = false; // 그 배수를 false로 바꿔주기 
    }
}

//숫자가 주어진 문자들로 구성 가능한지 판별
bool isIncluded(int num, string str) {
    string strNum = to_string(num);
    for (int i = 0;i < strNum.size();i++) {
        int flag = false;
        for (int j = 0;j < str.size();j++) {
            if (strNum.at(i) == str.at(j)) {//일치하는 문자가 있다면
                flag = true;
                str.at(j) = ' '; //다시 사용할수 없게 공백으로 대체
                break;
            }
        }
        if (!flag) //한번이라도  일치하는 문자가 없다면
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());

    int maxNum = stoi(numbers);

    Eratos(maxNum);
    for (int i = 0;i <= maxNum;i++) {
        if (primeArr[i] && isIncluded(i, numbers))
            answer++;
    }
    return answer;
}

int main() {
    string s = "17";
    cout << solution(s);
}