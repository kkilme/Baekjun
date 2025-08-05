// 2025-08-05 우주신과의 교감
// 그래프 이론 / 최소 스패닝 트리
class P1774
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static int[] parents;

    struct Edge
    {
        public int u, v;
        public double w;

        public Edge(int u, int v, double w)
        {
            this.u = u;
            this.v = v;
            this.w = w;
        }
    }

    static void _Main()
    {
        var line = sr.ReadLine().Split();
        int n = int.Parse(line[0]);
        int m = int.Parse(line[1]);

        parents = new int[n + 1];
        (double x, double y)[] pos = new (double, double)[n + 1];
        List<int>[] gp = new List<int>[n + 1];
        gp[0] = new();

        for (int i = 1; i <= n; i++)
        {
            line = sr.ReadLine().Split();
            pos[i] = (double.Parse(line[0]), double.Parse(line[1]));
            parents[i] = i;
            gp[i] = new();
        }


        for (int i = 0; i < m; i++)
        {
            line = sr.ReadLine().Split();
            int u = int.Parse(line[0]);
            int v = int.Parse(line[1]);
            union(u, v);
            gp[u].Add(v);
            gp[v].Add(u);
        }

        List<Edge> edges = new();
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (find(i) == find(j)) continue;
                edges.Add(new(i, j, Math.Sqrt(Math.Pow(pos[i].x - pos[j].x, 2) + Math.Pow(pos[i].y - pos[j].y, 2))));
            }
        }

        edges.Sort((e1, e2) => { return e1.w.CompareTo(e2.w); });

        double answer = 0;
        foreach (var e in edges)
        {
            if (union(e.u, e.v))
            {
                answer += e.w;
            }
        }

        Console.Write($"{answer:F2}");

    }

    static int find(int a)
    {
        return a == parents[a] ? a : parents[a] = find(parents[a]);
    }

    static bool union(int a, int b)
    {
        int ap = find(a);
        int bp = find(b);

        if (ap == bp) return false;

        parents[bp] = parents[ap];
        return true;
    }
}