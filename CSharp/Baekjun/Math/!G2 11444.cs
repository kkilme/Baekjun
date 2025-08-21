// 2025-08-21 피보나치 수 6
// 수학 / 분할 정복을 이용한 거듭제곱

// Fast Doubling 풀이
// 또는 행렬 거듭제곱(피보나치 행렬)으로 풀이 가능
class P11444
{
    const long M = 1000000007;

    // f(2k) = f(k) * (2f(k+1) - f(k))
    // f(2k+1) = f(k+1)^2 + f(k)^2
    static (long, long) f(long n)
    {
        if (n == 0) return (0, 1);
        var (a, b) = f(n >> 1);// f(k)

        long c = a * (((2 * b % M) - a + M) % M) % M; // f(2k) = f(n)
        long d = ((a * a % M) + (b * b % M)) % M; // f(2k+1)

        return n % 2 == 0 ? (c, d) : (d, (d + c) % M);
        // n이 짝수: n = 2k => c, d 그대로 반환
        // n이 홀수: n = 2k+1 => 우리가 원하는 건 2k+1, 2k+2. c = 2k, d=2k+1이므로 d와 2k+2 = f(2k) + f(2k+1)를 반환
    }

    static void _Main()
    {
        long n = long.Parse(Console.ReadLine());
        Console.Write(f(n).Item1);
    }
}