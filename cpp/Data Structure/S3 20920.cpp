// 2025-02-28 영단어 암기는 괴로워
// 자료 구조 / 문자열 / 정렬 / 해시를 사용한 집합과 맵 / 트리를 사용한 집합과 맵?
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> counts;

bool comp(string a, string b){
    if(counts[a] == counts[b]){
        if(a.size() == b.size()) return a < b;
        return a.size() > b.size();
    }
    return counts[a] > counts[b];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<string> words;

    for(int i = 0; i<n; i++){
        string word;
        cin >> word;
        if(word.size() < m) continue;
        if(counts[word]++ == 0)
            words.push_back(word);
    }

    sort(words.begin(), words.end(), comp);

    for(auto word : words){
        cout << word << '\n';
    }
}