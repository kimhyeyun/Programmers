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
        if (jobs.size() > j && time >= jobs[j][0]) { //time 시간안에 도착한 jobs이 있다면
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1]; //시간에 이작이 끝날때 까지 걸리는 시간만큼 추가
            answer += time - pq.top()[0]; //작업시간에 대시시간 만큼 추가(현재시간-들어온시간)
            pq.pop(); //작업이 끝났으므로 힙에서 제거
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