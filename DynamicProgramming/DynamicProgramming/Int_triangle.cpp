#include<iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int i = 1;i < triangle.size();i++) {
        for (int j = 0;j < i + 1;j++) {
            if (j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if (j == i)
                triangle[i][j] += triangle[i - 1][j - 1];
            else {
                triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
    }

    for (int i = 0;i < triangle[triangle.size() - 1].size();i++) {
        if (answer < triangle[triangle.size() - 1][i])
            answer = triangle[triangle.size() - 1][i];
    }
    return answer;
}

int main() {
    vector<vector<int>> t = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };

    cout << solution(t);
}