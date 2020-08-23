#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> ar;

    for (int i = 0;i < commands.size();i++) {
        for (int j = commands[i][0] - 1;j < commands[i][1];j++)
            ar.push_back(array[j]);
        sort(ar.begin(), ar.end());
        answer.push_back(ar[commands[i][2] - 1]);
        ar.clear();
    }
    return answer;
}

int main() {
    vector<int> ar = { 1,5,2,6,3,7,4 };
    vector<vector<int>> c = { {2,5,3},{4,4,1},{1,7,3 } };

    vector<int> a = solution(ar, c);

    for (int i = 0;i < a.size();i++)
        cout << a[i] << " ";
}