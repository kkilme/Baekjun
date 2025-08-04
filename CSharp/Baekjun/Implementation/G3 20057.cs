// 2025-08-04 마법사 상어와 토네이도
// 구현 / 시뮬레이션
class P20057
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        int[,] board = new int[n, n];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            for (int j = 0; j < n; j++)
            {
                board[i, j] = int.Parse(line[j]);
            }
        }

        List<Dictionary<(int dr, int dc), float>> dict = new()
        {
            new()
            {
                {(-2, 0), .05f},
                {(-1, -1), .1f},
                {(-1, 1), .1f},
                {(0, -1), .07f},
                {(0, 1), .07f},
                {(0, -2), .02f},
                {(0, 2), .02f},
                {(1, -1), .01f},
                {(1, 1), .01f}
            }
        };
        int[][] dirs = new int[4][] { new int[2] { -1, 0 }, new int[2] { 0, 1 }, new int[2] { 1, 0 }, new int[2] { 0, -1 } };
        int[] cos = new int[3] { 0, -1, 0 };
        int[] sin = new int[3] { -1, 0, 1 };
        for (int i = 1; i <= 3; i++)
        {
            dict.Add(new());
            foreach (var kvp in dict[0])
            {
                int x = kvp.Key.dc;
                int y = kvp.Key.dr;
                int nx = x * cos[i - 1] + y * sin[i - 1];
                int ny = y * cos[i - 1] - x * sin[i - 1];

                dict[i].Add((ny, nx), kvp.Value);
            }
        }

        int dir = 3;
        int r = n / 2, c = n / 2;
        int len = 1;
        int curlen = 0;
        bool flag = false;
        void getNext(int r, int c, out int nr, out int nc)
        {
            if (curlen == len)
            {
                if (flag)
                {
                    len++;
                    flag = false;
                }
                else
                {
                    flag = true;
                }
                curlen = 0;
                dir = (dir + 3) % 4;
            }
            nr = r + dirs[dir][0];
            nc = c + dirs[dir][1];
            curlen++;
        }

        int answer = 0;

        while (r != 0 || c != 0)
        {
            getNext(r, c, out int nr, out int nc);

            int cur = board[nr, nc];
            int left = cur;
            int nnr, nnc;
            foreach (var kvp in dict[dir])
            {
                nnr = nr + kvp.Key.dr;
                nnc = nc + kvp.Key.dc;
                int removing = (int)(cur * kvp.Value);

                if (nnr < 0 || nnr >= n || nnc < 0 || nnc >= n)
                {
                    answer += removing;
                }
                else
                {
                    board[nnr, nnc] += removing;
                }
                left -= removing;
            }

            nnr = nr + dirs[dir][0];
            nnc = nc + dirs[dir][1];
            if (nnr < 0 || nnr >= n || nnc < 0 || nnc >= n)
            {
                answer += left;
            }
            else
            {
                board[nnr, nnc] += left;
            }
            board[nr, nc] = 0;

            r = nr; c = nc;
        }

        Console.Write(answer);
    }
}
