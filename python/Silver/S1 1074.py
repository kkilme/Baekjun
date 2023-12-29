# Z
# 분할 정복
# 2^n * 2^n 영역을 2^n-1 * 2^n-1로 분할하며 Z자 경로
# r행 c열 방문 순서 구하기

n, r, c = map(int, input().split())
ans = 0
def find(n, sr, er, sc, ec):
    global r, c, ans
    if not(sr <= r <= er and sc <= c <= ec):
        # print(sr, er, sc, ec)
        return 2**n * 2**n
    if sr == r and sc == c and er == r and ec == c:
        print(ans)
    if n < 1: return 1

    ans += find(n-1, sr, sr + (2**(n-1)) - 1, sc, sc + (2**(n-1)) - 1)
    ans += find(n-1, sr, sr + (2**(n-1)) - 1, sc + 2**(n-1), ec)
    ans += find(n-1, sr + 2**(n-1), er, sc, sc + (2**(n-1)) - 1)
    ans += find(n-1, sr + 2**(n-1), er, sc + 2**(n-1), ec)
    return 0
    
find(n, 0, 2**n-1, 0, 2**n-1)
    