// 2025-08-01 양팔저울
// DP / 배낭문제
class P2629
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        int[] chus = sr.ReadLine().Split().Select(int.Parse).ToArray();

        int maxSum = 0;
        foreach (int num in chus)
            maxSum += num;

        bool[] dp = new bool[maxSum + 1];
        dp[0] = true;

        foreach (int num in chus)
        {
            for (int i = maxSum; i >= num; i--)
            {
                if (dp[i - num]) dp[i] = true; // 모든 합의 경우 구하기
            }
        }

        int m = int.Parse(sr.ReadLine());
        int[] marbles = sr.ReadLine().Split().Select(int.Parse).ToArray();

        foreach (int num in marbles)
        {
            if (num > maxSum) Console.Write("N ");
            else if (dp[num]) Console.Write("Y ");
            else
            {
                bool flag = false;
                for (int i = 0; i <= maxSum - num; i++)
                {
                    if (dp[i] && dp[i + num])
                    {
                        flag = true;
                        Console.Write("Y ");
                        break;
                    }
                }
                if (!flag) Console.Write("N ");
            }
        }
    }
}