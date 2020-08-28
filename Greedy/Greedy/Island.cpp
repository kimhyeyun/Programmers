#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
 
//����ġ�� ���� �������� ������ ���� ��
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

//�θ� ��� ã��
int getParent(vector<int>& par, int x) {
    //�θ��尡 �ڽ��̶�� �ڽ��� ����
    if (par[x] == x)
        return x;
    return par[x] = getParent(par, par[x]);
}

//�θ��� �����ϱ�
void unionParent(vector<int>& par, int a, int b) {
    //�ΰ��� �θ� �����ͼ�
    a = getParent(par, a);
    b = getParent(par, b);

    //���� ������� �θ�� ���ս�Ű��
    a < b ? par[b] = a : par[a] = b;
}

//�θ��尡 ������ ��
bool find(vector<int>& par, int a, int b) {
    //�θ��带 �����ͼ�
    a = getParent(par, a);
    b = getParent(par, b);

    return a == b;
}

//Minimum Spanning Tree Algorithm
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int max = 0;

    //����ġ �������� ����
    sort(costs.begin(), costs.end(), cmp);

    //cost�� ��ȸ�ؼ� ���� ���� ��� ã��
    for (auto a : costs)
        if (max < a[1])
            max = a[1];

    //�θ���� ����Ʈ ����, �ʱ�ȭ
    vector<int> par;
    for (int i = 0;i <= max;i++)
        par.push_back(i);

    //�ڽ�Ʈ�� ó������ ��ȸ
    for (auto a : costs) {
        //�ΰ��� �θ��尡 ���� �ʴٸ� - > ����Ŭ�� ���� �ȵȴٸ�
        if (!find(par, a[0], a[1])) {
            //����� ����ġ �߰�
            answer += a[2];
            //�θ��� �����ϱ�
            unionParent(par, a[0], a[1]);
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> c = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

    cout << solution(4, c);
}