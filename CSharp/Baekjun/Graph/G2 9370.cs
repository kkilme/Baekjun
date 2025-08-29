// 2025-08-29 미확인 도착지
// 그래프 이론 / 최단 경로 / 다익스트라
using System.Text;
class P9370
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static int n, m, t, s, g, h;
    static List<(int, int)>[] gp;
    static void _Main()
    {
        int T = int.Parse(sr.ReadLine());
        StringBuilder sb = new();
        while (T-- > 0)
        {
            var l1 = sr.ReadLine().Split().Select(int.Parse).ToArray();
            var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();
            n = l1[0]; m = l1[1]; t = l1[2]; s = l2[0]; g = l2[1]; h = l2[2];

            gp = new List<(int, int)>[n + 1];
            for (int i = 0; i <= n; i++) gp[i] = new();

            int gh = 0;
            for (int i = 0; i < m; i++)
            {
                var l3 = sr.ReadLine().Split();
                int a = int.Parse(l3[0]), b = int.Parse(l3[1]), d = int.Parse(l3[2]);

                gp[a].Add((b, d));
                gp[b].Add((a, d));
                if ((a == g && b == h) || (a == h && b == g)) gh = d;
            }

            var dist = dijkstra(s);
            var distg = dijkstra(g);
            var disth = dijkstra(h);
            List<int> ans = new();
            for (int i = 0; i < t; i++)
            {
                int candi = int.Parse(sr.ReadLine());
                if (dist[candi] == int.MaxValue) continue;

                int path1 = dist[g] + gh + disth[candi];
                int path2 = dist[h] + gh + distg[candi];
                if (dist[candi] == path1 || dist[candi] == path2) ans.Add(candi);                
            }

            ans.Sort();

            foreach (var a in ans) sb.Append(a).Append(' ');
            sb.AppendLine();
        }

        Console.Write(sb.ToString());
        return;

        int[] dijkstra(int start)
        {
            int[] dists = new int[n + 1];
            for (int i = 0; i <= n; i++)
            {
                dists[i] = int.MaxValue;
            } 
            dists[start] = 0;

            PriorityQueue<int, int> pq = new();
            pq.Enqueue(start, 0);

            while (pq.Count != 0)
            {
                var v = pq.Dequeue();

                foreach (var (u, d) in gp[v])
                {
                    int nd = d + dists[v];
                    if (dists[u] > nd)
                    {
                        dists[u] = nd;
                        pq.Enqueue(u, nd);
                    }
                }
            }

            return dists;
        }
    }
}