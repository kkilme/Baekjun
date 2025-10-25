// 2025-10-25 에라토스테네스의 체
// 에라토스테네스의 체 / 수학 / 구현 / 정수론 / 소수 판정
class P2960
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int n = l[0], k = l[1];

        bool[] check = new bool[n + 1];
        int cnt = 0;

        for (int i = 2; i <= n; i++)
        {
            if (check[i]) continue;
            for (int j = i; j <= n; j += i)
            {
                if (!check[j])
                {
                    check[j] = true;
                    if (++cnt == k)
                    {
                        Console.Write(j);
                        return;
                    }

                }
            }
        }

    }
}