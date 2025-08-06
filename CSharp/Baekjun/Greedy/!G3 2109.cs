// 2025-08-06 순회강연
// 자료구조 / 그리디 / 정렬 / 우선순위 큐
class P2109
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        List<(int p, int d)> l = new();
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            l.Add((int.Parse(line[0]), int.Parse(line[1])));
        }

        l.Sort((a, b) => a.d.CompareTo(b.d));

        PriorityQueue<int, int> pq = new();
        foreach (var (p, d) in l)
        {
            pq.Enqueue(p, p); // 일단 넣고
            if (d < pq.Count) // 날짜 초과 시 가장 낮은 보수 강연 제거
            {
                pq.Dequeue();
            }
        }

        int answer = 0;

        while (pq.Count != 0) answer += pq.Dequeue();

        Console.Write(answer);
    }
}