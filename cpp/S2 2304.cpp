// 2025-01-29 창고 다각형
// 구현 / 자료 구조? / 브루트포스 / 스택?
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    pair<int, int> lhs[1002];

    int l, h;
    for(int i = 0; i<n; i++){
        cin >> l >> h;
        lhs[i] = {l, h};
    }

    sort(lhs, lhs+n);
    
    int answer = 0;
    int maxi = 0;

    for(int i = 0; i<n; i++){
        if(lhs[i].second > lhs[maxi].second){
            maxi = i;
        }
    }

    int next = 0;
    while(next < maxi){
        int found = -1;
        for(int j = next+1; j<=maxi; j++){
            if(lhs[j].second >= lhs[next].second){
                found = j;
                break;
            }
        }
        if(found != -1){
            answer += lhs[next].second * (lhs[found].first - lhs[next].first);
            next = found;
        } else next++;
    }

    next = n-1;
    while(next > maxi){
        int found = -1;
        for(int j = next-1; j>=maxi; j--){
            if(lhs[j].second >= lhs[next].second){
                found = j;
                break;
            }
        }
        if(found != -1){
            answer += lhs[next].second * (lhs[next].first - lhs[found].first);
            next = found;
        } else next--;
    }
    
    answer += lhs[maxi].second;
    cout << answer;
}