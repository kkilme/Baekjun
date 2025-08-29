// 2025-08-28 벽 부수고 이동하기 4
// 그래프 이론 / 그래프 탐색 / BFS / DFS
// StringBuilder를 안써서 시간초과로 1시간을 허비한 문제
using System.Text;

class P16946
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static string[] map;
    static int[,] group;
    static List<int> cnts = new();
    static void _Main()
    {
        var l = sr.ReadLine().Split();
        int n = int.Parse(l[0]), m = int.Parse(l[1]);

        map = new string[n];
        group = new int[n, m];
        int[,] answer = new int[n, m];
        for (int i = 0; i < n; i++)
        {
            map[i] = sr.ReadLine();
            for (int j = 0; j < m; j++)
            {
                group[i, j] = -1;
                answer[i, j] = 0;
            }
        }

        int[,] dirs = new int[4, 2] { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        bool[,] visited = new bool[n, m];
        int gnum = 0;

        void bfs(int r, int c, int groupnum)
        {
            int cnt = 0;

            Queue<(int, int)> q = new();
            visited[r, c] = true;
            q.Enqueue((r, c));

            while (q.Count != 0)
            {
                var (cr, cc) = q.Dequeue();
                group[cr, cc] = groupnum;
                cnt++;
                for (int i = 0; i < 4; i++)
                {
                    int nr = cr + dirs[i, 0];
                    int nc = cc + dirs[i, 1];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (map[nr][nc] == '1' || visited[nr, nc]) continue;
                    visited[nr, nc] = true;
                    q.Enqueue((nr, nc));
                }
            }

            cnts.Add(cnt);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == '0' && !visited[i, j]) bfs(i, j, gnum++);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == '0') continue;
                HashSet<int> groups = new();
                for (int k = 0; k < 4; k++)
                {
                    int nr = i + dirs[k, 0];
                    int nc = j + dirs[k, 1];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (group[nr, nc] == -1) continue;
                    if (groups.Add(group[nr, nc])) answer[i, j] += cnts[group[nr, nc]];
                }

                answer[i, j]++;
                answer[i, j] %= 10;
            }
        }

        StringBuilder sb = new();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sb.Append(answer[i, j]);
            }
            sb.AppendLine();
        }

        Console.Write(sb.ToString());
    }
}