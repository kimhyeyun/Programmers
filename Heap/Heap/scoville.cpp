#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0;i < scoville.size();i++)
        pq.push(scoville[i]);

    int f, s;

    while (pq.top() < K) {
        if (pq.size() <= 1)
            return -1;

        f = pq.top();
        pq.pop();
        s = pq.top();
        pq.pop();

        f = f + s * 2;
        pq.push(f);
        answer++;
    }

    return answer;
}

int main() {
    vector<int> s = { 1,2,3,9,10,12 };
    int k = 7;

    cout << solution(s, k) << "\n";
}