// 2025-01-03 컨베이어 벨트 위의 로봇
// 구현 / 시뮬레이션

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, k;
int progress = 0;
unordered_map<int, int> hp;
vector<int> belts;
vector<int> robots;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    int hp0 = 0;

    for(int i = 0; i<2*n; i++){
        cin >> hp[i];
        belts.push_back(i);
    }
    
    while(hp0 < k){
        progress++;
        int tmp = belts.back();
        belts.pop_back();
        belts.insert(belts.begin(), tmp);

        if(robots.size() != 0 && robots.front() == belts[n-1]) robots.erase(robots.begin());

        for(int i = 0; i<robots.size(); i++){
            int nextbelt = (robots[i]+1) % (2*n);
            if(hp[nextbelt] == 0) continue;

            if(i == 0 || robots[i-1] != nextbelt) robots[i] = nextbelt;
            else continue;

            hp[nextbelt]--;
            if(hp[nextbelt] == 0) hp0++;
        }

        if(robots.size() != 0 && robots.front() == belts[n-1]) robots.erase(robots.begin());

        if(hp[belts[0]] != 0){ 
            robots.push_back(belts[0]);
            hp[belts[0]]--;
            if(hp[belts[0]] == 0) hp0++;
        }
    }
    cout << progress;
}