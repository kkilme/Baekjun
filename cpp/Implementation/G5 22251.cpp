// 2025-01-15 빌런 호석
// 구현 / 브루트포스
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

vector<vector<int>> map = {
    {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
    {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
    {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
    {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
    {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
    {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
    {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
    {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
    {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
    {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
};

int n, k, p;
string x;
int answer = 0;
unordered_set<int> s;
void find(int idx, int sum, int curnum){
    if(sum > p || curnum > n){
        return;
    }
    if(idx == 0 && sum != 0 && curnum != 0 && s.find(curnum) == s.end()){
        s.insert(curnum);
        answer++;
    }

    if(idx > 0){
        for(int i = 0; i<10; i++){
            find(idx-1, sum+map[x[idx-1]-'0'][i], curnum + pow(10, k-idx)*i);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> p >> x;

    for(int i = x.size(); i<k; i++){
        x = "0" + x;
    }

    for(int i = 0; i<10; i++){
        find(k-1, map[x[k-1]-'0'][i], i);
    }

    cout << answer;
}