// 2025-09-19 날짜 계산
// 수학 / 브루트포스 / 정수론
class P1476
{
    static void _Main()
    {
        var l = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int e = l[0], s = l[1], m = l[2];

        int E = 1, S = 1, M = 1;
        int years = 1;

        while (e != E || s != S || m != M)
        {
            years++;
            if (++E == 16) E = 1;
            if (++S == 29) S = 1;
            if (++M == 20) M = 1;
        }

        Console.Write(years);
    }
}