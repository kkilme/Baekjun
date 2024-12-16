// 2024-12-16 요세푸스 문제
// 구현 / 자료구조? / 큐?
#include <iostream>
#include <vector>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector<int> v;
    for(int i = 0; i<n; i++){
        v.push_back(i+1);
    }
    string s = "<";
    auto it = v.begin();

    while(!v.empty()){
        for(int i=1; i<k; i++){
            it++;
            if(it == v.end()){
                it = v.begin();
            }
        }

        s.append(to_string(*it));
        s.append(", ");
        it = v.erase(it);
        if(it == v.end()){
                it = v.begin();
        }
        // for(int i = 0; i<v.size(); i++){
        //     cout << v[i] << ' ';
        // }
        // cout << ' ' << distance(v.begin(), it);
        // cout << '\n';
    }
    s.erase(s.size()-2, 2);
    s.append(">");
    cout << s;
}