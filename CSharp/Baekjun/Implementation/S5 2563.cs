// 2025-09-13 색종이
// 구현
class P2563
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        bool[,] board = new bool[100, 100];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            int l = int.Parse(line[0]), b = int.Parse(line[1]);
            for (int j = l; j < l + 10; j++)
            {
                for (int k = b; k < b + 10; k++)
                {
                    board[j, k] = true;
                }
            }
        }

        int ans = 0;
        foreach (var b in board)
        {
            if (b) ans++;
        }

        Console.Write(ans);
    }
}