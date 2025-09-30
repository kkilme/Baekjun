// 2025-09-30 카드1
using System.Text;

class P2161
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());

        List<int> deque = new();
        for (int i = n; i >= 1; i--) deque.Add(i);

        StringBuilder sb = new();

        int j = 0;

        while (deque.Count != 0)
        {
            if (j % 2 == 0)
            {
                sb.Append(deque[^1]).Append(' ');
                deque.RemoveAt(deque.Count - 1);
            }
            else
            {
                int tmp = deque[^1];
                deque.RemoveAt(deque.Count - 1);
                deque.Insert(0, tmp);
            }
            j++;
        }

        Console.Write(sb.ToString());
    }
}