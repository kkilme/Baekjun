// 2025-10-16 문자열 집합
// 자료 구조 / 문자열 / 집합과 맵 / 해시를 사용한 집합과 맵 / 트리를 사용한 집합과 맵
class P14425
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int n = l[0], m = l[1];

        HashSet<string> ss = new();
        for (int i = 0; i < n; i++)
        {
            ss.Add(sr.ReadLine());
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            string s = sr.ReadLine();
            if (ss.Contains(s)) ans++;
        }

        Console.Write(ans);
    }
}