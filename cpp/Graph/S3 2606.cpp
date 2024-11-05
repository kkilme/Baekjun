// 20241105 바이러스
// Graph, BFS DFS
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int c, n;

    cin >> c >> n;

    map<int, vector<int>> g;
    map<int, bool> check;

    for(int i = 0; i<c; i++){
        g.insert({c, {}});
        check.insert({c, false});
    }

    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;

        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    queue<int> q;
    q.push(0);

    int answer = -1;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        if(check[k]) continue;
        check[k] = true;
        answer++;
        auto n = g[k];
        for(int i = 0; i<n.size(); i++){
            if(!check[n[i]]) q.push(n[i]);
        }
    }
    cout << answer;
}