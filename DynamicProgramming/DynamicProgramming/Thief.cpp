#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    vector<int> dp1(money.size() - 1);
    vector<int> dp2(money.size());

    //출발점
    dp1[0] = money[0];
    dp1[1] = money[0];
    for (int i = 2;i < money.size() - 1;i++)
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);

    //두번째 집이 출발점
    dp2[0] = 0;
    dp2[1] = money[1];
    for (int i = 2;i < money.size();i++)
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);


    return max(dp1[money.size() - 2], dp2[money.size() - 1]);
}

int main() {
    vector<int> m = { 1,2,3,1 };
    cout << solution(m);
}