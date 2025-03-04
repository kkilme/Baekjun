// 2025-03-04 비슷한 단어
// 구현 / 문자열
#include <iostream>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int arr[26] = {0, };
    for(int i = 0; i<s.size(); i++){
        arr[s[i]-'A']++;
    }

    int answer = 0;

    for(int i = 0; i<n-1; i++){
        string t;
        cin >> t;
        int arr2[26] = {0, };
        for(int j = 0; j<t.size(); j++){
            arr2[t[j]-'A']++;
        }
        bool flag = true;
        int onemore = 0;
        int oneless = 0;
        for(int j = 0; j<26; j++){
            int diff = arr[j] - arr2[j];
            if(diff > 1 || diff < -1){
                flag = false;
                break;
            }
            else if(diff == 1) {
                onemore++;
            }
            else if(diff == -1) {
                oneless++;
            }
        }
        if(flag && (onemore <= 1 && oneless <= 1)) {
            answer++;
        }
    }
    cout << answer;
}