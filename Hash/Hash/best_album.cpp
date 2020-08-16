#include<iostream>
#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<cstring>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> mp;
    map<string, int>::iterator it;

    for (int i = 0;i < genres.size();i++) {
        it = mp.find(genres[i]);
        if (it != mp.end()) {
            int pre = it->second;
            mp[genres[i]] = pre + plays[i];
        }
        else
            mp.insert({ genres[i],plays[i] });
    }

    map<int, string> rev;
    map<int, string>::iterator rit;

    for (it = mp.begin();it != mp.end();it++)
        rev.insert({ -(it->second),it->first });

    pair<int, int> arr[10010];
    for (rit = rev.begin();rit != rev.end();rit++) {
        string gen = rit->second;
        memset(arr, 0, sizeof(arr));
        int idx = 0;
        for (int i = 0;i < genres.size();i++) {
            if (gen.compare(genres[i]) == 0)
                arr[idx++] = {-plays[i], i};
        }
        sort(arr, arr + idx);
        if (idx == 1)
            answer.push_back(arr[0].second);
        else {
            answer.push_back(arr[0].second);
            answer.push_back(arr[1].second);
        }
    }
    return answer;
}

int main() {
    vector<string> g = { "classic","pop","classic","classic","pop" };
    vector<int> p = { 500,600,150,800,2500 };

    vector<int> a = solution(g, p);
    for (int i = 0;i < a.size();i++)
        cout << a[i] << " ";
}