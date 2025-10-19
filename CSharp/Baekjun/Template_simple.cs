class P2
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int a = l[0], b = l[1];

        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
        }

    }
}