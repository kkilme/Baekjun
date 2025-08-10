// 2025-08-11 성곽
// 그래프 이론 / 그래프 탐색 / BFS / 비트마스킹 / 격자 그래프
class P2234
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static int[,] dirs = new int[4, 2] { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };

    static void _Main()
    {
        var l1 = sr.ReadLine().Split();
        int n = int.Parse(l1[0]);
        int m = int.Parse(l1[1]);

        int[][] castle = new int[m][];
        for (int i = 0; i < m; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            castle[i] = line;
        }

        List<int> sizes = new();

        bool[,] visited = new bool[m, n];
        int[,] territory = new int[m, n];

        int num = 0;
        List<HashSet<int>> neighbors = new();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i, j])
                {
                    neighbors.Add(new());
                    sizes.Add(bfs(i, j));
                    num++;
                }
            }
        }

        int bfs(int sr, int sc, bool flag = false)
        {
            int rooms = 1;

            Queue<(int r, int c)> q = new();

            q.Enqueue((sr, sc));
            visited[sr, sc] = true;
            if(!flag) territory[sr, sc] = num;

            while (q.Count != 0)
            {
                (int r, int c) = q.Dequeue();

                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dirs[i, 0];
                    int nc = c + dirs[i, 1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (flag && territory[r, c] != territory[nr, nc]) neighbors[num].Add(territory[nr, nc]);
                    if (((1 << i) & castle[r][c]) != 0) continue;
                    if (!visited[nr, nc])
                    {
                        visited[nr, nc] = true;
                        if(!flag) territory[nr, nc] = num;
                        rooms++;
                        q.Enqueue((nr, nc));
                    }
                }
            }

            return rooms;
        }

        num = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i, j] = false;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i, j])
                {
                    bfs(i, j, true);
                    num++;
                }
            }
        }
                
        int maxMergedSize = 0;
        for (int i = 0; i < sizes.Count; i++)
        {
            var nl = neighbors[i].ToList();
            for (int j = 0; j < nl.Count; j++)
            {
                maxMergedSize = Math.Max(maxMergedSize, sizes[i] + sizes[nl[j]]);
            }
        }

        Console.WriteLine(sizes.Count);
        Console.WriteLine(sizes.Max());
        Console.WriteLine(maxMergedSize);
    }
}