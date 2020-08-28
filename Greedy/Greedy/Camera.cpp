#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    //�⺻ ī�޶� 1��
    int answer = 1;

    //���� ����Ʈ ����
    sort(routes.begin(), routes.end());
    //�񱳸� ���� ó������ ������ �κ� üũ
    int tmp = routes[0][1];
    //����Ʈ ��ȸ�ϱ�
    for (auto a : routes) {
        //���� ������ ������ �ڿ� ���� ���´ٸ�
        if (tmp < a[0]) {
            //ī�޶� ��ġ
            answer++;
            //������ �κ� ����
            tmp = a[1];
        }
        //���� ������ ������ ����������
        if (tmp >= a[1])
            //������ �κ��� ������ ����
            tmp = a[1];
    }

    return answer;
}

