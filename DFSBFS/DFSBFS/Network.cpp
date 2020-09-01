#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool check[201];

void DFS(vector<vector<int>> computers, int x) {
    check[x] = true;
    for (int i = 0;i < computers[x].size();i++) {
        if (i != x && computers[x][i] == 1 && !check[i])
            DFS(computers, i);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0;i < n;i++) {
        if (!check[i]) {
            DFS(computers,i);
            answer++;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> c = { {1,1,0},{1,1,0},{0,0,1} };
    cout << solution(3, c);
}