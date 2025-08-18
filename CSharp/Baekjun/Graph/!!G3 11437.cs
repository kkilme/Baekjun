// 2025-08-03 LCA
// 그래프 이론 / 트리 / 최소 공통 조상 (LCA)
using System.Text;

class P11437
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
    static StringBuilder sb = new StringBuilder();

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        List<int>[] adj = new List<int>[n + 1];
        for (int i = 0; i <= n; i++) adj[i] = new();
        int[] parent = new int[n + 1];
        int[] height = new int[n + 1];
        for (int i = 0; i < n-1; i++)
        {
            var line = sr.ReadLine().Split();
            int u = int.Parse(line[0]);
            int v = int.Parse(line[1]);

            adj[u].Add(v);
            adj[v].Add(u);
        }

        bool[] visited = new bool[n + 1];
        void maketree(int u, int h)
        {
            visited[u] = true;
            height[u] = h;
            foreach (var v in adj[u])
            {
                if (!visited[v])
                {
                    parent[v] = u;
                    maketree(v, h + 1);
                }
            }
        }
        parent[1] = -1;
        maketree(1, 1);


        int m = int.Parse(sr.ReadLine());
        for (int i = 0; i < m; i++)
        {
            var line = sr.ReadLine().Split();
            int u = int.Parse(line[0]);
            int v = int.Parse(line[1]);

            if (height[u] > height[v]) (v, u) = (u, v);
            while (height[u] != height[v]) v = parent[v];

            if (v == u)
            {
                sb.Append($"{v}\n");
                continue;
            }

            while (parent[u] != parent[v])
            {
                u = parent[u]; v = parent[v];
            }

            sb.Append($"{parent[u]}\n");
            
        }

        sw.Write(sb.ToString());
        sw.Flush();
        sw.Close();
    }
}