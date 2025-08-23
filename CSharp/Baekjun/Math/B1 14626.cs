// 2025-08-23 ISBN
// 수학 / 구현 / 브루트포스 / 사칙연산
class P14626
{
    static void _Main()
    {
        int a = 0;
        bool flag = true;
        bool tmp = false;
        var s = Console.ReadLine();
        for (int i = 0; i < 12; i++)
        {
            flag = !flag;
            var c = s[i];
            if (c == '*')
            {
                tmp = flag;
                continue;
            }
            if (flag) a += (c - '0') * 3;
            else a += c - '0';
        }
        int check = s[^1] - '0';
        int b = a + check;
        for (int i = 0; ; i += tmp ? 3 : 1)
        {
            if ((i + b) % 10 == 0)
            {
                Console.Write(tmp ? i / 3 : i);
                break;
            }
        }
        // *그냥 0부터 9까지 다 대입해보면 풀이가능
    }
}