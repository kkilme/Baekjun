// 2025-09-27 알고리즘 수업 - 점근적 표기 1
// 수학

class P24313
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var line = sr.ReadLine().Split();
        int a1 = int.Parse(line[0]), a0 = int.Parse(line[1]);
        int c = int.Parse(sr.ReadLine());
        int n0 = int.Parse(sr.ReadLine());

        int i = c - a1;
        var bound = (float)a0 / i;
        Console.Write(i >= 0 ? (bound <= n0 ? 1 : 0) : 0);
    }
}