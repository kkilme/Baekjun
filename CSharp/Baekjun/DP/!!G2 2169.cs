// 2025-09-08 로봇 조종하기
// DP
class P2169
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split();
        int n = int.Parse(l[0]), m = int.Parse(l[1]);
        int[,] mars = new int[n, m];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            for (int j = 0; j < m; j++)
            {
                mars[i, j] = int.Parse(line[j]);
            }
        }

        int[] dp = new int[m];
        dp[0] = mars[0, 0];
        for (int i = 1; i < m; i++)
        {
            dp[i] = dp[i - 1] + mars[0, i];
        }

        // 한 행씩 채워나감
        for (int i = 1; i < n; i++)
        {
            int[] left = new int[m];
            int[] right = new int[m];

            // 특정 위치에, 왼쪽에서 올 때 값
            left[0] = dp[0] + mars[i, 0];
            for (int j = 1; j < m; j++)
            {
                left[j] = Math.Max(dp[j], left[j - 1]) + mars[i, j];
            }

            // 특정 위치에, 오른쪽에서 올 때 값
            right[m - 1] = dp[m - 1] + mars[i, m - 1];
            for (int j = m - 2; j >= 0; j--)
            {
                right[j] = Math.Max(dp[j], right[j + 1]) + mars[i, j];
            }

            // 둘 중 큰 값이 그 위치 최종 값
            for (int j = 0; j < m; j++)
            {
                dp[j] = Math.Max(left[j], right[j]);
            }

        }

        Console.Write(dp[m - 1]);
    }
}