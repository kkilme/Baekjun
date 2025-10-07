// 2025-10-07 폴리오미노
// 구현 / 그리디 / 문자열
class P1343
{
    static void _Main()
    {
        string s = Console.ReadLine();

        string ans = "";

        int cnt = 0;
        foreach (var c in s)
        {
            if (c == '.')
            {
                if (cnt == 0)
                {
                    ans += ".";
                    continue;
                }
                if (cnt == 4)
                {
                    ans += "AAAA";
                    cnt = 0;
                }
                else if (cnt == 2)
                {
                    ans += "BB";
                    cnt = 0;
                }
                else
                {
                    Console.Write(-1);
                    return;
                }
                ans += ".";
            }
            else if (cnt == 3)
            {
                ans += "AAAA";
                cnt = 0;
            }
            else cnt++;
        }

        if (cnt == 4)
            ans += "AAAA";
        else if (cnt == 2)
            ans += "BB";
        else if (cnt != 0)
        {
            Console.Write(-1);
            return;
        }

        Console.Write(ans);
    }
}