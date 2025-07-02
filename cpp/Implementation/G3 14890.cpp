// 2025-07-03 경사로
// 구현
// 투 포인터 사용
#include <bits/stdc++.h>
using namespace std;

int mp[100][100];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, L;
    cin >> n >> L;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> mp[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        int l, r;
        l = r = 0;
        bool flag = true;
        bool recentDown = false;
        while(r<n && flag){
            if(mp[i][l] == mp[i][r]){
                r++;
            } else {
                if(abs(mp[i][l] - mp[i][r]) != 1){
                    flag = false; break;
                }
                if(mp[i][l] < mp[i][r]){ // 오르막 설치
                    if(recentDown) l++;
                    if(r - l < L){
                        flag = false; break;
                    }
                    l = r;
                    recentDown = false;
                } else { // 내리막 설치
                    int cur = mp[i][r];
                    for(int j = 2; j<=L; j++){
                        if(r + 1 == n || mp[i][++r] != cur){
                            flag = false; break;
                        }
                    }
                    if(!flag) break;
                    l = r;
                    recentDown = true;
                    if(r != n-1){
                        r++;
                    }
                }
            }
        }
        ans += flag;
        l = r = 0;
        flag = true;
        recentDown = false;

        while(r<n && flag){
            if(mp[l][i] == mp[r][i]){
                r++;
            } else {
                if(abs(mp[l][i] - mp[r][i]) != 1){
                    flag = false; break;
                }
                if(mp[l][i] < mp[r][i]){ // 오르막 설치
                    if(recentDown) l++;
                    if(r - l < L){
                        flag = false; break;
                    }
                    l = r;
                    recentDown = false;
                } else { // 내리막 설치
                    int cur = mp[r][i];
                    for(int j = 2; j<=L; j++){
                        if(r + 1 == n || mp[++r][i] != cur){
                            flag = false; break;
                        }
                    }
                    if(!flag) break;
                    l = r;
                    recentDown = true;
                    if(r != n-1){
                        r++;
                    }
                }
            }
        }
        ans += flag;
    }

    cout << ans;
}