class MathNote
{
    // GCD 최대공약수
    public long GCD(long a, long b)
    {
        // 유클리드 호제법
        // O(log(min(a, b)))
        while (b != 0)
        {
            // a, b => b, a % b
            long tmp = b;
            b = a % b;
            a = tmp;
        }

        return a;
    }

    // LCM 최소공배수: GCD 이용
    // (a * b)/gcd(a, b)
    public long LCM(long a, long b)
    {
        var gcd = GCD(a, b);

        return a / gcd * b; // gcd로 먼저 나눠서 오버플로우 방지
    }

    // 행렬 곱셈
    // n*m 행렬 m1, m*k 행렬 m2의 곱셈
    public int[,] MatrixMultiply(int n, int m, int k, int[,] m1, int[,] m2)
    {
        int[,] result = new int[n, k];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++) result[i, j] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                for (int p = 0; p < m; p++)
                {
                    result[i, j] += m1[i, p] * m2[p, j];
                }
            }
        }

        return result;
    }

    const long M = 1000000007;

    // n번째 피보나치 수 구하기: fast doubling
    // f(2k) = f(k) * (2f(k+1) - f(k))
    // f(2k+1) = f(k+1)^2 + f(k)^2
    // fibo(n) = FastDoublingFibo(n).Item1
    public (long, long) FastDoublingFibo(long n)
    {
        if (n == 0) return (0, 1);
        var (a, b) = FastDoublingFibo(n >> 1);// f(k)

        long c = a * (((2 * b % M) - a + M) % M) % M; // f(2k) = f(n)
        long d = ((a * a % M) + (b * b % M)) % M; // f(2k+1)

        return n % 2 == 0 ? (c, d) : (d, (d + c) % M);
        // n이 짝수: n = 2k => c, d 그대로 반환
        // n이 홀수: n = 2k+1 => 우리가 원하는 건 f(2k+1), f(2k+2). c = f(2k), d = f(2k+1)이므로 d와 f(2k+2) = f(2k) + f(2k+1)를 반환
    }
}