// 2025-07-23 세 용액
// 정렬 / 투 포인터 / 이분 탐색?
class P2473
{
    static void _Main()
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        int n = int.Parse(sr.ReadLine());
        List<long> l = sr.ReadLine().Split().Select(long.Parse).ToList();

        l.Sort();

        int a1 = 0, a2 = 1, a3 = 2;
        long curmin = long.MaxValue;
        for (int i = 0; i <= n - 3; i++)
        {
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                if (Math.Abs(l[i] + l[left] + l[right]) < curmin)
                {
                    a1 = i; a2 = left; a3 = right;
                    curmin = Math.Abs(l[i] + l[left] + l[right]);
                }

                if (Math.Abs(l[i] + l[left + 1] + l[right]) < Math.Abs(l[i] + l[left] + l[right - 1]))
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        Console.WriteLine($"{l[a1]} {l[a2]} {l[a3]}");
    }
}