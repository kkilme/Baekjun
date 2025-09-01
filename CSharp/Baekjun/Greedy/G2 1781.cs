// 2025-09-01 컵라면
// 자료 구조 / 그리디 / 정렬 / 우선순위 큐
// 2109, 13904와 동일
class P1781
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        (int d, int c)[] problems = new (int d, int c)[n];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            problems[i] = (int.Parse(line[0]), int.Parse(line[1]));
        }

        Array.Sort(problems);

        PriorityQueue<int, int> pq = new();
        foreach (var (d, c) in problems)
        {
            pq.Enqueue(c, c);
            if (pq.Count > d) pq.Dequeue();
        }

        int ans = 0;
        while (pq.Count != 0) ans += pq.Dequeue();

        Console.Write(ans);

    }
}