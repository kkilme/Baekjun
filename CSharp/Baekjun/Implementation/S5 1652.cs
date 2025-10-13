// 2025-10-13 누울 자리를 찾아라
// 구현 / 문자열
class P1652
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        string[] s = new string[n];

        for (int i = 0; i < n; i++)
        {
            s[i] = sr.ReadLine();
        }

        int h = 0, v = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (s[i][j] == 'X')
                {
                    cur = 0;
                    flag = false;
                }
                else
                {
                    cur++;
                    if (cur == 2 && !flag)
                    {
                        h++;
                        flag = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            bool flag = false;
            for (int j = 0; j < n; j++)
            {
                if (s[j][i] == 'X')
                {
                    cur = 0;
                    flag = false;
                }
                else
                {
                    cur++;
                    if (cur == 2 && !flag)
                    {
                        v++;
                        flag = true;
                    }
                }
            }
        }

        Console.Write($"{h} {v}");
    }
}