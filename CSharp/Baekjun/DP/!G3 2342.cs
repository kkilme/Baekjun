// 2025-08-09 Dance Dance Revolution
// DP
// 내겐 너무 어려웠던 DP
class P2342
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void _Main()
    {
        var line = sr.ReadLine().Split().Select(int.Parse).ToArray();

        int[,] dp = new int[5, 5]; // 현재 상태까지 [왼발, 오른발]위치일 때 cost
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                dp[i, j] = int.MaxValue / 4;
            }
        }
        dp[0, 0] = 0;

        int cost(int from, int to)
        {
            if (from == to) return 1;
            else if (from == 0) return 2;
            else if (Math.Abs(from - to) == 2) return 4;
            return 3;
        }

        foreach (var move in line)
        {
            if (move == 0) break;
            int[,] newdp = new int[5, 5];

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    newdp[i, j] = int.MaxValue / 4;
                }
            }

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (dp[i, j] == int.MaxValue / 4) continue;
                    int cur = dp[i, j];

                    int cl = cost(i, move); // 왼발을 옮기는 경우
                    int cr = cost(j, move); // 오른발을 옮기는 경우

                    if (cur + cl < newdp[move, j]) newdp[move, j] = cur + cl;
                    if (cur + cr < newdp[i, move]) newdp[i, move] = cur + cr;
                }
            }

            dp = newdp; // 2차원 배열에서, 현재 가능한 경우의 요소만 cost가 무한이 아닌 값으로 저장됨
        }

        int answer = int.MaxValue;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                answer = Math.Min(answer, dp[i, j]);
            }
        }

        Console.Write(answer);

    }
}