// 2025-10-12 BABBA
// DP
// 피보나치인듯
class P9625
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());

        int[,] dp = new int[46, 2];
        dp[1, 0] = 0; dp[1, 1] = 1;
        for (int i = 2; i < 46; i++)
        {
            dp[i, 0] = dp[i - 1, 1];
            dp[i, 1] = dp[i - 1, 0] + dp[i - 1, 1];
        }

        Console.Write($"{dp[n, 0]} {dp[n, 1]}");
    }
}