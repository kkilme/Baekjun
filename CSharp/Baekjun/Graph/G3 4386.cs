// 2025-07-22 별자리 만들기
// 그래프 이론 / 최소 스패닝 트리
// 첫 C# 풀이
public class P4386
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        (float x, float y)[] stars = new (float, float)[100];

        for (int i = 0; i < n; i++)
        {
            var ip = sr.ReadLine().Split();
            stars[i].x = float.Parse(ip[0]);
            stars[i].y = float.Parse(ip[1]);
        }

        List<List<(int v, float dist)>> l = new(n);
        for (int i = 0; i < n; i++)
        {
            l.Add(new List<(int v, float dist)>());
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                float d = distance(stars[i], stars[j]);
                l[i].Add((j, d));
                l[j].Add((i, d));
            }
        }

        float answer = 0;
        List<bool> visited = new();
        for (int i = 0; i < n; i++)
        {
            visited.Add(false);
        }
        PriorityQueue<(int, float), float> pq = new();
        pq.Enqueue((0, 0), 0);
        while (pq.Count != 0)
        {
            (int, float) cur = pq.Dequeue();
            if (visited[cur.Item1]) continue;
            visited[cur.Item1] = true;
            answer += cur.Item2;

            foreach (var (v, dist) in l[cur.Item1])
            {
                if (!visited[v])
                {
                    pq.Enqueue((v, dist), dist);
                }
            }
        }

        Console.WriteLine($"{answer:F2}");
    }

    static float distance((float x, float y) p1, (float x, float y) p2)
    {
        return MathF.Sqrt(MathF.Pow(p1.x - p2.x, 2) + MathF.Pow(p1.y - p2.y, 2));
    }
}