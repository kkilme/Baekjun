// 2025-05-06 CCW
// 기하학
// 세 점이 이루는 방향
#include <bits/stdc++.h>
using namespace std;

// u x v = (|u||v| sinθ) n (n: u, v의 외적 방향 = u, v에 수직인 단위벡터(법선 벡터))

// u(m1, m2, m3) x v(n1, n2, n3) = (m2*n3 - m3*n2, m3*n1 - m1*n3, m1*n2 - m2*n1)
// 2D일 시 m3 = n3 = 0 이므로 u x v = (0, 0, m1*n2 - m2*n1)

// A = (x1, y1), B = (x2, y2), C = (x3, y3) 일 시
// u = (x2-x1, y2-y1), v = (x3-x1, y3-y1) -> u x v = (0, 0, (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1))

// ccw > 0: 반시계 (sinθ>0), < 0: 시계(sinθ<0), = 0: 일직선
int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1); // = x1y2 + x2y3 + x3y1 - (x1y3 + x2y1 + x3y2)
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int result = ccw(x1, y1, x2, y2, x3, y3);
    cout << (result == 0 ? 0 : (result > 0 ? 1 : -1));
}