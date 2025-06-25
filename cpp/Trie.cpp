#include <bits/stdc++.h>
using namespace std;

// Trie 노드
struct TrieNode {
    bool isEnd;                      // 이 노드에서 단어가 끝나는지
    array<TrieNode*, 26> child;      // a-z 자식 포인터

    TrieNode() : isEnd(false) {
        child.fill(nullptr);
    }
    ~TrieNode() {
        for (auto ptr : child) 
            if (ptr) delete ptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    // 1) 단어 삽입
    void insert(const string &s) {
        TrieNode* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    // 2) 정확히 일치하는 단어가 있는지 검색
    bool search(const string &s) const {
        TrieNode* node = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (!node->child[idx]) 
                return false;
            node = node->child[idx];
        }
        return node->isEnd;
    }

    // 3) 접두사로 시작하는 단어가 있는지 검사
    bool startsWith(const string &prefix) const {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!node->child[idx]) 
                return false;
            node = node->child[idx];
        }
        return true;
    }
};

// 사용 예시
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    cout << boolalpha;
    cout << trie.search("app") << "\n";       // true
    cout << trie.search("apple") << "\n";     // true
    cout << trie.search("ap") << "\n";        // false
    cout << trie.startsWith("ap") << "\n";    // true
    cout << trie.startsWith("ba") << "\n";    // false
    return 0;
}