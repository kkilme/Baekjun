// 24-08-29 계단 오르기
// DP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n;
    
    vector<int> inputs(n+1);
    inputs.push_back(0);
    vector<vector<int>> scores(2, vector<int>(n+1));

    for(int i = 0; i<n; i++){
        cin >> inputs[i+1];
    }

    scores[0][1] = inputs[1];

    for(int i = 2; i<n+1; i++){
        // cout << inputs[i] << endl;
        scores[0][i] = max({scores[0][i-2], scores[1][i-2]}) + inputs[i];
        scores[1][i] = scores[0][i-1] + inputs[i];
        // cout << scores[0][i] << " " << scores[1][i] << endl;
    }
    cout << max({scores[0][n], scores[1][n]});
}