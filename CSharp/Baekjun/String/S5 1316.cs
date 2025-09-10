// 2025-09-10 그룹 단어 체커
// 구현 / 문자열
class P1316
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine();
            HashSet<char> used = new();
            char cur = line[0];
            used.Add(cur);
            bool flag = false;
            for (int j = 0; j < line.Length; j++)
            {
                if (line[j] == cur) continue;
                else
                {
                    cur = line[j];
                    if (used.Contains(cur))
                    {
                        flag = true;
                        break;
                    }
                    used.Add(cur);
                }
            }
            if (!flag) answer++;
        }

        Console.Write(answer);
    }
}