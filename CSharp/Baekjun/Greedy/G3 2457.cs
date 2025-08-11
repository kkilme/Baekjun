// 2025-08-12 공주님의 정원
// 그리디 / 정렬

class P2457
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static int[] _30 = new int[4] { 4, 6, 9, 11 };
    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        int start = dateToInt(3, 1);
        int end = dateToInt(11, 30);

        List<(int s, int e)> flowers = new();
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            flowers.Add((Math.Max(dateToInt(line[0], line[1]), start), Math.Min(dateToInt(line[2], line[3]) - 1, end)));
            if (flowers[i].s == start && flowers[i].e == end)
            {
                Console.Write(1);
                return;
            }
        }

        flowers.Sort((a, b) =>
        {
            if (a.s == b.s) return b.e.CompareTo(a.e);
            return a.s.CompareTo(b.s);
        });

        if (flowers[0].s != start)
        {
            Console.Write(0);
            return;
        }

        int ans = 1;
        int curs = start;
        int cure = flowers[0].e;
        PriorityQueue<int, int> pq = new();
        for (int i = 1; i < flowers.Count && cure != end; i++)
        {
            if (flowers[i].s > cure)
            {
                if (flowers[i].s - cure == 1) pq.Enqueue(i, -flowers[i].e);
                if (pq.Count == 0)
                {
                    Console.Write(0);
                    return;
                }

                int idx = pq.Dequeue();
                if (flowers[idx].s > cure + 1)
                {
                    Console.Write(0);
                    return;
                }

                ans++;
                curs = flowers[idx].s;
                cure = flowers[idx].e;
                pq.Clear();
            }

            if (flowers[i].e > cure)
            {
                pq.Enqueue(i, -flowers[i].e);
            }
        }

        if (pq.Count != 0)
        {
            int idx = pq.Dequeue();
            if (flowers[idx].s > cure + 1)
            {
                Console.Write(0);
                return;
            }
            cure = flowers[idx].e;
            ans++;
        }

        if (cure == end) Console.Write(ans);
        else Console.Write(0);
    }

    static int dateToInt(int month, int day)
    {
        int num = 0;
        for (int i = 1; i < month; i++)
        {
            if (i == 2) num += 28;
            else if (_30.Contains(i)) num += 30;
            else num += 31;
        }

        return num + day;
    }
}

/* 더 좋은 풀이? by chatgpt
int targetStart = DateToDay(3, 1);   // 60
int targetEnd = DateToDay(12, 1);    // 335 (we need to cover up to 11/30 => [60,335))
int cur = targetStart;
int idx = 0;
int count = 0;
int n = flowers.Count;

while (cur < targetEnd)
{
    int maxReach = cur;
    while (idx < n && flowers[idx].start <= cur)
    {
        if (flowers[idx].end > maxReach)
            maxReach = flowers[idx].end;
        idx++;
    }
    if (maxReach == cur)
    {
        Console.WriteLine(0);
        return;
    }
    count++;
    cur = maxReach;
}
*/
