// 2025-07-24 게리맨더링
// 수학 / 그래프 이론 / 브루트포스 / 그래프 탐색 / 조합론 / BFS / DFS
class P17471
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static int n;
    static int[] pp;
    static List<int>[] adj;
    static int answer = int.MaxValue;

    static void _Main()
    {
        n = int.Parse(sr.ReadLine());
        pp = sr.ReadLine().Split().Select(int.Parse).ToArray();
        adj = new List<int>[n];
        for (int i = 0; i < n; i++) adj[i] = new List<int>();
        for (int i = 0; i < n; i++)
        {
            int[] line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 1; j <= line[0]; j++)
            {
                adj[i].Add(line[j] - 1);
                adj[line[j] - 1].Add(i);
            }
        }

        int block = 0;
        int block1 = 0, block2 = 0;
        bool[] visited = new bool[n];
        for (int i = 0; i < n; i++) visited[i] = false;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int sum = bfs(i, ref block, visited);
                if (block == 1) block1 = sum;
                else if (block == 2) block2 = sum;
            }
        }

        if (block >= 3)
        {
            Console.WriteLine(-1);
            return;
        }
        else if (block == 2)
        {
            Console.WriteLine(Math.Abs(block1 - block2));
            return;
        }

        for (int i = 0; i < n; i++) visited[i] = false;
        for (int i = 1; i < n; i++)
        {
            backtrack(i, 0, 0, 0, visited);
        }

        Console.WriteLine(answer);
    }

    static void backtrack(int maxdepth, int curdepth, int cursum, int cur, bool[] visited)
    {
        if (curdepth == maxdepth)
        {
            bool[] vcopy = new bool[n];
            for (int i = 0; i < n; i++) vcopy[i] = !visited[i];
            int block = -1;
            bfs(cur, ref block, vcopy);
            for (int i = 0; i < n; i++)
            {
                if (!vcopy[i]) return;
            }
            int sum = 0;
            visited.CopyTo(vcopy, 0);
            for (int i = 0; i < n; i++)
            {
                if (!vcopy[i])
                {
                    sum = bfs(i, ref block, vcopy);
                }
            }
            if (block > 1) return;
            answer = Math.Min(answer, Math.Abs(sum - cursum));
            return;
        }

        for (int i = cur; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                backtrack(maxdepth, curdepth + 1, cursum + pp[i], i, visited);
                visited[i] = false;
            }
        }
    }

    static int bfs(int i, ref int block, bool[] visited)
    {
        block++;
        int sum = pp[i];
        Queue<int> q = new();
        q.Enqueue(i);
        visited[i] = true;
        while (q.Count != 0)
        {
            int cur = q.Dequeue();
            foreach (int v in adj[cur])
            {
                if (!visited[v])
                {
                    sum += pp[v];
                    visited[v] = true;
                    q.Enqueue(v);
                }
            }
        }
        return sum;
    }
}