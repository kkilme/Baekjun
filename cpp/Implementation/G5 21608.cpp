// 2025-05-16 상어 초등학교
// 구현
#include <bits/stdc++.h>
using namespace std;

int fr[401][4];
int seats[20][20];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct candi{
    int r;
    int c;
    int frs;
    int empty;

    candi(int rr, int cc){
        r = rr;
        c = cc;
        frs = 0;
        empty = 0;
    }
};

bool comp(const candi& c1, const candi& c2){
    if(c1.frs == c2.frs){
        if(c1.empty == c2.empty){
            if(c1.r == c2.r){
                return c1.c < c2.c;
            }
            return c1.r < c2.r;
        }
        return c1.empty > c2.empty;
    }
    return c1.frs > c2.frs;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    queue<int> order;
    for(int i = 0; i<n*n; i++){
        int k;
        cin >> k;
        order.push(k);
        for(int j = 0; j<4; j++){
            cin >> fr[k][j];
        }
    }
    
    vector<candi> candis;
    for(int i = 0; i<n*n; i++){
        candis.clear();
        int cur = order.front();
        order.pop();
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                if(seats[j][k] != 0) continue;
                candi c = candi(j, k);
                for(auto d: dir){
                    int nr = j + d[0];
                    int nc = k + d[1];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                        if(seats[nr][nc] == 0){
                            c.empty++;
                        } else {
                            for(auto f: fr[cur]){
                                if(seats[nr][nc] == f){
                                    c.frs++;
                                }
                            }
                        }
                    }
                }
                candis.push_back(c);
            }
        }
        sort(candis.begin(), candis.end(), comp);
        seats[candis[0].r][candis[0].c] = cur;
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int cur = seats[i][j];
            int frs = 0;
            for(auto d: dir){
                int nr = i + d[0];
                int nc = j + d[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    for(auto f: fr[cur]){
                        if(seats[nr][nc] == f){
                            frs++;
                        }
                    }
                }
            }
            if(frs != 0) ans += pow(10, frs-1);
        }
    }

    cout << ans;
}