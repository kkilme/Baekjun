// 2025-10-20 수들의 합 2
// 투 포인터 / 누적 합 / 브루트포스
class P2003
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var ln = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int n = ln[0], m = ln[1];

        int[] arr = sr.ReadLine().Split().Select(int.Parse).ToArray();

        int l, r;
        l = r = 0;

        int ans = 0;
        int cur = arr[0];

        while (l < n)
        {
            if (cur == m) ans++;
            if ((l == r || cur <= m) && r < n - 1)
            {
                cur += arr[++r];
            }
            else
            {
                cur -= arr[l++];
            }
        }

        Console.Write(ans);
    }
}