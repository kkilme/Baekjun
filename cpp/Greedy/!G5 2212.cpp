// 2025-05-13 센서
// 그리디 알고리즘 / 정렬
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<int> sensors;
    for(int i = 0; i<n; i++){
        int p;
        cin >> p;
        sensors.push_back(p);
    }

    sort(sensors.begin(), sensors.end());
    vector<int> gaps;
    for(int i = 1; i<n; i++){
        gaps.push_back(sensors[i]-sensors[i-1]);
    }
    sort(gaps.begin(), gaps.end(), greater<int>());

    // 가장 큰 K-1개의 간격을 제외. K-1개의 틈에서 구간을 끊으면, 총 K의 구간이 완성됨.
    int answer = 0;
    for(int i = k-1; i<n-1; i++){
        answer += gaps[i];
    }
    cout << answer;
}

/*
1 3 6 7 9
 [1,3] [6,9]

3  6  7  8  10  12  14  15  18  20
   [3] [6,8] [10,15] [18][20]  
*/