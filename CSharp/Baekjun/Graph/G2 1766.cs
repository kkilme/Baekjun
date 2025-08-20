// 2025-08-20 문제집
// 그래프 이론 / 위상 정렬 / 방향 비순환 그래프 / 자료 구조 / 우선순위 큐
using System.Text;

class P1766
{
    static StreamReader sr = new(Console.OpenStandardInput());
    static StringBuilder sb = new();

    static void Main()
    {
        var l = sr.ReadLine().Split();
        int n = int.Parse(l[0]), m = int.Parse(l[1]);

        int[] indegree = new int[n + 1];
        List<int>[] gp = new List<int>[n + 1];
        for (int i = 0; i <= n; i++)
        {
            indegree[i] = 0;
            gp[i] = new();
        }

        for (int i = 0; i < m; i++)
        {
            var line = sr.ReadLine().Split();
            int a = int.Parse(line[0]), b = int.Parse(line[1]);
            gp[a].Add(b);
            indegree[b]++;
        }

        PriorityQueue<int, int> pq = new();
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                pq.Enqueue(i, i);
            }
        }

        while (pq.Count != 0)
        {
            int cur = pq.Dequeue();
            sb.Append(cur).Append(' ');
            foreach (var v in gp[cur])
            {
                if (--indegree[v] == 0)
                {
                    pq.Enqueue(v, v);
                }
            }
        }

        Console.Write(sb.ToString());
    }
}