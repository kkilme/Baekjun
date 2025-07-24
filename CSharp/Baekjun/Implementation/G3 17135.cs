// 2025-07-25 캐슬 디펜스
// 구현 / 그래프 이론 / 브루트포스 / 그래프 탐색 / 시뮬레이션 / BFS
class Enemy
{
    public int savedr;
    public int r;
    public int c;
    public bool isValid;
    public Enemy(int r = 99, int c = 99, bool isValid = true)
    {
        this.r = this.savedr = r;
        this.c = c;
        this.isValid = isValid;
    }
}

class P17135
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static int n, m, d;
    static List<Enemy> l;

    static int answer = 0;
    static void _Main()
    {
        int[] line = sr.ReadLine().Split().Select(int.Parse).ToArray();
        n = line[0]; m = line[1]; d = line[2];
        l = new();
        for (int i = 0; i < n; i++)
        {
            string[] line2 = sr.ReadLine().Split();
            for (int j = 0; j < m; j++)
            {
                if (line2[j] == "1")
                {
                    l.Add(new Enemy(i, j));
                }
            }
        }
        bool[] selected = new bool[m];
        for (int i = 0; i < m; i++) selected[i] = false;
        BT(0, 0, selected);
        Console.Write(answer);
    }

    static void BT(int depth, int cur, bool[] selected)
    {
        if (depth == 3)
        {
            List<int> s = new();
            for (int i = 0; i < m; i++)
            {
                if (selected[i]) s.Add(i);
            }
            Simulate(s[0], s[1], s[2]);
            return;
        }

        for (int i = cur; i < m; i++)
        {
            if (!selected[i])
            {
                selected[i] = true;
                BT(depth + 1, i, selected);
                selected[i] = false;
            }
        }
    }

    static void Simulate(int a, int b, int c)
    {
        int kills = 0;
        (int r, int c)[] archers = { (n, a), (n, b), (n, c) };
        List<Enemy> targets;
        int[] distance = new int[3];
        List<Enemy> enemies = new(l);
        foreach (var e in enemies) e.r = e.savedr;
        while (enemies.Count != 0)
        {
            targets = new() { new Enemy(isValid: false), new Enemy(isValid: false), new Enemy(isValid: false) };
            distance[0] = distance[1] = distance[2] = 10000;
            for (int i = 0; i < 3; i++)
            {
                foreach (var enemy in enemies)
                {
                    int dist = Math.Abs(archers[i].r - enemy.r) + Math.Abs(archers[i].c - enemy.c);
                    if (dist > d) continue;
                    if (dist < distance[i] || (dist == distance[i] && enemy.c < targets[i].c))
                    {
                        targets[i] = enemy;
                        distance[i] = dist;
                    }
                }
            }

            for (int i = 0; i < 3; i++)
            {
                if (targets[i].isValid && enemies.Contains(targets[i]))
                {
                    kills++;
                    enemies.Remove(targets[i]);
                }
            }

            foreach (var enemy in enemies)
            {
                if (++enemy.r >= n) targets.Add(enemy);
            }

            foreach (var t in targets)
            {
                enemies.Remove(t);
            }
            targets.Clear();
        }

        answer = Math.Max(answer, kills);
    }
}
