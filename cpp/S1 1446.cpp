// 2025-03-17 지름길
// 다이나믹 프로그래밍? / 그래프 이론 / 최단 경로 / 다익스트라?
// 그냥 재귀로 품
#include <iostream>
#include <algorithm>
using namespace std;

int n, d;
int answer = 2e9;
struct pt{
    int start;
    int end;
    int length;
};
pt arr[12];

bool comp(const pt& p1, const pt& p2){
    return p1.start <= p2.start;
}

void find(int depth, int curpos, int curcost){
    if(curpos > d) return;
    if(depth == n || curpos == d){
        if(curpos < d) curcost += d - curpos;
        answer = min(answer, curcost);
        return;
    }

    pt next = arr[depth];
    if(next.start >= curpos) find(depth+1, next.end, curcost + (next.start - curpos) + next.length);
    find(depth+1, curpos, curcost);
}


int main(){

    cin >> n >> d;
    for(int i = 0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = pt({a, b, c});
    }

    sort(arr, arr+n, comp);
    find(0, 0, 0);
    cout << answer;
}