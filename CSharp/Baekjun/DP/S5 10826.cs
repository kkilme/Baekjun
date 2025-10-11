// 2025-10-11 피보나치 수 4
// DP / 임의 정밀도, 큰 수 연산
using System.Numerics;

class P10826
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());

        List<BigInteger> l = new() { 0, 1 };
        for (int i = 2; i <= n + 1; i++)
        {
            l.Add(l[i - 1] + l[i - 2]);
        }

        Console.Write(l[n]);
    }
}