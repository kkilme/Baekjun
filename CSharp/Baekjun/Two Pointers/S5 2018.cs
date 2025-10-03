// 2025-10-03 수들의 합 5
// 수학 / 투 포인터
class P2018
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());

        int ans = 0;
        int cur = 1;
        int l = 1, r = 1;
        while (l <= r && r <= n)
        {
            if (cur == n) ans++;
            if (cur < n) cur += ++r;
            else cur -= l++;
        }
        Console.Write(ans);
    }
}