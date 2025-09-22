// 2025-09-22 뒤집기
// 그리디 / 문자열
class P1439
{
    static void _Main()
    {
        string s = Console.ReadLine();
        int a = 0, b = 0;

        char prev = ' ';
        // 덩어리 수 세기
        foreach (var c in s)
        {
            if (c == '0' && c != prev)
            {
                prev = '0';
                a++;
            }
            else if (c == '1' && c != prev)
            {
                prev = '1';
                b++;
            }
        }

        Console.Write(Math.Min(a, b));
    }
}