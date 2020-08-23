#include<iostream>
#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    string op;
    int num;

    for (int i = 0;i < operations.size();i++) {
        op = operations.at(i);
        num = stoi(op.substr(2));

        if (op[0] == 'I') {
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else {
            if (dq.empty())
                continue;
            if (num == 1)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }

    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}

int main() {
    vector<string> o1 = { "I 16","D 1" };
    vector<string> o2 = { "I 7","I 5","I-5","D -1"};

    vector<int> a1 = solution(o1);
    vector<int> a2 = solution(o2);

    for (int i = 0;i < a1.size();i++)
        cout << a1[i] << " ";
    cout << "\n";

    for (int i = 0;i < a2.size();i++)
        cout << a2[i] << " ";
    cout << "\n";
}