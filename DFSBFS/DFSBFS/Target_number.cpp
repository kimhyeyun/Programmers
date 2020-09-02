#include<iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
int sz;

void DFS(vector<int> & numbers, int target,int sum, int idx) {
    if (idx == sz) {
        if (sum ==  target)
            answer++;
        return;
    }
    DFS(numbers, target, sum + numbers[idx], idx + 1);
    DFS(numbers, target, sum - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    sz = numbers.size();
    DFS(numbers, target, 0, 0);
    return answer;
}

int main() {
    vector<int> n = { 1,1,1,1,1 };
    cout << solution(n, 3);
}