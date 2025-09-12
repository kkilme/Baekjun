// 2025-09-11 크로아티아 알파벳
// 구현 / 문자열
class P2941
{
    static void _Main()
    {
        var s = Console.ReadLine();
        int n = s.Length;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            var cur = s[i];
            if ((cur == 's' || cur == 'z' || cur == 'c') && i + 1 < n && s[i + 1] == '=') i++;
            else if ((cur == 'n' || cur == 'l') && i + 1 < n && s[i + 1] == 'j') i++;
            else if (cur == 'd' && i + 2 < n && s[i + 1] == 'z' && s[i + 2] == '=') i += 2;
            else if ((cur == 'c' || cur == 'd') && i + 1 < n && s[i + 1] == '-') i++;
            ans++;
        }

        Console.Write(ans);
    }
}