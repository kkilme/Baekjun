// 2025-10-23 접미사 배열
// 문자열 / 정렬
class P11656
{
    static void _Main()
    {
        string s = Console.ReadLine();

        List<string> strs = new();
        for (int i = 0; i < s.Length; i++)
        {
            strs.Add(s.Substring(i));
        }

        strs.Sort();

        foreach (var st in strs)
        {
            Console.WriteLine(st);
        }
    }
}