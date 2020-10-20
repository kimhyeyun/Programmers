#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int ans = 51;
vector<bool> check;

void DFS(vector<string> words, string now, string target, int cnt) {    
    //�ϼ� ��
    if (now.compare(target) == 0) {
        ans = min(ans, cnt); //�ּڰ� �ֱ�
        return;
    }

    //�� �� �ִ� �� ����(�Ѱ� �̻� ���� ���� ���ư���)
    for (int i = 0;i < words.size();i++) {
        //���ڿ��� ���̰� �ϳ��� ���� ����
        int diff = 0;
        if (check[i])
            continue;
        for (int j = 0;diff <= 1 && j < now.size();j++)
            if (now[j] != words[i][j])
                diff++;

        //�ϳ��� ���̳��� ����
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