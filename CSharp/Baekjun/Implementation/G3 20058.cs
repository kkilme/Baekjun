// 2025-08-12 마법사 상어와 파이어스톰
// 구현 / 그래프 이론 / 그래프 탐색 / 시뮬레이션 / BFS / DFS
class P20058
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static int n;
    static int[,] A;
    static int[] pows = new int[7] { 1, 2, 4, 8, 16, 32, 64 };
    static void _Main()
    {
        var l1 = sr.ReadLine().Split();
        n = int.Parse(l1[0]);
        int sz = pows[n];
        A = new int[sz, sz];
        for (int i = 0; i < sz; i++)
        {
            var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 0; j < sz; j++)
            {
                A[i, j] = l2[j];
            }
        }

        var Ls = sr.ReadLine().Split().Select(int.Parse).ToArray();

        var dirs = new int[,] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        foreach (var l in Ls)
        {
            RotateAll(l);
            int[,] Acopy = (int[,])A.Clone();
            for (int i = 0; i < sz; i++)
            {
                for (int j = 0; j < sz; j++)
                {
                    if (A[i, j] == 0) continue;
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nr = i + dirs[k, 0];
                        int nc = j + dirs[k, 1];
                        if (nr < 0 || nr >= sz || nc < 0 || nc >= sz) continue;
                        if (A[nr, nc] == 0) continue;
                        cnt++;
                    }

                    if (cnt < 3) Acopy[i, j]--;
                }
            }

            A = Acopy;
        }
        int ans1 = 0;
        int ans2 = 0;

        bool[,] visited = new bool[sz, sz];

        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                ans1 += A[i, j];
                if (!visited[i, j] && A[i, j] != 0) ans2 = Math.Max(ans2, bfs(i, j));
            }
        }

        Console.Write($"{ans1}\n{ans2}");

        int bfs(int r, int c)
        {
            int cnt = 1;

            Queue<(int, int)> q = new();
            q.Enqueue((r, c));
            visited[r, c] = true;

            while (q.Count != 0)
            {
                (int curr, int curc) = q.Dequeue();

                for (int k = 0; k < 4; k++)
                {
                    int nr = curr + dirs[k, 0];
                    int nc = curc + dirs[k, 1];
                    if (nr < 0 || nr >= sz || nc < 0 || nc >= sz) continue;
                    if (visited[nr, nc] || A[nr, nc] == 0) continue;
                    q.Enqueue((nr, nc));
                    visited[nr, nc] = true;
                    cnt++;
                }
            }

            return cnt;
        }
    }

    static void RotateAll(int l)
    {
        int size = pows[l];

        void RotateBlock(int r, int c)
        {
            for (int pd = 0; pd < size / 2; pd++)
            {
                int sR = r + pd;
                int sC = c + pd;
                int eR = r + size - pd;
                int eC = c + size - pd;
                List<int> tmp = new((size - pd * 2) * 4);
                for (int i = sR + 1; i < eR; i++) tmp.Add(A[i, sC]);
                for (int i = sC + 1; i < eC; i++) tmp.Add(A[eR - 1, i]);
                for (int i = eR - 2; i >= sR; i--) tmp.Add(A[i, eC - 1]);
                for (int i = eC - 2; i >= sC; i--) tmp.Add(A[sR, i]);

                int cnt = tmp.Count;
                int j = 0;
                for (int i = sR + 1; i < eR; i++) A[i, sC] = tmp[(j++ + cnt + (size - pd * 2 - 1)) % cnt];
                for (int i = sC + 1; i < eC; i++) A[eR - 1, i] = tmp[(j++ + cnt + (size - pd * 2 - 1)) % cnt];
                for (int i = eR - 2; i >= sR; i--) A[i, eC - 1] = tmp[(j++ + cnt + (size - pd * 2 - 1)) % cnt];
                for (int i = eC - 2; i >= sC; i--) A[sR, i] = tmp[(j++ + cnt + (size - pd * 2 - 1)) % cnt];
            }
        }

        for (int i = 0; i < pows[n]; i += size)
        {
            for (int j = 0; j < pows[n]; j += size)
            {
                RotateBlock(i, j);
            }
        }
    }
}