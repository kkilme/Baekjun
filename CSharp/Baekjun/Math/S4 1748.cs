// 2025-10-29 수 이어 쓰기 1
// 수학 / 구현
class P1748
{
    static void _Main()
    {
        string s = Console.ReadLine();
        int n = int.Parse(s);

        long ans = (n - (long)Math.Pow(10, s.Length - 1) + 1) * s.Length;
        for (int i = 1; i < s.Length; i++) ans += (long)Math.Pow(10, i - 1) * 9 * i;

        Console.Write(ans);
    }
}