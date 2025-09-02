// 2025-09-03 스타트 택시
// 구현 / 그래프 이론 / 그래프 탐색 / 시뮬레이션 / BFS / 격자 그래프
class P19328
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int n = l[0], m = l[1], fuel = l[2];
        bool[,] map = new bool[n, n];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            for (int j = 0; j < n; j++)
            {
                if (line[j] == "1") map[i, j] = true;
                else map[i, j] = false;
            }
        }

        int[,] dirs = new int[4, 2] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

        int bfs((int r, int c) start, (int r, int c) target, int cut = int.MaxValue)
        {
            if (start == target) return 0;
            int dist = 0;
            bool[,] visited = new bool[n, n];
            visited[start.r, start.c] = true;

            Queue<(int r, int c)> q = new();
            q.Enqueue((start.r, start.c));

            while (q.Count != 0)
            {
                int qCount = q.Count;
                dist++;
                if (dist > cut) return -1;
                while (qCount-- > 0)
                {
                    var (r, c) = q.Dequeue();

                    for (int i = 0; i < 4; i++)
                    {
                        int nr = r + dirs[i, 0];
                        int nc = c + dirs[i, 1];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                        if (visited[nr, nc] || map[nr, nc]) continue;
                        if (nr == target.r && nc == target.c)
                        {
                            return dist;
                        }

                        visited[nr, nc] = true;
                        q.Enqueue((nr, nc));
                    }
                }
            }
            return int.MaxValue;
        }

        var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int taxir = l2[0] - 1, taxic = l2[1] - 1;

        HashSet<((int r, int c) start, (int r, int c) dest)> customers = new();

        for (int i = 0; i < m; i++)
        {
            var l3 = sr.ReadLine().Split().Select(int.Parse).ToArray();
            customers.Add(((l3[0] - 1, l3[1] - 1), (l3[2] - 1, l3[3] - 1)));
        }

        while (customers.Count != 0 && fuel > 0)
        {
            var target = customers.ElementAt(0);
            int minDist = int.MaxValue;
            foreach (var customer in customers)
            {
                var dist = bfs((taxir, taxic), customer.start, minDist);
                if (dist != -1)
                {
                    if (dist == minDist)
                    {
                        if (target.start.r == customer.start.r)
                        {
                            if (target.start.c > customer.start.c) target = customer;
                        }
                        else if (target.start.r > customer.start.r) target = customer;
                    }
                    else
                    {
                        minDist = dist;
                        target = customer;
                    }
                }
            }

            fuel -= minDist;
            if (fuel <= 0) break;

            int d = bfs(target.start, target.dest);

            fuel -= d;
            if (fuel < 0) break;

            fuel += 2 * d;
            taxir = target.dest.r; taxic = target.dest.c;
            customers.Remove(target);

        }

        if (customers.Count > 0) Console.WriteLine(-1);
        else Console.Write(fuel);

    }
}