// 2025-02-08 올림픽
// 구현 / 정렬
#include <iostream>
#include <algorithm>
using namespace std;

struct Country{
    int num;
    int gold;
    int silver;
    int bronze;

    bool operator==(const Country& other) const {
        return gold == other.gold && silver == other.silver && bronze == other.bronze;
    }

    bool operator!=(const Country& other) const {
        return !(*this == other);
    }
};


bool comp(const Country &a, const Country &b) {
    if (a.gold != b.gold) return a.gold > b.gold;
    if (a.silver != b.silver) return a.silver > b.silver;
    return a.bronze > b.bronze;
}

Country countries[1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int num, g,s,b;
    cin >> n >> k;

    for(int i = 0; i<n; i++){
        cin >> num >> g >> s >> b;
        Country c {num, g, s, b};
        countries[i] = c;
    }

    sort(countries, countries+n, comp);

    int idx;
    for(int i = 0; i<n; i++){
        if(countries[i].num == k){
            idx = i;
            break;
        }
    }
    while(idx > 0 && countries[idx] == countries[idx-1]) idx--;
    cout << idx+1;
}