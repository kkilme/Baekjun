// 2025-02-06 하늘에서 별똥별이 빗발친다
// 브루트포스
// 풀이법을 떠올리고 이해하기 쉽지 않음
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, k;
    cin >> n >> m >> l >> k;

    vector<pair<int, int>> stars(k);

    for(int i = 0; i<k; i++){
        cin >> stars[i].first >> stars[i].second;
    }
    int mx = 0;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            int count = 0;
            for(int p = 0; p<k; p++){
                if(stars[i].first <= stars[p].first && stars[p].first <= stars[i].first + l 
                    && stars[j].second <= stars[p].second && stars[p].second <= stars[j].second + l) count++;
            }
            mx = max(count, mx);
        }
    }

    cout << k-mx;
}