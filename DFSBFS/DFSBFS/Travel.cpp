#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool DFS(string here, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& tmp, vector<string>& answer, int cnt) {
    tmp.push_back(here);
    if (cnt == tickets.size()) {
        answer = tmp;
        return true;
    }

    for (int i = 0;i < tickets.size();i++) {
        if (tickets[i][0] == here && !visited[i]) {
            visited[i] = true;
            if (DFS(tickets[i][1], tickets, visited, tmp, answer, cnt + 1))
                return true;
            visited[i] = false;
            //다음여정으로 갈 수 없다는 의미
        }
    }
    tmp.pop_back();
    //그래서 제거해주고 다시

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, tmp;
    vector<bool> visited(tickets.size(), false);

    sort(tickets.begin(), tickets.end());

    DFS("ICN", tickets, visited, tmp, answer, 0);

    return answer;
}

int main() {
    vector<vector<string>> t = { {"ICN","JFK"},{"HND","IAD"},{"JFK","HND"} };
    vector<string> a = solution(t);

    for (int i = 0;i < a.size();i++)
        cout << a[i]<<" ";
}