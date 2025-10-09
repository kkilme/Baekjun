// 2025-10-09 생일
// 구현 / 문자열 / 정렬
class P5635
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        SortedDictionary<(int, int, int), string> sd = new();

        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            int d = int.Parse(line[1]), m = int.Parse(line[2]), y = int.Parse(line[3]);
            sd.Add((y, m, d), line[0]);
        }

        Console.WriteLine(sd.Last().Value);
        Console.Write(sd.First().Value);
    }
}