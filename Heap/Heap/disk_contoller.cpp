#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

struct cmp {
    bool operator() (vector<int> a,vector<int> b){
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    int len = jobs.size();
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp>pq; //min heap

    while (j < jobs.size() || !pq.empty()) {
        if (jobs.size() > j && time >= jobs[j][0]) { //time �ð��ȿ� ������ jobs�� �ִٸ�
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1]; //�ð��� ������ ������ ���� �ɸ��� �ð���ŭ �߰�
            answer += time - pq.top()[0]; //�۾��ð��� ��ýð� ��ŭ �߰�(����ð�-���½ð�)
            pq.pop(); //�۾��� �������Ƿ� ������ ����
        }
        else
            time = jobs[j][0];
    }
    return answer/len;
}

int main() {
    vector<vector<int>> j = { {0,3} ,{1,9},{2,6} };
    cout << solution(j) << "\n";
}