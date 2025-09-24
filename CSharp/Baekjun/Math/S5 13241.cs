// 2025-09-24 최소공배수
// 수학 / 정수론 / 유클리드 호제법
class P13241
{
    static void _Main()
    {
        var l = Console.ReadLine().Split().Select(long.Parse).ToArray();

        long a = l[0], b = l[1];
        long gcd(long x, long y)
        {
            while (y != 0)
            {
                var tmp = y;
                y = x % y;
                x = tmp;
            }

            return x;
        }
        Console.Write(a / gcd(a, b) * b);
    }
}