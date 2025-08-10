// 2025-08-10 개미굴
// 자료구조 / 문자열 / 트리? / 집합과 맵? / 트라이?
using System.Text;

class P14725
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        List<List<string>> l = new();
        for (int i = 0; i < n; i++)
        {
            l.Add(new());
            var line = sr.ReadLine().Split();
            int m = int.Parse(line[0]);
            for (int j = 1; j <= m; j++)
            {
                l[i].Add(line[j]);
            }
        }

        l.Sort((a, b) =>
        {
            for (int i = 0; ; i++)
            {
                if (i >= a.Count) return 1;
                else if (i >= b.Count) return -1;
                if (a[i] != b[i]) return a[i].CompareTo(b[i]);
            }
        });

        int depth = 0;
        StringBuilder sb = new();
        for (; depth < l[0].Count; depth++)
        {
            sb.Append(new string('-', depth * 2));
            sb.AppendLine(l[0][depth]);
        }
        for (int i = 1; i < n; i++)
        {
            depth = 0;
            while (depth < l[i - 1].Count && depth < l[i].Count && l[i - 1][depth] == l[i][depth]) depth++;
            for (; depth < l[i].Count; depth++)
            {
                sb.Append(new string('-', depth * 2));
                sb.AppendLine(l[i][depth]);
            }
        }
        Console.Write(sb.ToString());
    }
}