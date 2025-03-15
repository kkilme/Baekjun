// 2025-03-15 겹치는 건 싫어
// 투 포인터?
// 큐로 품
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int cnt[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int answer = -1;
    for(int i = 0; i<n; i++){
        int cur;
        cin >> cur;
        if(cnt[cur] == k){
            while(!q.empty()){
                int num = q.front();
                q.pop();
                cnt[num]--;
                if(num == cur) break;
            }
        }
        cnt[cur]++;
        q.push(cur);
        answer = max(answer, (int)q.size());
    }
    cout << answer;
}