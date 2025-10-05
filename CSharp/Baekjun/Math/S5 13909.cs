// 2025-10-05 창문 닫기
// 수학 / 정수론
class P13909
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());

        int ans = 0;
        int di = 3;
        for (int i = 1; i <= n; i += di, di += 2) ans++;

        Console.Write(ans);
        // == (int)sqrt(n)
    }
}

// 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 ...
// 0이 0, 2, 4, 6...개 이후 1
// 1 4 9 16 25 36...번째에 1
// 제곱수(== 약수가 홀수개)에 1