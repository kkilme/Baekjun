// 2025-09-08 트리의 높이와 너비
// 그래프 이론 / 그래프 탐색 / 트리 / DFS
class P2250
{
    class Node
    {
        public int num;
        public int left;
        public int right;

        public Node(int n, int l, int r)
        {
            num = n; left = l; right = r;
        }
    }
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        Node[] nodes = new Node[n];
        bool[] hasP = new bool[n];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            int num = int.Parse(line[0]) - 1;
            int l = int.Parse(line[1]), r = int.Parse(line[2]);
            if (l != -1)
            {
                l--;
                hasP[l] = true;
            }
            if (r != -1)
            {
                r--;
                hasP[r] = true;
            }
            nodes[num] = new Node(num, l, r);
        }

        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (!hasP[i]) root = i;
        }

        Dictionary<int, (int min, int max)> dict = new();

        int nextEmpty = 1;

        void dfs(int num, int depth)
        {
            if (num == -1) return;

            dfs(nodes[num].left, depth + 1);
            if (dict.ContainsKey(depth))
            {
                dict[depth] = (Math.Min(dict[depth].min, nextEmpty), Math.Max(dict[depth].max, nextEmpty));
            }
            else
            {
                dict.Add(depth, (nextEmpty, nextEmpty));
            }
            nextEmpty++;
            dfs(nodes[num].right, depth + 1);
        }
        dfs(root, 1);

        int ans = 1;
        int mindepth = 1;

        foreach (var kvp in dict)
        {
            int width = kvp.Value.max - kvp.Value.min + 1;
            if (width > ans)
            {
                ans = width;
                mindepth = kvp.Key;
            }
            else if (width == ans)
            {
                mindepth = Math.Min(mindepth, kvp.Key);
            }
        }

        Console.Write($"{mindepth} {ans}");
    }
}