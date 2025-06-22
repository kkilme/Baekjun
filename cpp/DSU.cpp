#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Disjoint Set Union (혹은 Union–Find)
struct DSU {
    vector<int> p, r;
    DSU(int n): p(n+1), r(n+1,0){ iota(p.begin(), p.end(), 0); }

    int find(int x){ 
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a,int b){
        a = find(a); 
        b = find(b);
        if(a==b) return false;

        if(r[a]<r[b]) swap(a,b);

        p[b]=a;

        if(r[a]==r[b]) r[a]++;

        return true;
    }
};

struct DSU {
    vector<int> p, r;
    
    // 생성자: 크기가 n인 DSU를 만든다.
    // p  : 부모 노드(parent) 정보
    // r  : 랭크(rank) 혹은 트리 높이 근사 정보
    DSU(int n)
      : p(n+1),             // 0번부터 n번까지 총 n+1개 공간 준비
        r(n+1, 0)           // 모두 0으로 초기화
    {
        // iota는 <numeric>에 있는 함수로,
        // p[0]=0, p[1]=1, …, p[n]=n  로 채워준다.
        // 즉, 처음엔 각 원소가 자기 자신을 부모로 삼는다.
        iota(p.begin(), p.end(), 0);
    }

    // find(x): x가 속한 집합의 “대표(root)”를 찾는다.
    // 경로 압축(path compression)을 함께 적용하여
    // 호출할 때마다 트리를 얕게(=빠르게) 만든다.
    int find(int x) {
        // p[x]==x 이면 x가 트리의 루트 → 그냥 x 반환
        // 아니면 재귀로 find(p[x]) 호출해서 최종 루트를 찾고,
        // 그 결과를 p[x]에 바로 저장(=path compression)
        return p[x] == x
             ? x
             : (p[x] = find(p[x]));
    }

    // unite(a,b): a와 b를 같은 집합으로 합친다.
    // 두 집합이 이미 같았다면 false, 새로 합쳐졌다면 true를 반환.
    bool unite(int a, int b) {
        // 1) 각각의 루트(대표)를 찾는다
        a = find(a);
        b = find(b);
        // 2) 이미 같은 루트면(이미 같은 집합) 합칠 필요가 없다
        if (a == b) return false;

        // 3) 랭크(rank)를 비교하여, 높이가 작은 쪽을 큰 쪽 밑으로 단다
        //    이렇게 하면 트리의 최대 높이를 억제할 수 있다.
        if (r[a] < r[b]) 
            swap(a, b);

        // 4) b의 루트를 a로 연결
        p[b] = a;

        // 5) 만약 두 랭크가 같았다면, 합친 뒤 a의 랭크를 1 올린다
        if (r[a] == r[b]) 
            r[a]++;

        return true;
    }
};

/*usage(Krusukal)
DSU dsu(V);
ll total = 0;
int cnt = 0;
for(auto &e : edges){
    if(dsu.unite(e.u, e.v)){
        total += e.w;
        cnt++;
        if(cnt == V-1) break;
    }
}
*/