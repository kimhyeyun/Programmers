#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int check[101][101] = { 0, };

    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            //출발점 제외
            if (i == 1 && j == 1) {
                check[i][j] = 1;
                continue;
            }
            //갈 수 없는 경우
            bool can = true;
            for (int k = 0;can && k < puddles.size();k++)
                if (i == puddles[k][0] && j == puddles[k][1])
                    can = false;
            if (!can)
                check[i][j] = 0;
            //갈 수 있는 경우
            else
                check[i][j] = (check[i - 1][j] + check[i][j - 1]) % 1000000007;
        }
    }
    return check[m][n];
}

int main() {
    vector<vector<int>> p = { {2,2} };

    cout << solution(4, 3, p);
}