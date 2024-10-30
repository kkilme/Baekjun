// 2024-09-08 토마토
// Graph - BST

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> m >> n;

    int num_done = 0, num_block = 0, day = 0;
    vector<vector<int>> box(n, vector<int>(m));
    queue<pair<int, int>> q;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> k;
            if(k == -1) num_block++;
            else if (k == 1)
            {
                num_done++;
                q.push(pair<int, int>(i,j));
            }
            box[i][j] = k;
        }
    }

    if(num_done + num_block == n*m){
        cout << 0;
        return 0;
    }

    vector<pair<int, int>> dir = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};

    int qsize;

    while(!q.empty() && num_done + num_block != n*m){
        day++;
        qsize = q.size();
        for(int i = 0; i<qsize; i++){
            pair<int, int> a = q.front();
            q.pop();
            for(pair<int, int> d: dir){
                int y = a.first + d.first;
                int x = a.second + d.second;
                if(y < 0 || y >= n || x < 0 || x >= m){
                    continue;
                }
                if(box[y][x] == 0){
                    box[y][x] = 1;
                    q.push(make_pair(y, x));
                    num_done++;
                }
            }
        }
    }

    if(num_done + num_block == n*m){
        cout << day;
    } else{
        cout << -1;
    }
}