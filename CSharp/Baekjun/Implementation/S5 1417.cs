// 2025-10-14 국회의원 선거
// 구현 / 자료 구조 / 그리디 / 시뮬레이션 / 우선순위 큐
class P1417
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        int first = int.Parse(sr.ReadLine());

        int cur = first;
        PriorityQueue<int, int> pq = new();
        for (int i = 1; i < n; i++)
        {
            var next = int.Parse(sr.ReadLine());
            pq.Enqueue(next, -next);
        }

        while (pq.Count != 0)
        {
            int nxt = pq.Dequeue();
            if (cur <= nxt)
            {
                cur++;
                nxt--;
                pq.Enqueue(nxt, -nxt);
            }
        }

        Console.Write(cur - first);
    }
}