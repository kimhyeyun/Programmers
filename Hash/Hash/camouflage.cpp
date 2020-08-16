#include<iostream>
#include <string>
#include <vector>
#include<map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;

    for (vector<string> c : clothes)
        m[c[1]]++; 
    //clothes[][1]은 옷의 종류이다. 

    int answer = 1;
    map<string, int>::iterator it;
    
    for (it = m.begin();it != m.end();it++)
        answer *= it->second + 1;

    return answer-1;
}

int main() {
    vector<vector<string>> c = { {"yellow_hat","headgear"},{"blue_sunglasses","eyewear"},
        {"green_turban","headgear"} };

    cout << solution(c) << "\n";
}