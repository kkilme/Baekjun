// 2025-01-10 빗물
// 구현 / 시뮬레이션
#include <iostream>

using namespace std;

int world[500][500];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h, w;
    cin >> h >> w;

    for(int i = 0; i<w; i++){
        int k;
        cin >> k;
        for(int j = 0; j<h; j++){
            if(j<k) world[i][j] = 1;
            else world[i][j] = 0;
        }
    }

    int answer = 0;
    
    for(int i = 0; i<h; i++){
        int cur = -1;
        for(int j = 0; j<w; j++){
            if(world[j][i] == 1){
                if(cur == -1){
                    cur = j;
                    continue;
                }
                answer += j - cur - 1;
                cur = j;
            }
        }
    }
    cout << answer;
}