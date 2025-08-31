// 2025-09-01 원판 돌리기
// 구현 / 시뮬레이션
class P17822
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static int n, m, t, alivecnt;
    static int[,] boards = new int[n, m];
    static bool[,] alive = new bool[n, m];
    static void _Main()
    {
        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        n = l[0]; m = l[1]; t = l[2];
        boards = new int[n, m];
        alive = new bool[n, m];
        alivecnt = n * m;

        for (int i = 0; i < n; i++)
        {
            var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 0; j < m; j++)
            {
                boards[i, j] = l2[j];
                alive[i, j] = true;
            }
        }

        while (t-- > 0)
        {
            var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();
            int x = l2[0], d = l2[1], k = l2[2];

            for (int i = x; i <= n; i += x)
            {
                rotate(i - 1, d, k);
            }
            erase();
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!alive[i, j]) continue;
                sum += boards[i, j];
            }
        }

        Console.Write(sum);

        return;

        void rotate(int x, int d, int k)
        {
            if (d == 0) k = m - k;

            List<int> b = new(m);
            List<bool> a = new(m);

            for (int i = 0; i < m; i++)
            {
                b.Add(boards[x, i]);
                a.Add(alive[x, i]);
            }
            for (int i = 0; i < m; i++)
            {
                boards[x, i] = b[(i + k) % m];
                alive[x, i] = a[(i + k) % m];
            }
        }

        void erase()
        {
            bool flag = false;
            int sum = 0;
            int cnt = 0;
            bool[,] alive2 = new bool[n, m];
            Array.Copy(alive, alive2, n * m);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (!alive2[i, j]) continue;
                    sum += boards[i, j];
                    cnt++;
                    int t1 = j - 1, t2 = j + 1, t3 = i - 1, t4 = i + 1;
                    if (j == 0) t1 = m - 1;
                    else if (j == m - 1) t2 = 0;

                    if (boards[i, j] == boards[i, t1] && alive2[i, t1])
                    {
                        flag = true;
                        alive[i, t1] = false;
                        alive[i, j] = false;
                    }

                    if (boards[i, j] == boards[i, t2] && alive2[i, t2])
                    {
                        flag = true;
                        alive[i, t2] = false;
                        alive[i, j] = false;
                    }

                    if (t3 >= 0 && boards[i, j] == boards[t3, j] && alive2[t3, j])
                    {
                        flag = true;
                        alive[t3, j] = false;
                        alive[i, j] = false;
                    }
                    if (t4 < n && boards[i, j] == boards[t4, j] && alive2[t4, j])
                    {
                        flag = true;
                        alive[t4, j] = false;
                        alive[i, j] = false;
                    }
                }
            }

            if (!flag && sum > 0)
            {
                float f = (float)sum / cnt;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (!alive[i, j]) continue;
                        if (boards[i, j] < f) boards[i, j]++;
                        else if (boards[i, j] > f) boards[i, j]--;
                    }
                }
            }
        }
    }
}