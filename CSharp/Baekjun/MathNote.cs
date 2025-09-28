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
}