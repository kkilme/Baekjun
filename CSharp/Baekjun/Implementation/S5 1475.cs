// 2025-09-16 방 번호
// 구현
class P1475
{
    static void Main()
    {
        string n = Console.ReadLine();
        int[] cnts = new int[10];
        for (int i = 0; i < 10; i++) cnts[i] = 0;
        foreach (var c in n) cnts[c - '0']++;

        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (i == 6 || i == 9) continue;
            ans = Math.Max(ans, cnts[i]);
        }

        int sn = cnts[6] + cnts[9];
        int need;
        if (sn % 2 == 0) need = sn / 2;
        else need = sn / 2 + 1;

        ans = Math.Max(ans, need);
        Console.Write(ans);
    }
}