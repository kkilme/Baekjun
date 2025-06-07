// 2025-06-07 이진 검색 트리
// 그래프 이론 / 그래프 탐색 / 트리 / 재귀
// 쉽지않네
#include <bits/stdc++.h>
using namespace std;

vector<int> result;

void postorder(int l, int r){
    if(l >= r) return;

    int rt = result[l];
    int idx = l+1;
    // 왼쪽 서브트리의 경계 idx 찾기: result[l+1..idx) < root
    while(idx < r && result[idx] < rt) idx++;

    postorder(l+1, idx); // 왼 [l+1, idx)
    postorder(idx, r); // 오 [idx, r)
    cout << rt << '\n'; // 루트
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while(cin >> x){
        result.push_back(x);
    }

    postorder(0, result.size());
}

/* O(N)
#include <bits/stdc++.h>
using namespace std;

vector<int> pre;
int idx = 0;

// 전위 순회 pre에서 현재 idx가 [mn, mx] 범위 안에 있으면
// 그 값을 루트로 서브트리 구성 → 후위로 출력
void dfs(int mn, int mx) {
    if (idx >= (int)pre.size()) return;
    int val = pre[idx];
    if (val < mn || val > mx) return;

    // 이 값을 루트로 사용
    idx++;
    // 왼쪽 서브트리: 값 범위 [mn, val)
    dfs(mn, val);
    // 오른쪽 서브트리: 값 범위 (val, mx]
    dfs(val, mx);
    // 후위 출력
    cout << val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x) {
        pre.push_back(x);
    }
    dfs(INT_MIN, INT_MAX);
    return 0;
}
*/