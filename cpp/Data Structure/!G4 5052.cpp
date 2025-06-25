// 2025-06-25 전화번호 목록
// 문자열 / 정렬 / 자료 구조? / 트리? / 트라이? / 집합과 맵?
// 트라이 없이도 풀 수 있었지만 알아가는 계기가 됨.
#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        bool flag = false;
        for(int i = 0; i<n-1; i++){
            string cur = v[i];
            string nxt = v[i+1];
            flag = true;
            for(int j = 0; j<cur.size(); j++){
                if(cur[j] != nxt[j]){
                    flag = false;
                    break;
                }
            }
            /*
            // a[i] 가 a[i+1]의 접두어인지 검사
            if(a[i+1].compare(0, a[i].size(), a[i]) == 0) {
                flag = false;
                break;
            }
            */
            if(flag){
                cout << "NO\n";
                break;
            }
        }
        if(!flag) cout << "YES\n";
    }
}

/* 트라이 풀이
struct TrieNode {
    bool isEnd = false;
    TrieNode* child[10] = { nullptr };
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    // 삽입 함수: 번호 num을 삽입하면서 일관성 깨지는지 체크
    // 깨지면 false, 아니면 true
    bool insert_and_check(const string& num) {
        TrieNode* node = root;
        for (int i = 0; i < num.size(); ++i) {
            int d = num[i] - '0';
            // 1) 삽입 도중 이미 isEnd인 노드가 있으면
            //    기존 번호가 지금 삽입 중인 번호의 접두사
            if (node->isEnd) 
                return false;

            // 자식이 없으면 새로 생성
            if (!node->child[d]) 
                node->child[d] = new TrieNode();
            node = node->child[d];
        }
        // 2) 삽입 완료 지점에 자식이 있으면
        //    지금 삽입한 번호가 기존 번호의 접두사
        for (int d = 0; d < 10; ++d) {
            if (node->child[d]) 
                return false;
        }
        // 끝 표시가 중복되진 않으니 바로 isEnd = true
        node->isEnd = true;
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> phones(n);
        for (int i = 0; i < n; i++) 
            cin >> phones[i];

        Trie trie;
        bool ok = true;
        // 삽입 순서는 정렬 안 해도 되지만,
        // 짧은 번호가 먼저 들어가면 1) 검사에 더 빨리 걸리므로 약간 이득
        sort(phones.begin(), phones.end(), 
            [](auto &a, auto &b){
                return a.size() < b.size();
            });

        for (auto &num : phones) {
            if (!trie.insert_and_check(num)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
*/