// 2025-08-27 색종이 붙이기
// 브루트포스 / 백트래킹
// dp는 안 써도 됐을듯.. 더 나은 풀이가 있지 않을까
class P17136
{
    static StreamReader sr = new(Console.OpenStandardInput());
    static List<(int, (int, int))> l = new();
    static bool[,] paper = new bool[10, 10];
    static bool[,] covered = new bool[10, 10];
    static int[,] dp = new int[10, 10];

    static void _Main()
    {
        for (int i = 0; i < 10; i++)
        {
            var line = sr.ReadLine().Split();
            for (int j = 0; j < 10; j++)
            {
                paper[i, j] = int.Parse(line[j]) == 1;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if ((i == 0 || j == 0) && paper[i, j])
                {
                    dp[i, j] = 1;
                    l.Add((dp[i, j], (i, j)));
                }
                else dp[i, j] = 0;
                covered[i, j] = false;
            }
        }

        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                if (paper[i, j])
                {
                    dp[i, j] = Math.Min(Math.Min(dp[i - 1, j], dp[i, j - 1]), dp[i - 1, j - 1]) + 1;
                    l.Add((dp[i, j], (i, j)));
                }
            }
        }
        l.Sort((a, b) =>
        {
            if (a.Item1 == b.Item1)
            {
                if (a.Item2.Item1 == b.Item2.Item1) return b.Item2.Item2.CompareTo(a.Item2.Item2);
                return b.Item2.Item1.CompareTo(a.Item2.Item1);
            }
            return b.Item1.CompareTo(a.Item1);
        });

        bt(0);

        Console.Write(answer == int.MaxValue ? -1 : answer);
    }

    static int answer = int.MaxValue;
    static int[] cpapers = new int[6] { 0, 5, 5, 5, 5, 5 };

    static (int, int) findnext()
    {
        for (int i = 0; i < l.Count; i++)
        {
            var (r, c) = l[i].Item2;
            if (!covered[r, c] && paper[r, c]) return (r, c);
        }
        return (-1, -1);
    }

    static void bt(int cnt)
    {
        if (cnt >= answer) return;

        var (r, c) = findnext();
        if (r == -1)
        {
            answer = cnt;
            return;
        }

        var sz = Math.Min(dp[r, c], 5);
        for (int s = sz; s >= 1; s--)
        {
            if (cpapers[s] == 0) continue;

            bool flag = false;
            for (int j = r; j >= r - s + 1 && !flag; j--)
            {
                for (int k = c; k >= c - s + 1; k--)
                {
                    if (covered[j, k])
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) continue;
            for (int j = r; j >= r - s + 1; j--)
            {
                for (int k = c; k >= c - s + 1; k--)
                {
                    covered[j, k] = true;
                }
            }
            cpapers[s]--;
            bt(cnt + 1);
            cpapers[s]++;
            for (int j = r; j >= r - s + 1; j--)
            {
                for (int k = c; k >= c - s + 1; k--)
                {
                    covered[j, k] = false;
                }
            }
        }
    }
}