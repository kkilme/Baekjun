// 2025-03-13 한 줄로 서기
// 구현 / 그리디 알고리즘
#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[10];
    int sorted[10] = {0,};
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i<n; i++){
        int idx = arr[i];
        while(idx<n-1){
            if(sorted[idx]){
                idx++;
                continue;
            }
            int cnt = 0;
            for(int j = idx-1; j>=0; j--){
                if(!sorted[j]) cnt++;
            }
            if(cnt >= arr[i]) break;
            else idx++;
        }
        sorted[idx] = i+1;
    }

    for(int i = 0; i<n; i++){
        cout << sorted[i] << ' ';
    }
}

/* ChatGPT
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    // 입력: 각 사람(키 1부터 n)의 앞에 있어야 하는, 자신보다 큰 사람의 수
    vector<int> counts(n);
    for(int i = 0; i < n; i++){
        cin >> counts[i]; // counts[i]는 키 (i+1)인 사람의 조건
    }
    
    // 최종 줄을 저장할 벡터 (최종 순서)
    vector<int> line;
    
    // 가장 큰 사람(키 n)부터 가장 작은 사람(키 1)까지 처리
    for (int h = n; h >= 1; h--){
        // 현재 사람의 조건: counts[h-1] (왜냐하면 인덱스는 0부터 시작)
        // line 벡터의 해당 인덱스 위치에 삽입
        line.insert(line.begin() + counts[h-1], h);
    }
    
    // 최종 줄 출력
    for (int p : line) {
        cout << p << " ";
    }
    cout << "\n";
    
    return 0;
}*/