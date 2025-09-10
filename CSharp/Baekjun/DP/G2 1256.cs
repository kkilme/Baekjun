// 2025-09-09 사전
// 수학 / DP / 조합론 / 역추적
// 이왜맞
using System.Text;
class P1256
{
    static void _Main()
    {
        var l = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = l[0], m = l[1], k = l[2];

        long[,] dp = new long[101, 101];
        dp[0, 0] = 0;
        for (int i = 1; i <= 100; i++)
        {
            dp[i, 0] = dp[0, i] = 1;
        }

        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                if (dp[i, j - 1] > 1_000_000_000 || dp[i - 1, j] > 1_000_000_000 || dp[i, j - 1] == -1 || dp[i - 1, j] == -1)
                {
                    dp[i, j] = -1;
                }
                else dp[i, j] = dp[i, j - 1] + dp[i - 1, j];
            }
        }

        if (dp[n, m] != -1 && dp[n, m] < k)
        {
            Console.Write(-1);
            return;
        }

        StringBuilder sb = new();

        void find(int a, int z, long start)
        {
            if (z == 0)
            {
                for (int i = 0; i < a; i++) sb.Append('a');
                return;
            }
            else if (a == 0)
            {
                for (int i = 0; i < z; i++) sb.Append('z');
                return;
            }
            long p = dp[a - 1, z];
            long q = dp[a, z - 1];
            if (p == -1 && q == -1)
            {
                sb.Append('a');
                find(a - 1, z, start);
                return;
            }


            if (start + p < k)
            {
                sb.Append('z');
                find(a, z - 1, start + p);
            }
            else
            {
                sb.Append('a');
                find(a - 1, z, start);
            }
        }

        find(n, m, 0);

        Console.WriteLine(sb.ToString());
    }
}
/* 
    // 조합 DP 계산
    comb = new long[N + M + 1, N + M + 1];
    for (int i = 0; i <= N + M; i++)
    {
        comb[i, 0] = comb[i, i] = 1;
        for (int j = 1; j < i; j++)
        {
            comb[i, j] = Math.Min((long)LIMIT, comb[i - 1, j - 1] + comb[i - 1, j]);
        }
    }
    while (N > 0 && M > 0)
    {
        long countA = comb[N + M - 1, N - 1]; // 'a'로 시작하는 경우의 수
        if (K <= countA)
        {
            sb.Append('a');
            N--;
        }
        else
        {
            sb.Append('z');
            K -= countA;
            M--;
        }
    }
    sb.Append(new string('a', N));
    sb.Append(new string('z', M));
*/