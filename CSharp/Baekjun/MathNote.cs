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
            a = b;
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
}