// 2025-07-28 크게 만들기
// 자료 구조 / 그리디 알고리즘 / 스택
// 스택을 쓸 생각조차 하지 못했다
using System.Text;

class P2812
{
    static StringBuilder sb = new StringBuilder(); // stack처럼 사용 가능

    static void _Main()
    {
        var line = Console.ReadLine().Split();
        int n, k;
        n = int.Parse(line[0]);
        k = int.Parse(line[1]);
        string num = Console.ReadLine().Trim();

        foreach (var c in num)
        {
            while (k > 0 && sb.Length > 0 && sb[^1] < c)
            {
                sb.Length--; // stack.pop()
                k--;
            }
            sb.Append(c);
        }

        sb.Length -= k;

        Console.WriteLine(sb.ToString());
    }
}