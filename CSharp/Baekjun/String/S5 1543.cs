// 2025-10-01 문서 검색
// 문자열 / 브루트포스
class P1543
{
    static void _Main()
    {
        string s = Console.ReadLine();
        string target = Console.ReadLine();

        int ans = 0;
        for (int i = 0; i < s.Length - target.Length + 1; i++)
        {
            bool flag = true;
            for (int j = 0; j < target.Length; j++)
            {
                if (target[j] != s[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                i += target.Length - 1;
                ans++;
            }
        }
        Console.Write(ans);
    }
}