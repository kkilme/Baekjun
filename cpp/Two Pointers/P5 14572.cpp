// 2024-12-23 스터디 그룹
// 투 포인터
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ST{
    int skill;
    int know[30] = {0,};
};

bool comp(const ST& a, const ST& b){
    return a.skill <= b.skill;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, d;
    cin >> n >> k >> d;

    vector<ST> students;

    for(int i = 0; i<n; i++){
        int m, sk;
        cin >> m >> sk;

        ST stu {sk};

        while(m--){
            int algo;
            cin >> algo;
            stu.know[algo-1] = 1;
        }

        students.push_back(stu);
    }

    sort(students.begin(), students.end(), comp);

    int l=0, r=0, answer=0;
    int arr[30];

    for(int i = 0; i<30; i++){
        arr[i] = students[0].know[i];
    }

    while(l < n){
        int allKnow=0, allAlgos=0;
        int skillDiff = students[r].skill - students[l].skill;
        // cout << l << ' ' << r << '\n';
        if(skillDiff <= d && r < n){

            for(int i = 0; i<30; i++){
                if(arr[i] == r-l+1) allKnow++;
                if(arr[i] > 0) allAlgos++;
            }
            // cout << "calc " << allAlgos << ' ' << allKnow << ' ' << r-l+1 << '\n';
            int cur = (allAlgos - allKnow) * (r-l+1);
            answer = max(cur, answer);

            r++;
            for(int i = 0; i<30; i++){
                arr[i] += students[r].know[i];
            }
            
        } else {
            for(int i = 0; i<30; i++){
                arr[i] -= students[l].know[i];
            }
            l++;
        }
    }

    cout << answer;
}