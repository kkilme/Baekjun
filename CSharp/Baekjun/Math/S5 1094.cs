// 2025-09-19 막대기
// 수학 / 비트마스킹?
class P1094
{
    static void _Main()
    {
        int target = int.Parse(Console.ReadLine());
        int cur = 64;
        int cursum = 0;
        int cnt = 0;
        while (cursum != target)
        {
            if (target - cursum >= cur)
            {
                cnt++;
                cursum += cur;
            }
            else cur /= 2;
        }
        Console.Write(cnt);
    }
}