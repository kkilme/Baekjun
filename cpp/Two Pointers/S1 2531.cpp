// 2025-03-19 회전 초밥
// 브루트포스 / 투 포인터 / 슬라이딩 윈도우
#include <iostream>

using namespace std;

int dish[3001] = {0, };
int line[30000];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for(int i = 0; i<n; i++){
        cin >> line[i];
    }

    int answer = 0;
    for(int i = 0; i<k; i++){
        int cur = line[i];
        if(!dish[cur]){
            answer++;
        }
        dish[cur]++;
    }
    int cur = answer;
    if(!dish[c]) answer++;
    int l = 0, r = k-1;
    while(l < n){
        dish[line[l]]--;
        if(!dish[line[l]]) cur--;
        l++;
        r = r == n-1? 0 : r+1;
        dish[line[r]]++;
        if(dish[line[r]] == 1) cur++;

        if(dish[c] == 0){
            answer = max(answer, cur+1);
        } else {
            answer = max(answer, cur);
        }

        if(answer == k+1) break;
    }
    cout << answer;
}