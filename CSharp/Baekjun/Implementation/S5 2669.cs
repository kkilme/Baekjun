// 2025-10-06 직사각형 네게의 합집합의 면적 구하기
// 구현
// 2563 색종이와 유사
class P2669
{
    static void _Main()
    {
        bool[,] filled = new bool[101, 101];
        for (int i = 0; i < 4; i++)
        {
            var l = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int x1 = l[0], y1 = l[1], x2 = l[2], y2 = l[3];
            for (int p = x1; p < x2; p++)
            {
                for (int q = y1; q < y2; q++)
                {
                    filled[p, q] = true;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                ans += filled[i, j] ? 1 : 0;
            }
        }

        Console.Write(ans);
    }
}