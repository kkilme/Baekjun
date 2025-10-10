// 2025-10-10 수 정렬하기 4
// 정렬
using System.Text;
class P11931
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        PriorityQueue<int, int> pq = new();

        for (int i = 0; i < n; i++)
        {
            int a = int.Parse(sr.ReadLine());
            pq.Enqueue(a, -a);
        }

        StringBuilder sb = new();

        while (pq.Count != 0)
        {
            sb.AppendLine(pq.Dequeue().ToString());
        }

        Console.Write(sb.ToString());
    }
}