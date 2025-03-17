// 2025-03-18 볼 모으기
// 그리디 알고리즘
// 어케든 풀었는데 아이디어 떠올리기 넘빡셌음;;
#include <iostream>
#include <string>
using namespace std;

int main(){

    int n;
    string s;
    cin >> n;
    cin >> s;

    int bcnt = 0, rcnt = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == 'B'){
            bcnt++;
        } else {
            rcnt++;
        }
    }

    // 양쪽 끝으로부터 같은 색의 공이 연속된 개수
    int l = 1, r = 1;
    for(int i = 1; i<n; i++){
        if(s[i] == s[0]) l++;
        else break;
    }
    for(int i = n-2; i>=0; i--){
        if(s[i] == s[n-1]) r++;
        else break;
    }

    // 양 끝 공 색이 같음
    if(s[0] == s[n-1]){
        if(s[0] == 'B'){
            // 양 끝 공 색이 B
            // R을 옮길 경우 R 개수만큼 움직임 필요. 
            // B를 옮길 경우 한 쪽 끝으로 몰아야 함.
            // 양 쪽 끝 중 더 많이 쌓여있는곳으로 몰아야함
            cout << min(bcnt - max(l,r), rcnt);
        } else {
            cout << min(rcnt - max(l,r), bcnt);
        }
    } else {
        // 양 끝 공 색이 다름
        if(s[0] == 'B'){ // 왼쪽 끝이 B: 왼쪽 끝으로 나머지 파란공을 다 옮기기 vs 오른쪽 끝으로 나머지 빨간공을 다 옮기기
            cout << min(bcnt - l, rcnt - r);
        } else { // 오른쪽 끝이 B: 오른쪽 끝으로 나머지 파란공을 다 옮기기 vs 왼쪽 끝으로 나머지 빨간공을 다 옮기기
            cout << min(bcnt - r, rcnt - l);
        }
    }
}