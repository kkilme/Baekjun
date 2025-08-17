// 2025-08-18 가운데를 말해요
// 자료 구조 / 우선순위 큐
using System.Text;

class P1655
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        PriorityQueue<int, int> max = new();
        PriorityQueue<int, int> min = new();
        StringBuilder sb = new();
        for (int i = 0; i < n; i++)
        {
            int k = int.Parse(sr.ReadLine());
            if (max.Count == 0 || max.Peek() >= k) max.Enqueue(k, -k);
            else min.Enqueue(k, k);

            if (max.Count < min.Count)
            {
                int a = min.Dequeue();
                max.Enqueue(a, -a);
            }
            else if (max.Count > min.Count + 1)
            {
                int a = max.Dequeue();
                min.Enqueue(a, a);
            }

            sb.Append(max.Peek()).Append('\n');
        }

        Console.Write(sb.ToString());
    }
}
/*
maxHeap(최대 힙): 지금까지 나온 수들 중 작은 절반을 보관. 루트는 현재 중간값
minHeap(최소 힙): 나머지 큰 절반을 보관. 루트는 큰 쪽의 최솟값.
새 수 x가 오면: x <= maxHeap.Peek() 이면 maxHeap에 넣고, 아니면 minHeap에 넣는다. (maxHeap 비어있을 땐 바로 maxHeap에)
크기 균형 맞춤: 항상 maxHeap.Count >= minHeap.Count 이고 maxHeap.Count - minHeap.Count <= 1 가 되도록 이동(pop/add)한다.
출력할 값은 항상 maxHeap.Peek() (짝수일 때 작은 쪽 규칙을 만족).
*/