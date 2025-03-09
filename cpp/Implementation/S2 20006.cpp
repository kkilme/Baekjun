// 2025-03-10 랭킹전 대기열
// 구현 / 시뮬레이션
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int p, m;

struct Room{
    int lvl;
    vector<pair<string, int>> ps;

    bool check(int level){
        return abs(lvl - level) <= 10 && ps.size() < m;
    }

    void add(string s, int l){
        ps.push_back({s, l});
    }

    void print(){
        if(ps.size() == m){
            cout << "Started!\n";
        } else {
            cout << "Waiting!\n";
        }
        sort(ps.begin(), ps.end());

        for(auto p: ps){
            cout << p.second << ' ' << p.first << '\n';
        }
    }

    Room(int l, string s){
        lvl = l;
        ps.push_back({s, l});
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> p >> m;
    vector<Room> rooms;
    for(int i = 0; i<p; i++){
        int l; string name;
        cin >> l >> name;
        bool added = false;
        for(Room &room: rooms){
            if(room.check(l)){
                room.add(name, l);
                added = true;
                break;
            }
        }
        if(!added){
            rooms.push_back(Room({l, name}));
        }
    }
    for(Room r: rooms){
        r.print();
    }
}