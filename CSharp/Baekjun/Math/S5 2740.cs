// 2025-09-28 행렬 곱셈
// 수학 / 구현 / 선형대수학
using System.Text;

class P2740
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void Main()
    {
        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int n = l[0], m = l[1];
        int[,] m1 = new int[n, m];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 0; j < m; j++)
            {
                m1[i, j] = line[j];
            }
        }
        var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int k = l2[1];
        int[,] m2 = new int[m, k];
        for (int i = 0; i < m; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 0; j < k; j++)
            {
                m2[i, j] = line[j];
            }
        }

        int[,] result = new int[n, k];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++) result[i, j] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                for (int p = 0; p < m; p++)
                {
                    result[i, j] += m1[i, p] * m2[p, j];
                }
            }
        }
        StringBuilder sb = new();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                sb.Append(result[i, j]).Append(' ');
            }
            sb.AppendLine();
        }
        
        Console.Write(sb.ToString());
    }
}