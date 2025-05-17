// 2025-05-17 배열 돌리기 1
// 구현
#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int arr[301][301];
int arr2[301][301];

pair<int, int> getNext(int start, int nn, int mm, int curx, int cury, int rcount){
    int nx = curx, ny = cury;
    for(int i = 0; i<rcount; i++){
        if(nx == start){
            if(ny == start + nn - 1){
                nx++;
            } else {
                ny++;  
            }
        } else if (ny == start + nn - 1){
            if(nx == start + mm - 1){
                ny--;
            } else {
                nx++;
            }
        } else if (nx == start + mm - 1){
            if(ny == start){
                nx--;
            } else {
                ny--;
            }
        } else if (ny == start){
            if(nx == start){
                ny++;
            } else {
                nx--;
            }
        }
    }
    return {nx, ny};
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
            arr2[i][j] = arr[i][j];
        }
    }

    int cur = 0;
    int nn = n, mm = m;
    while(nn > 1 && mm > 1){
        int rr = r;
        int cury = cur;
        int curx = cur;
        int cnt = nn * 2 + mm * 2 - 4;
        rr %= cnt;
        for(int i = 0; i<cnt; i++){
            auto nxt = getNext(cur, nn, mm, curx, cury, rr);
            arr2[nxt.second][nxt.first] = arr[cury][curx];
            
            auto npos = getNext(cur, nn, mm, curx, cury, 1);
            curx = npos.first;
            cury = npos.second;
        }
        cur++;
        nn -= 2;
        mm -= 2;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << arr2[i][j] << ' ';
        }
        cout << '\n';
    }
}

/* GPT O(NM)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> A(N, vector<int>(M));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> A[i][j];

    int layers = min(N, M) / 2;
    for(int k = 0; k < layers; k++){
        // 경계: (k,k) … (k,M-k-1) … (N-k-1,M-k-1) … (N-k-1,k) … 돌아옴
        vector<int> v;

        // 1) top row
        for(int j=k; j < M-k; j++) v.push_back(A[k][j]);
        // 2) right col
        for(int i=k+1; i < N-k; i++) v.push_back(A[i][M-k-1]);
        // 3) bottom row
        for(int j=M-k-2; j >= k; j--) v.push_back(A[N-k-1][j]);
        // 4) left col
        for(int i=N-k-2; i > k; i--) v.push_back(A[i][k]);

        int len = v.size();
        int r = R % len;

        // 시프트
        vector<int> v2(len);
        for(int i=0; i < len; i++){
            v2[i] = v[(i + r) % len];
        }

        // 다시 채우기 (same order)
        int idx = 0;
        for(int j=k; j < M-k; j++) A[k][j] = v2[idx++];
        for(int i=k+1; i < N-k; i++) A[i][M-k-1] = v2[idx++];
        for(int j=M-k-2; j >= k; j--) A[N-k-1][j] = v2[idx++];
        for(int i=N-k-2; i > k; i--) A[i][k] = v2[idx++];
    }

    // 출력
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << A[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}

*/