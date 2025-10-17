// 2025-10-18 로프
// 수학 / 그리디 / 정렬
class P2217
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        List<int> weights = new();
        for (int i = 0; i < n; i++)
        {
            weights.Add(int.Parse(sr.ReadLine()));
        }

        weights.Sort();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = Math.Max(ans, weights[i] * (n - i));
        }

        Console.Write(ans);
    }
}