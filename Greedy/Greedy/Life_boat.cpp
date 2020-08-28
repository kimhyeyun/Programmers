#include <string>
#include<algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int start = 0;
    int end = people.size() - 1;
    while (start < end + 1) {
        if (people[start] + people[end] <= limit) {
            end--;
        }
        answer++;
        start++;
    }
    return answer;
}

int main() {
    vector<int> p = { 70,50,80,50 };
    cout << solution(p, limit);
}