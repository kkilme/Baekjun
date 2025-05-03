// 2025-05-03 다각형의 면적
// 기하학 / 다각형의 넓이
#include <bits/stdc++.h>
using namespace std;

pair<long double, long double> points[10001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long double x1, y1, x2, y2, x3, y3;

    cin >> n >> x1 >> y1;
    for(int i = 0; i<n-1; i++){
        cin >> points[i].first >> points[i].second;
    }

    long double answer = 0;
    for(int i = 0; i<n-2; i++){
        x2 = points[i].first;
        y2 = points[i].second;
        x3 = points[i+1].first;
        y3 = points[i+1].second;

        answer += (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0; // 여기서 abs 하면 안됨
    }
    answer = round(answer * 10.0L) / 10.0L;
    cout << fixed << setprecision(1) << abs(answer); // 여기서 abs 해야함
}