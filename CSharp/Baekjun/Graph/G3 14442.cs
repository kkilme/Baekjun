// 2025-07-31 벽 부수고 이동하기 2
// 그래프 이론 / 그래프 탐색 / BFS / 격자 그래프
class P14442
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void Main()
    {
        var l = sr.ReadLine().Split();
        int n, m, k;
        n = int.Parse(l[0]);
        m = int.Parse(l[1]);
        k = int.Parse(l[2]);
        if (n == 1 && m == 1)
        {
            Console.Write(1);
            return;
        }
        List<string> map = new();
        for (int i = 0; i < n; i++)
        {
            map.Add(sr.ReadLine());
        }

        int[,] dirs = new int[4, 2] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        int[,] visited = new int[n, m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i, j] = int.MaxValue;
            }
        }

        Queue<(int cnt, int r, int c)> q = new();
        q.Enqueue((0, 0, 0));
        int dist = 1;
        while (q.Count != 0)
        {
            int cnt = q.Count;
            for (int i = 0; i < cnt; i++)
            {
                var cur = q.Dequeue();
                for (int j = 0; j < 4; j++)
                {
                    int nr = cur.r + dirs[j, 0];
                    int nc = cur.c + dirs[j, 1];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (nr == n - 1 && nc == m - 1)
                    {
                        Console.Write(dist + 1);
                        return;
                    }
                    if (map[nr][nc] == '1' && cur.cnt < k && visited[nr, nc] > cur.cnt + 1)
                    {
                        visited[nr, nc] = cur.cnt + 1;
                        q.Enqueue((cur.cnt + 1, nr, nc));
                    }
                    else if (map[nr][nc] == '0' && visited[nr, nc] > cur.cnt)
                    {
                        visited[nr, nc] = cur.cnt;
                        q.Enqueue((cur.cnt, nr, nc));
                    }
                }
            }
            dist++;
        }

        Console.Write(-1);
    }
}