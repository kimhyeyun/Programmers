#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int b = (brown - 4) / 2;
    
    for (int i = 1;i <= yellow;i++) {
        if (yellow % i == 0) {
            if (i + (yellow / i) == b) {
                answer.push_back((yellow / i)+2);
                answer.push_back(i+2);
                break;
            }
        }
    }
    sort(answer.begin(), answer.end(),greater<int>());
    return answer;
}

int main() {
    vector<int> a = solution(8, 1);
    
    for (int i = 0;i < a.size();i++)
        cout << a[i] << " ";
}