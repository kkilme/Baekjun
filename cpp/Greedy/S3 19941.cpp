// 2025-02-19 햄버거 분배
// 그리디 알고리즘?
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){

    int n, k;
    string s;
    cin >> n >> k >> s;

    queue<int> hq;
    queue<int> pq;
    int answer = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == 'H'){
            if(!pq.empty()){
                while(abs(pq.front() - i) > k)
                {
                    pq.pop();
                }
                if(!pq.empty()){
                    pq.pop();
                    answer++;
                } else {
                    hq.push(i);
                }             
            } else {
                hq.push(i);
            }
        }
        else if(s[i] == 'P'){
            if(!hq.empty()){
                while(abs(hq.front() - i) > k)
                {
                    hq.pop();
                }
                if(!hq.empty()){
                    hq.pop();
                    answer++;
                } else {
                    pq.push(i);
                }
            } else {
                pq.push(i);
            }
        }
    }

    cout << answer;

}