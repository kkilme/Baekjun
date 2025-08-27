// 2025-08-24 빵집
// 그리디 / 그래프 이론 / 그래프 탐색 / DFS / 격자 그래프
class P3109
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var rc = sr.ReadLine().Split();
        int r = int.Parse(rc[0]);
        int c = int.Parse(rc[1]);

        string[] map = new string[r];
        for (int i = 0; i < r; i++)
        {
            map[i] = sr.ReadLine();
        }

        bool[,] visited = new bool[r, c];
        int[] dirs = new int[3] { -1, 0, 1 };
        int cnt = 0;

        bool dfs(int rr, int cc)
        {
            if (cc == c - 1) return true;
            foreach (var d in dirs)
            {
                int nr = rr + d;
                int nc = cc + 1;
                if (nr < 0 || nr >= r) continue;
                if (visited[nr, nc] || map[nr][nc] == 'x') continue;
                visited[nr, nc] = true;
                if (dfs(nr, nc)) return true;
            }
            return false;
        }
        for (int i = 0; i < r; i++)
        {
            if (dfs(i, 0)) cnt++;
        }
        Console.Write(cnt);
    }
}