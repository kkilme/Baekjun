// 2025-08-16 트리의 지름
// 그래프 이론 / 그래프 탐색 / 트리 / DFS / 트리의 지름
class P1167
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        List<(int v, int w)>[] gp = new List<(int v, int w)>[n + 1];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            var u = line[0];
            gp[u] = new();
            for (int j = 1; j < line.Length - 1; j += 2)
            {
                gp[u].Add((line[j], line[j + 1]));
            }
        }

        (int v, int d) bfs(int s)
        {
            bool[] visited = new bool[n + 1];
            Queue<(int v, int d)> q = new();
            q.Enqueue((s, 0));
            visited[s] = true;

            int far = s;
            int fard = 0;

            while (q.Count != 0)
            {
                (int curv, int curd) = q.Dequeue();

                foreach ((int u, int w) in gp[curv])
                {
                    if (visited[u]) continue;
                    if (curd + w > fard)
                    {
                        fard = curd + w;
                        far = u;
                    }
                    visited[u] = true;
                    q.Enqueue((u, curd + w));
                }
            }

            return (far, fard);
        }

        (int far, int d) = bfs(1);
        (int f, int answer) = bfs(far);

        Console.Write(answer);
    }
}