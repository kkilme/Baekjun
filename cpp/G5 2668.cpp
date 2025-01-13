// 2025-01-14 숫자고르기
// 그래프 이론? / 그래프 탐색? / DFS?
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }

    vector<int> answer;
    vector<int> sames;
    vector<int> cur;

    for(int i = 1; i<=n; i++){
        if(arr[i] == i) sames.push_back(i); 
    }

    answer = sames;
    for(int i = 1; i <=n; i++){
        vector<bool> visited(n, false);
        for(int k: sames) visited[k] = true;

        int nextidx = i;
        cur = sames;
        cur.push_back(nextidx);

        if(visited[i]) continue;
        visited[i] = true;
        while (true)
        {
            nextidx = arr[nextidx];
            if(visited[nextidx]){
                if(nextidx == i){
                    if(answer.size() < cur.size()){
                        answer = cur;
                        for(int p: cur){
                            if(find(sames.begin(), sames.end(), p) == sames.end()) sames.push_back(p);
                        }
                    }
                }
                break;
            } else {
                cur.push_back(nextidx);
                visited[nextidx] = true;
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(int k: answer){
        cout << k << '\n';
    }
}