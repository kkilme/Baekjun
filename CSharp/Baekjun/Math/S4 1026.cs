// 2025-10-15 보물
// 수학 / 그리디 / 정렬
class P1026
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        var l2 = sr.ReadLine().Split().Select(int.Parse).ToArray();

        Array.Sort(l);
        Array.Sort(l2, (a, b) => { return b.CompareTo(a); });

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += l[i] * l2[i];
        }

        Console.Write(sum);
    }
}