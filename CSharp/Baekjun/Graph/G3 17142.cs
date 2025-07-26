// 2025-07-27 연구소 3
// 그래프 이론 / 그래프 탐색 / 격자 그래프 / BFS / 브루트포스
class P17142
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static int n, m, emptyCnt, answer = int.MaxValue;
    static char[,] map;
    static List<(int r, int c)> virus = new();
    static (int r, int c)[] dirs = { (1, 0), (-1, 0), (0, 1), (0, -1) };
    static void _Main()
    {
        int[] l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        n = l[0]; m = l[1]; emptyCnt = 0;
        map = new char[n, n];
        for (int i = 0; i < n; i++)
        {
            string[] l2 = sr.ReadLine().Split();
            for (int j = 0; j < n; j++)
            {
                if (l2[j].CompareTo("2") == 0) virus.Add((i, j));
                else if (l2[j].CompareTo("0") == 0) emptyCnt++;
                map[i, j] = char.Parse(l2[j]);
            }
        }
        if (emptyCnt == 0)
        {
            Console.WriteLine(0);
            return;
        }
        bool[] s = new bool[virus.Count];
        for (int i = 0; i < virus.Count; i++) s[i] = false;
        bt(0, 0, s);
        if (answer == int.MaxValue) Console.WriteLine(-1);
        else Console.WriteLine(answer);
    }

    static void bt(int depth, int cur, bool[] selected)
    {
        if (depth == m)
        {
            bfs(selected);
            return;
        }

        for (int i = cur; i < virus.Count; i++)
        {
            if (!selected[i])
            {
                selected[i] = true;
                bt(depth + 1, i, selected);
                selected[i] = false;
            }
        }
    }

    static void bfs(bool[] selected)
    {
        char[,] mapCopy = new char[n, n];
        Array.Copy(map, mapCopy, mapCopy.Length);

        Queue<(int r, int c)> q = new();
        for (int i = 0; i < selected.Length; i++)
        {
            if (selected[i])
            {
                mapCopy[virus[i].r, virus[i].c] = '5';
                q.Enqueue(virus[i]);
            }
        }

        int t = 1;
        int empty = emptyCnt;

        while (q.Count != 0 && t < answer)
        {
            int qCount = q.Count;
            for (int i = 0; i < qCount; i++)
            {
                var cur = q.Dequeue();
                int r = cur.r;
                int c = cur.c;

                foreach (var d in dirs)
                {
                    int nr = r + d.r;
                    int nc = c + d.c;
                    if (nr < 0 || nr >= n || nc < 0 || nc >= n || map[nr, nc] == '1' || mapCopy[nr, nc] == '5') continue;

                    if (mapCopy[nr, nc] == '0') empty--;

                    mapCopy[nr, nc] = '5';
                    q.Enqueue((nr, nc));
                }
            }
            if (empty == 0)
            {
                answer = t;
                break;
            }
            t++;
        }
    }
}