// 2025-01-27 여행 가자
// 자료 구조 / 그래프 이론 / 그래프 탐색 / 분리 집합
// Union-Find
#include <iostream>

using namespace std;

int n, m;
int cities[201];

int find(int x) {
    while (cities[x] != x) {
        cities[x] = cities[cities[x]]; // path compression
        x = cities[x];
    }
    return x;
}

void _union(int x, int y) {
    int p = find(x);
    int q = find(y);
    if(p != q) {
        cities[p] = q;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cities[i] = i;
    }

    for(int i = 0; i<n; i++){
        bool connected;
        for(int j = 0; j<n; j++){
            cin >> connected;
            if(connected){
                _union(i, j);
            }
        }
    }

    int parent, cur;
    int city;
    cin >> city;
    parent = find(city-1);
    for(int i = 1; i<m; i++){
        cin >> city;
        cur = find(city-1);
        if(cur != parent){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}