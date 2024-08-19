#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> damaged;
    vector<int> more;
    int n, s, r;
    cin >> n >> s >> r;
    for(int i =0; i<s;i++){
        int k;
        cin >> k;
        damaged.push_back(k);
    }
    for(int i =0; i<r;i++){
        int k;
        cin >> k;
        if(find(damaged.begin(), damaged.end(), k) != damaged.end()){
            damaged.erase(remove(damaged.begin(), damaged.end(), k), damaged.end());
            continue;
        }
        more.push_back(k);
    }
    for(int i =0; i<more.size(); i++){
        if(find(damaged.begin(), damaged.end(), more[i]-1) != damaged.end()){
            damaged.erase(remove(damaged.begin(), damaged.end(), more[i]-1), damaged.end());
            continue;
        }
        if(find(damaged.begin(), damaged.end(), more[i]+1) != damaged.end()){
            damaged.erase(remove(damaged.begin(), damaged.end(), more[i]+1), damaged.end());
        }
    }
    cout << damaged.size();
}
