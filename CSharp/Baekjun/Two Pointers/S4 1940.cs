// 2025-10-26 주몽
// 정렬 / 투 포인터
class P1940
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        int m = int.Parse(sr.ReadLine());

        var arr = sr.ReadLine().Split().Select(int.Parse).ToList();

        arr.Sort();

        int l = 0, r = n - 1;
        int cnt = 0;

        while (l < r)
        {
            if (arr[l] + arr[r] == m)
            {
                cnt++; l++; r--;
            }
            else if (arr[l] + arr[r] > m) r--;
            else l++;
        }

        Console.Write(cnt);
    }
}