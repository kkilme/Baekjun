// 2025-09-12 소트인사이드
// 문자열 / 정렬
class P1427
{
    static void _Main()
    {
        string s = Console.ReadLine();
        SortedDictionary<char, int> cnts = new();
        foreach (var c in s)
        {
            if (cnts.ContainsKey(c)) cnts[c]++;
            else cnts.Add(c, 1);
        }

        string ans = "";
        foreach (var kvp in cnts)
        {
            ans += new string(kvp.Key, kvp.Value);
        }
        ans = new string(ans.Reverse().ToArray());
        Console.Write(ans);
    }
}