// 2025-01-29 고층 건물
// 수학 / 브루트포스 / 기하학
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int heights[52];
    for(int i = 1; i<=n; i++){
        cin >> heights[i];
    }
    pair<double, double> line[52][52];

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i == j) line[i][j] = {0, 0};
            else{
                double a = (double)(heights[j] - heights[i]) / (j - i);
                double b = heights[i] - a * i;
                line[i][j] = {a, b};
            }
        }
    }
    int answer[51] = {0, };

    bool flag = false;
    double a, b;
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            flag = false;
            a = line[i][j].first;
            b = line[i][j].second;
            for(int k = i+1; k<j; k++){
                if(heights[k] >= a * k + b){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                answer[i]++;
            }
        }
        for(int j = i-1; j>=1; j--){
            flag = false;
            a = line[i][j].first;
            b = line[i][j].second;
            for(int k = i-1; k>j; k--){
                if(heights[k] >= a * k + b){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                answer[i]++;
            }
        }
    }

    cout << *max_element(answer + 1, answer + n + 1);
}