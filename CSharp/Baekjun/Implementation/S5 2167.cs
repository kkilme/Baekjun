// 2025-09-25 2차원 배열의 합
// 구현 / 누적 합
using System.Text;

class P2167
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split();
        int n = int.Parse(l[0]), m = int.Parse(l[1]);

        int[,] arr = new int[n + 1, m + 1];
        for (int i = 0; i <= n; i++) arr[i, 0] = 0;
        for (int i = 0; i <= m; i++) arr[0, i] = 0;
        for (int i = 1; i <= n; i++)
        {
            var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 1; j <= m; j++)
            {
                arr[i, j] = arr[i - 1, j] + arr[i, j - 1] - arr[i - 1, j - 1] + l2[j - 1];
            }
        }

        int k = int.Parse(sr.ReadLine());
        StringBuilder sb = new();
        for (int i = 0; i < k; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            int a = line[0], b = line[1], c = line[2], d = line[3];
            sb.AppendLine((arr[c, d] - arr[c, b - 1] - arr[a - 1, d] + arr[a - 1, b - 1]).ToString());
        }

        Console.Write(sb.ToString());
    }
}