#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int ans = 51;
vector<bool> check;

void DFS(vector<string> words, string now, string target, int cnt) {    
    //완성 비교
    if (now.compare(target) == 0) {
        ans = min(ans, cnt); //최솟값 넣기
        return;
    }

    //갈 수 있는 곳 가기(한개 이상 차이 나면 돌아가기)
    for (int i = 0;i < words.size();i++) {
        //문자열의 차이가 하나면 변경 가능
        int diff = 0;
        if (check[i])
            continue;
        for (int j = 0;diff <= 1 && j < now.size();j++)
            if (now[j] != words[i][j])
                diff++;

        //하나만 차이나면 변경
        if (diff == 1) {
            check[i] = true;
            DFS(words, words[i], target, cnt + 1);
            check[i] = false;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    check.assign(words.size(), false);
    DFS(words, begin, target, 0);
    return ans;
}