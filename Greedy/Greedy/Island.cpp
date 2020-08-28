#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;
 
//가중치에 따른 오름차순 정렬을 위한 비교
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

//부모 노드 찾기
int getParent(vector<int>& par, int x) {
    //부모노드가 자신이라면 자신을 리턴
    if (par[x] == x)
        return x;
    return par[x] = getParent(par, par[x]);
}

//부모노드 병합하기
void unionParent(vector<int>& par, int a, int b) {
    //두개의 부모를 가져와서
    a = getParent(par, a);
    b = getParent(par, b);

    //작은 노드쪽의 부모로 병합시키기
    a < b ? par[b] = a : par[a] = b;
}

//부모노드가 같은지 비교
bool find(vector<int>& par, int a, int b) {
    //부모노드를 가져와서
    a = getParent(par, a);
    b = getParent(par, b);

    return a == b;
}

//Minimum Spanning Tree Algorithm
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int max = 0;

    //가중치 기준으로 정렬
    sort(costs.begin(), costs.end(), cmp);

    //cost를 순회해서 제일 높은 노드 찾기
    for (auto a : costs)
        if (max < a[1])
            max = a[1];

    //부모노드용 리스트 생성, 초기화
    vector<int> par;
    for (int i = 0;i <= max;i++)
        par.push_back(i);

    //코스트를 처음부터 순회
    for (auto a : costs) {
        //두개의 부모노드가 같지 않다면 - > 사이클이 생성 안된다면
        if (!find(par, a[0], a[1])) {
            //결과에 가중치 추가
            answer += a[2];
            //부모노드 병합하기
            unionParent(par, a[0], a[1]);
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> c = { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} };

    cout << solution(4, c);
}