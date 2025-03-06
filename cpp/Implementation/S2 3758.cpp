// 2025-03-06 KCPC
// 구현 / 정렬
#include <iostream>
#include <algorithm>
using namespace std;

struct Team{
    int score[101];
    int totalscore;
    int submitcnt;
    int lastsubmit;
    int id;

    Team(){
        for(int i = 0; i < 101; i++) {
            score[i] = 0;
        }
        totalscore = 0;
        submitcnt = 0;
        lastsubmit = 0;
    }
};

bool comp(Team a, Team b){
    if(a.totalscore == b.totalscore){
        if(a.submitcnt == b.submitcnt){
            return a.lastsubmit < b.lastsubmit;
        }
        return a.submitcnt < b.submitcnt;
    }
    return a.totalscore > b.totalscore;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, targetid, m;
        cin >> n >> k >> targetid >> m;
        Team team[101];
        for(int i = 1; i <= n; i++)
        {
            team[i] = Team();
            team[i].id = i;
        }
        for(int i = 0; i<m; i++){
            int id, num, score;
            cin >> id >> num >> score;
            team[id].submitcnt++;
            team[id].totalscore -= team[id].score[num];
            team[id].score[num] = max(team[id].score[num], score);
            team[id].totalscore += team[id].score[num];
            team[id].lastsubmit = i;
        }

        sort(team+1, team+n+1, comp);
        for(int i = 1; i <= n; i++){
            if(team[i].id == targetid){
                cout << i << '\n';
            }
        }
    }
}