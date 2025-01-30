// 2025-01-31 비슷한 단어
// 자료 구조? / 문자열 / 정렬 / 해시를 사용한 집합과 맵?
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    string words[20000];
    pair<string, int> arr[20000];

    cin >> n;
    for(int i = 0; i<n; i++){
        string word;
        cin >> word;
        words[i] = word;
        arr[i].first = word;
        arr[i].second = i;
    }
    sort(arr, arr+n);

    pair<int, int> best = {0, 1};
    int mxlen = 0;
    for(int i = 0; i<n; i++){
        for(int j = 1; i+j<n; j++){
            int len = 0;
            string a = arr[i].first;
            string b = arr[i+j].first;

            while(len < a.size() && len < b.size() && a[len] == b[len]){
                len++;
            }
            if(len == 0 || len < mxlen) break;
            else if(len > mxlen){
                mxlen = len;
                best = {arr[i].second, arr[i+j].second};
                if(best.first > best.second) swap(best.first, best.second);
            } else if (len == mxlen){
                pair<int, int> curpair = {arr[i].second, arr[i+j].second};
                if(curpair.first > curpair.second) swap(curpair.first, curpair.second);
                if(best.first > curpair.first || (best.first == curpair.first && best.second > curpair.second)) best = {curpair.first, curpair.second};
            }
        }
    }
    cout << words[best.first] << '\n' << words[best.second] << '\n';
}