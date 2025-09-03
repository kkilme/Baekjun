// 2025-09-03 반도체 설계
// 이분탐색 / LIS 문제
class P2352
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] ports = new int[n];
        ports = Console.ReadLine().Split().Select(int.Parse).ToArray();

        List<int> lis = new();

        foreach (var p in ports)
        {
            if (lis.Count == 0 || lis[^1] < p) lis.Add(p);
            else
            {
                int l = lis.BinarySearch(p);
                if (l < 0) l = ~l;
                // int l = 0, r = lis.Count;
                // while (l < r)
                // {
                //     int mid = (l + r) / 2;
                //     if (lis[mid] < p) l = mid + 1;
                //     else r = mid;
                // }
                lis[l] = p;
            }
        }

        Console.Write(lis.Count);
    }
}