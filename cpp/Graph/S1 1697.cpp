// 2024 11 12 숨바꼭질
// 그래프 이론, 그래프 탐색, 너비 우선 탐색
#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    bool check[100001] = {false,};

    vector<int> s;
    vector<int> nxts;

    nxts.push_back(n);
    check[n] = 1;
    bool found = false;
    int depth = -1;
    while(!found && n < k){
        depth++;
        s.resize(nxts.size());
        copy(nxts.begin(),nxts.end(), s.begin());
        while(!s.empty()){
            int a = s.back();
            s.pop_back();
            
            if(a == k){
                found = true;
                break;
            }

            if(a-1 >= 0 && !check[a-1]){
                check[a-1] = true;
                nxts.push_back(a-1);
            }
            if(a+1 < 100001 && !check[a+1]){
                check[a+1] = true;
                nxts.push_back(a+1);
            }
            if(2*a < 100001 && !check[2*a]){
                check[2*a] = true;
                nxts.push_back(2*a);
            }
        }
    }
    if(n >= k){
        cout << n-k;
    }
    else cout << depth;
}