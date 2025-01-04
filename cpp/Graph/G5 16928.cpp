// 2025-01-05 뱀과 사다리 게임
// 그래프 이론 / 그래프 탐색
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int n, m;
unordered_map<int, int> board;
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist(101, 999);

void update(int curpos, int nextpos){
    if(nextpos > 100) return;

    if(board[nextpos] != 0){
            nextpos = board[nextpos];
    }

    if(dist[nextpos] > dist[curpos] + 1){
        dist[nextpos] = dist[curpos] + 1;
        pq.push(make_pair(dist[nextpos], nextpos));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i<=100; i++){
        board[i] = 0;
    }

    for(int i = 0; i<n; i++){
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    dist[1] = 0;
    pq.push(make_pair(0, 1));

    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();

        int pos = p.second;

        update(pos, pos+1);
        update(pos, pos+2);
        update(pos, pos+3);
        update(pos, pos+4);
        update(pos, pos+5);
        update(pos, pos+6);
    }

    cout << dist[100];
}