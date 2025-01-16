// for fun: gpt로 풀어보기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 연산자 삽입을 위한 DFS 함수
void generateExpressions(int num, int n, string expr, vector<string>& results) {
    if (num == n) { 
        // 수식 계산을 위해 공백을 처리한 후 평가
        string eval_expr;
        int result = 0, current = 0, sign = 1;

        for (char c : expr) {
            if (c == '+') {
                result += sign * current;
                sign = 1;
                current = 0;
            } else if (c == '-') {
                result += sign * current;
                sign = -1;
                current = 0;
            } else if (c != ' ') {
                current = current * 10 + (c - '0');
            }
        }
        result += sign * current;

        if (result == 0) {
            results.push_back(expr);
        }
        return;
    }

    // 다음 숫자를 연산자로 연결하며 탐색
    generateExpressions(num + 1, n, expr + " " + to_string(num + 1), results);
    generateExpressions(num + 1, n, expr + "+" + to_string(num + 1), results);
    generateExpressions(num + 1, n, expr + "-" + to_string(num + 1), results);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<string> results;
        generateExpressions(1, N, "1", results);

        sort(results.begin(), results.end());

        for (const string& expr : results) {
            cout << expr << '\n';
        }
        cout << '\n'; // 테스트 케이스 구분을 위한 개행
    }

    return 0;
}
