// 2025-02-18 크로스 컨트리
// 구현
#include <iostream>

using namespace std;

int arr[1001];
int count[201];
int count2[201];
int score[201];
int fifth[201];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fill(count, count+201, 0);
        fill(score, score+201, 0);
        fill(fifth, fifth+201, 0);
        fill(count2, count2+201, 0);

        for(int i = 0; i<n; i++){
            int k;
            cin >> k;
            if(++count[k] == 5){
                fifth[k] = i;
            }
            arr[i] = k;
        }
        int s = 0;
        for(int i = 0; i<n; i++){
            if(count[arr[i]] != 6) continue;
            s++;
            if(count2[arr[i]] == 4) continue;
            score[arr[i]] += s;
            count2[arr[i]]++;
        }
        int answer = -1;
        int mn = 2e9;
        for(int i = 1; i<201; i++){
            if(score[i] == 0) continue;
            if(score[i] < mn){
                answer = i;
                mn = score[i];
            } else if(score[i] == mn && fifth[i] < fifth[answer]){
                answer = i;
            }
        }
        cout << answer << '\n';
    }
    
}