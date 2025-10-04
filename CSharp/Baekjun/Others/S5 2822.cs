// 2025-10-04 점수 계산
// 정렬
class P2822
{
    static void _Main()
    {
        PriorityQueue<(int, int), int> pq = new();
        for (int i = 1; i <= 8; i++)
        {
            int sc = int.Parse(Console.ReadLine());
            if (pq.Count < 5)
            {
                pq.Enqueue((sc, i), sc);
            }
            else if (pq.Peek().Item1 < sc)
            {
                pq.Dequeue();
                pq.Enqueue((sc, i), sc);
            }
        }
        int score = 0;
        List<int> l = new();
        while (pq.Count != 0)
        {
            var cur = pq.Dequeue();
            score += cur.Item1;
            l.Add(cur.Item2);
        }

        l.Sort();

        Console.WriteLine(score);
        foreach (var i in l)
        {
            Console.Write($"{i} ");
        }
    }
}