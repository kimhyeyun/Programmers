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
        if (primeArr[i]) //���� ó������ true �̸�(�Ҽ��̸�)
            for(int j=i*i;j<=num;j+=i)
               primeArr[j] = false; // �� ����� false�� �ٲ��ֱ� 
    }
}

//���ڰ� �־��� ���ڵ�� ���� �������� �Ǻ�
bool isIncluded(int num, string str) {
    string strNum = to_string(num);
    for (int i = 0;i < strNum.size();i++) {
        int flag = false;
        for (int j = 0;j < str.size();j++) {
            if (strNum.at(i) == str.at(j)) {//��ġ�ϴ� ���ڰ� �ִٸ�
                flag = true;
                str.at(j) = ' '; //�ٽ� ����Ҽ� ���� �������� ��ü
                break;
            }
        }
        if (!flag) //�ѹ��̶�  ��ġ�ϴ� ���ڰ� ���ٸ�
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