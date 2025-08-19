// 2025-08-20 보석 도둑
// 자료 구조 / 그리디 / 정렬 / 우선순위 큐
// 아이디어가 중요한 문제
class P1202
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void Main()
    {
        var l = sr.ReadLine().Split();
        int n = int.Parse(l[0]);
        int k = int.Parse(l[1]);

        List<(int m, int v)> jewels = new();
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            jewels.Add((int.Parse(line[0]), int.Parse(line[1])));
        }

        jewels.Sort((a, b) => b.m.CompareTo(a.m));

        List<int> bags = new();
        for (int i = 0; i < k; i++)
        {
            bags.Add(int.Parse(sr.ReadLine().TrimEnd()));
        }

        bags.Sort(); // 가방 최대 무게 기준 오름차순 정렬. 이전 가방에서 가능했던 보석들은, 다음 가방에서도 반드시 가능함 => pq 내용물 재사용 가능

        long answer = 0;

        PriorityQueue<int, int> pq = new();

        foreach (int i in bags)
        {
            while (jewels.Count > 0 && jewels[^1].m <= i)
            {
                pq.Enqueue(jewels[^1].v, -jewels[^1].v); // 현재 가방 무게에 가능한 모든 보석을 pq에 넣기
                jewels.RemoveAt(jewels.Count - 1);
            }
            if (pq.Count != 0)
            {
                answer += pq.Dequeue(); // 현재 가능한 것 중 가장 가치 높은 것
            }
        }

        Console.Write(answer);
    }
}