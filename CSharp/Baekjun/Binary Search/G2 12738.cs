// 2025-08-14 가장 긴 증가하는 부분 수열 3
// 이분탐색 / LIS 문제
// 12015와 동일
class P12738
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] A = Console.ReadLine().Split().Select(int.Parse).ToArray();

        List<int> lis = new();

        foreach (var i in A)
        {
            if (lis.Count == 0 || lis[^1] < i) lis.Add(i);
            else
            {
                int idx = lis.BinarySearch(i);
                if (idx < 0) idx = ~idx;
                lis[idx] = i;
            }
        }

        Console.Write(lis.Count);
    }
}