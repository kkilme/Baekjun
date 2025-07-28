// 2025-07-29 사회망 서비스(SNS)
// DP / 트리 / 트리에서의 DP
class P2533
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static int n;
    static bool[] visited;
    static List<int>[] gp;
    static int[,] dp;
    // dp[i, 0]: i가 얼리 어답터 아닐 때 서브트리에서 필요한 최소 얼리 어답터 수 = 모든 자식이 얼리 어답터여야 함 = sum(dp[child, 1])
    // dp[i, 1]: i가 얼리 어답터 일 때 서브트리에서 필요한 최소 얼리 어답터 수 = min(sum(dp[child, 1]), sum(dp[child, 0]))

    static void _Main()
    {
        n = int.Parse(sr.ReadLine());
        visited = new bool[n + 1];
        gp = new List<int>[n + 1];
        for (int i = 0; i <= n; i++)
        {
            visited[i] = false;
            gp[i] = new();
        }
        for (int i = 0; i < n - 1; i++)
        {
            var line = sr.ReadLine().Split();
            int u = int.Parse(line[0]);
            int v = int.Parse(line[1]);
            gp[u].Add(v);
            gp[v].Add(u);
        }

        dp = new int[n + 1, 2];

        solve(1);

        Console.WriteLine(Math.Min(dp[1, 0], dp[1, 1]));
    }

    static void solve(int v)
    {
        visited[v] = true;
        dp[v, 0] = 0;
        dp[v, 1] = 1;

        foreach (var u in gp[v])
        {
            if (!visited[u])
            {
                solve(u);
                dp[v, 0] += dp[u, 1];
                dp[v, 1] += Math.Min(dp[u, 0], dp[u, 1]);
            }
        }
    }
}