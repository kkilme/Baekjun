// 2025-06-10 거짓말
// 자료 구조 / 그래프 이론 / 그래프 탐색 / 분리 집합
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int t;
    cin >> t;
    queue<int> truth;

    vector<bool> ptvisited(m);
    vector<bool> ppvisited(n+1);
    fill(ptvisited.begin(), ptvisited.end(), false);
    fill(ppvisited.begin(), ppvisited.end(), false);

    for(int i = 0; i<t; i++){
        int k;
        cin >> k;
        truth.push(k);
        ppvisited[k] = true;
    }
    
    vector<vector<int>> party(m);
    vector<vector<int>> people(n+1);
    for(int i = 0; i<m; i++){
        int pn;
        cin >> pn;
        for(int j = 0; j<pn; j++){
            int k;
            cin >> k;
            party[i].push_back(k);
            people[k].push_back(i);
        }
    }
    

    while(!truth.empty()){
        int cur = truth.front();
        truth.pop();

        for(auto pt: people[cur]){
            if(!ptvisited[pt]){
                ptvisited[pt] = true;
                for(auto pp: party[pt]){
                    if(!ppvisited[pp]){
                        ppvisited[pp] = true;
                        truth.push(pp);
                    }
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i<m; i++){
        if(!ptvisited[i]) answer++;
    }

    cout << answer;
}