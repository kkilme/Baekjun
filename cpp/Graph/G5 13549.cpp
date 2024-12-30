// 2024-12-31 숨바꼭질
// 그래프 / 다익스트라 / 최단 경로
#include <iostream>
#include <queue>

using namespace std;

int n, k;
int answer = 100005;
int visit[100001] = {0,};
int dist[100001];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// first: time, second: current pos

void update(int nexttime, int curpos, int nextpos){
    if(nextpos <= 0 || nextpos > 100000) return;
    if(dist[nextpos] > dist[curpos] + nexttime){
        // cout << nextpos << ' ' << curpos << ' ' << dist[curpos] << '\n'; 
        dist[nextpos] = dist[curpos] + nexttime;
        pq.push(make_pair(nexttime, nextpos));
    }
}

int main(){
    cin >> n >> k;
    fill_n(dist, 100001, 100002);
    if(k <= n){
        cout << n-k;
        return 0;
    }

    pq.push(make_pair(0, n));
    dist[n] = 0;

    while(!pq.empty()){
        int pos = pq.top().second;
        pq.pop();

        update(1, pos, pos+1);
        update(1, pos, pos-1);
        update(0, pos, pos*2);
    }

    cout << dist[k];

}