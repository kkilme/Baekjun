// 2025-02-21 감시
// 구현 / 브루트포스 / 시뮬레이션 / 백트래킹?
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> cctv;
int answer;

struct map{
    int map[8][8];
    int empty = 0;
};

void look(map &mp, int dir, int x, int y){
    if(dir == 0){
        for(int i = x-1; i>=0; i--){
            if(mp.map[i][y] == 6){
                break;
            }
            if(mp.map[i][y] == 0){
                mp.map[i][y] = -1;
                mp.empty--;
            }
        }
    } else if(dir == 1){
        for(int i = y+1; i<m; i++){
            if(mp.map[x][i] == 6){
                break;
            }
            if(mp.map[x][i] == 0){
                mp.map[x][i] = -1;
                mp.empty--;
            }
        }
    } else if(dir == 2){
        for(int i = x+1; i<n; i++){
            if(mp.map[i][y] == 6){
                break;
            }
            if(mp.map[i][y] == 0){
                mp.map[i][y] = -1;
                mp.empty--;
            }
        }
    } else if(dir == 3){
        for(int i = y-1; i>=0; i--){
            if(mp.map[x][i] == 6){
                break;
            }
            if(mp.map[x][i] == 0){
                mp.map[x][i] = -1;
                mp.empty--;
            }
        }
    }
}

void look_2way_horizontal(map& mp, int dir, int x, int y){
    if(dir == 0){
        look(mp, 0, x, y);
        look(mp, 2, x, y);
    } else if(dir == 1){
        look(mp, 1, x, y);
        look(mp, 3, x, y);
    }
}

void look_2way_right(map& mp, int dir, int x, int y){
    if(dir == 0){
        look(mp, 0, x, y);
        look(mp, 1, x, y);
    } else if(dir == 1){
        look(mp, 1, x, y);
        look(mp, 2, x, y);
    } else if(dir == 2){
        look(mp, 2, x, y);
        look(mp, 3, x, y);
    } else if(dir == 3){
        look(mp, 3, x, y);
        look(mp, 0, x, y);
    }
}

void look_3way(map& mp, int dir, int x, int y){
    if(dir == 0){
        look(mp, 0, x, y);
        look(mp, 1, x, y);
        look(mp, 2, x, y);
    } else if(dir == 1){
        look(mp, 1, x, y);
        look(mp, 2, x, y);
        look(mp, 3, x, y);
    } else if(dir == 2){
        look(mp, 2, x, y);
        look(mp, 3, x, y);
        look(mp, 0, x, y);
    } else if(dir == 3){
        look(mp, 3, x, y);
        look(mp, 0, x, y);
        look(mp, 1, x, y);
    }
}

void look_4way(map& mp, int x, int y){
    look(mp, 0, x, y);
    look(mp, 1, x, y);
    look(mp, 2, x, y);
    look(mp, 3, x, y);
}

void find(map mp, int depth){
    if(depth == cctv.size()){
        answer = min(answer, mp.empty);
        return;
    }

    int x = cctv[depth].first;
    int y = cctv[depth].second;
    int cur = mp.map[x][y];
    if(cur == 1){
        for(int i = 0; i<4; i++){
            map tmp = mp;
            look(tmp, i, x, y);
            find(tmp, depth+1);
        }
    } else if(cur == 2){
        for(int i = 0; i<2; i++){
            map tmp = mp;
            look_2way_horizontal(tmp, i, x, y);
            find(tmp, depth+1);
        }
    } else if(cur == 3){
        for(int i = 0; i<4; i++){
            map tmp = mp;
            look_2way_right(tmp, i, x, y);
            find(tmp, depth+1);
        }
    } else if(cur == 4){
        for(int i = 0; i<4; i++){
            map tmp = mp;
            look_3way(tmp, i, x, y);
            find(tmp, depth+1);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    map mp;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int k;
            cin >> k;
            if(k == 0){
                mp.empty++;
            } else if(k!=6 && k!=5){
                cctv.push_back({i, j});
            }
            mp.map[i][j] = k;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mp.map[i][j] == 5){
                look_4way(mp, i, j);
            }
        }
    }

    answer = mp.empty;
    find(mp, 0);

    cout << answer;
}