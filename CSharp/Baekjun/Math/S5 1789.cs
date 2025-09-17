// 2025-09-17 수들의 합
// 수학 / 그리디
class P1789
{
    static void _Main()
    {
        long s = long.Parse(Console.ReadLine());

        int n = 1;
        long left = s;
        for (; left > 0; n++) left -= n;

        if (left == 0) Console.Write(n - 1);
        else Console.Write(n - 2);
    }
}