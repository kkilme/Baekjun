// 2025-03-30 치킨 배달
// 구현 / 브루트포스 / 백트래킹
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> homes;
vector<pair<int,int>> chickens;
int dists[100][13];

int n, m;
int ans = 2e9;

void backtrack(int idx, int depth, int use[]){
    if(depth == m){
        int sum = 0;
        for(int i = 0; i<homes.size(); i++){
            int dist = 2e9;
            for(int j = 0; j<chickens.size(); j++){
                if(use[j] == 1){
                    dist = min(dist, dists[i][j]);
                }
            }
            sum += dist;
            if(sum >= ans) return;
        }
        ans = min(ans, sum);
        return;
    }
    for(int i = idx; i < chickens.size(); i++){
        if(use[i] == 1) continue;
        use[i] = 1;
        backtrack(i+1, depth+1, use);
        use[i] = 0;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int k;
            cin >> k;
            if(k == 1) homes.push_back({i, j});
            else if(k == 2) chickens.push_back({i, j});
        }
    }
    for(int i = 0; i<homes.size(); i++){
        for(int j = 0; j<chickens.size(); j++){   
            dists[i][j] = abs(homes[i].first-chickens[j].first) + abs(homes[i].second-chickens[j].second);
        }
    }
    int use[13] = {0,};
    backtrack(0, 0, use);
    cout << ans;
}