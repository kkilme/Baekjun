// 2025-08-04 소문난 칠공주
// 수학? / 그래프 이론 / 브루트포스 / 그래프 탐색 / 조합론 / BFS / 백트래킹
class P1941
{
    static int[,] dirs = new int[4, 2] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    static void _Main()
    {
        string[] classroom = new string[5];
        for (int i = 0; i < 5; i++)
        {
            classroom[i] = Console.ReadLine().Trim();
        }

        int answer = 0;
        bool[] selected = new bool[25];
        bool[,] visited = new bool[5, 5];

        void bt(int depth, int idx, int y)
        {
            if (y == 4) return;
            if (depth == 7)
            {
                if (bfs()) answer++;
                return;
            }

            if (idx >= 25 || idx + (7 - depth) >= 25) return;

            for (int i = idx; i < 25; i++)
            {
                if (!selected[i])
                {
                    selected[i] = true;
                    bt(depth + 1, i, y + (classroom[i / 5][i % 5] == 'Y' ? 1 : 0));
                    selected[i] = false;
                }
            }
        }

        bool bfs()
        {
            Queue<int> q = new();
            bool[,] visited = new bool[5, 5];

            for (int i = 0; i < 25; i++)
            {
                if (selected[i])
                {
                    q.Enqueue(i);
                    visited[i / 5, i % 5] = true;
                    break;
                }
            }

            int cnt = 1;

            while (q.Count != 0 && cnt < 7)
            {
                var cur = q.Dequeue();
                int r = cur / 5;
                int c = cur % 5;

                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dirs[i, 0];
                    int nc = c + dirs[i, 1];
                    if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                    if (visited[nr, nc] || !selected[nr * 5 + nc]) continue;
                    visited[nr, nc] = true;
                    q.Enqueue(nr * 5 + nc);
                    cnt++;
                }
            }

            return cnt == 7;
        }

        bt(0, 0, 0);

        Console.Write(answer);
    }
}