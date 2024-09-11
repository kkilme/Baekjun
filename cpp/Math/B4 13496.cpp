// 2024-09-11 The Merchant of Venice
// Math

#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, s, d;
    cin >> t;
    for(int i = 1; i<=t; i++){
        int answer = 0;
        cin >> n >> s >> d;
        while(n--){
            int dist, v;
            cin >> dist >> v;
            if(dist <= s * d){
                answer += v;
            }
        }
        cout << "Data Set " << i << ":" << '\n';
        cout << answer << "\n\n";
    }
}