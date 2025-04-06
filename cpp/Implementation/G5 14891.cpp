// 2025-04-06 톱니바퀴
// 구현 / 시뮬레이션
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int twelve[4];
int three[4];
int nine[4];
string wheels[4];

void rotate(int idx, int dir){
    twelve[idx] = (twelve[idx] + dir + 8) % 8;
    three[idx] = (three[idx] + dir + 8) % 8;
    nine[idx] = (nine[idx] + dir + 8) % 8;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fill(twelve, twelve + 4, 0);
    fill(three, three + 4, 2);
    fill(nine, nine + 4, 6);
    for(int i = 0; i < 4; i++){
        cin >> wheels[i];
    }
    int k;
    cin >> k;

    for(int i = 0; i<k; i++){
        int n, r;
        cin >> n >> r;
        n--;
        vector<int> left, right;
        if(r == -1) left.push_back(n); 
        else right.push_back(n);
        int prv = r;
        for(int j = n; j>=1; j--){
            if(wheels[j][nine[j]] - '0' + wheels[j-1][three[j-1]] - '0' == 1){
                if(prv == 1) left.push_back(j-1);
                else right.push_back(j-1);
                prv = -prv;
            } else break;
        }
        prv = r;
        for(int j = n; j<3; j++){
            if(wheels[j][three[j]] - '0' + wheels[j+1][nine[j+1]] - '0' == 1){
                if(prv == 1) left.push_back(j+1);
                else right.push_back(j+1);
                prv = -prv;
            } else break;
        }
        for(int i: left){
            rotate(i, 1);
        }
        for(int i: right){
            rotate(i, -1);
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        ans += (wheels[i][twelve[i]] - '0') * (1 << i); // 2^i
    }
    cout << ans << endl;
}