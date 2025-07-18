// 2025-07-19 나무 재테크
// 구현 / 자료 구조? / 시뮬레이션
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int A[10][10];
int nutrient[10][10];
int addingNutrient[10][10];
vector<int> trees[10][10];
int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int answer;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    answer = m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            nutrient[i][j] = 5;
            cin >> A[i][j];
        }
    }

    for(int i = 0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        trees[x-1][y-1].push_back(z);
    }

    while (k--)
    {
        vector<pair<int, int>> repopulatingTrees;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                sort(trees[i][j].begin(), trees[i][j].end());
                int deadidx = -1;
                for(int l = 0; l<trees[i][j].size(); l++){
                    int age = trees[i][j][l];
                    if(nutrient[i][j] >= age){
                        nutrient[i][j] -= age;
                        if(++trees[i][j][l] % 5 == 0){
                            repopulatingTrees.push_back({i, j});
                        }
                    } else {
                        deadidx = l;
                        break;
                    }
                }

                if(deadidx!=-1){
                    for(int l = trees[i][j].size()-1; l>=deadidx; l--){
                        addingNutrient[i][j] += trees[i][j][l] / 2;
                        answer--;
                        trees[i][j].pop_back();
                    }
                }
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                nutrient[i][j] += addingNutrient[i][j] + A[i][j];
                addingNutrient[i][j] = 0;
            }
        }

        for(auto pos: repopulatingTrees){
            for(auto d: dirs){
                int nr = pos.first + d[0];
                int nc = pos.second + d[1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                trees[nr][nc].push_back(1);
                answer++;
            }
        }
    }
    
    cout << answer;


}