// 2025-07-31 중량제한
// 그래프 이론 / 그래프 탐색 / 자료 구조? / 이분 탐색 / BFS / 최단 경로? / 다익스트라? / 분리 집합?
class P1939
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static int n, m, start, dest;
    static List<List<(int to, int d)>> gp = new();

    static void Main()
    {
        var line = sr.ReadLine().Split();
        n = int.Parse(line[0]);
        m = int.Parse(line[1]);

        for (int i = 0; i <= n; i++)
        {
            gp.Add(new());
            gp[i] = new();
        }

        int mx = 0;
        for (int i = 0; i < m; i++)
        {
            var ln = sr.ReadLine().Split();
            int a = int.Parse(ln[0]);
            int b = int.Parse(ln[1]);
            int c = int.Parse(ln[2]);
            mx = Math.Max(mx, c);
            gp[a].Add((b, c));
            gp[b].Add((a, c));

        }

        var l2 = sr.ReadLine().Split();
        start = int.Parse(l2[0]);
        dest = int.Parse(l2[1]);


        int l = 1, h = mx;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (bst(mid))
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        Console.WriteLine(l - 1);
    }

    static bool bst(int limit)
    {
        Queue<int> q = new();
        bool[] visited = new bool[n + 1];
        for (int i = 0; i <= n; i++) visited[i] = false;
        visited[start] = true;
        q.Enqueue(start);

        while (q.Count != 0)
        {
            int cur = q.Dequeue();
            foreach (var (to, d) in gp[cur])
            {
                if (!visited[to] && d >= limit)
                {
                    if (to == dest) return true;
                    visited[to] = true;
                    q.Enqueue(to);
                }
            }
        }

        return false;
    }
}