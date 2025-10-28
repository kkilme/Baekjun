// 2025-10-29 기타줄
// 수학 / 그리디?
class P1049
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int n = l[0], m = l[1];

        int pack = int.MaxValue, single = int.MaxValue;

        for (int i = 0; i < m; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            pack = Math.Min(line[0], pack);
            single = Math.Min(line[1], single);
        }

        float psingle = pack / 6.0f;
        if (psingle < single)
        {
            int left = n % 6;
            int leftPrice = Math.Min(left * single, pack);
            Console.Write((n / 6 * pack) + leftPrice);
        }
        else
        {
            Console.Write(single * n);
        }

    }
}