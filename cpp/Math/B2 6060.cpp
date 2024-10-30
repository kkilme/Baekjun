// 2024-09-13 Wheel Rotation
// Math

#include <iostream>
#include <vector>

using namespace std;

int main(){

    pair<int, int> arr[1001];

    int n, s, d, c;

    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> s >> d >> c;
        arr[s] = pair<int, int>(d, c);
    }
    
    int next = 1, answer=-1;

    for(int i = 0; i<n; i++){
        if(arr[next].second == 1) answer *= -1;
        next = arr[next].first;
    }
    
    answer = answer == 1 ? 1 : 0;

    cout << answer;
}