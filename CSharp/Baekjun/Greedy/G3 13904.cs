// 2025-08-07 과제
// 자료 구조 / 그리디 / 정렬 / 우선순위 큐
// 2109와 동일
class P13904
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        List<(int d, int w)> l = new();
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            l.Add((int.Parse(line[0]), int.Parse(line[1])));
        }

        l.Sort((a, b) => a.d.CompareTo(b.d));

        PriorityQueue<int, int> pq = new();

        foreach (var (d, w) in l)
        {
            pq.Enqueue(w, w);
            if (pq.Count > d)
            {
                pq.Dequeue();
            }
        }

        int answer = 0;

        while (pq.Count > 0) answer += pq.Dequeue();

        Console.Write(answer);
    }
}
