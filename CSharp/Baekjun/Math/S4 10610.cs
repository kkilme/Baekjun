// 2025-10-22 30
// 수학 / 그리디 / 문자열 / 정렬 / 정수론
// 30의 배수 판정
using System.Text;

class P10610
{
    static void _Main()
    {
        string s = Console.ReadLine();
        List<int> chars = new();
        int sum = 0;
        foreach (var c in s)
        {
            int ctoi = c - '0';
            sum += ctoi;
            chars.Add(ctoi);
        }

        // 3의 배수 판정
        if(sum % 3 != 0)
        {
            Console.Write(-1);
            return;
        }

        chars.Sort();

        // 10의 배수 판정
        if(chars[0] != 0)
        {
            Console.Write(-1);
            return;
        }
        StringBuilder sb = new();
        for (int i = chars.Count - 1; i >= 0; i--)
        {
            sb.Append(chars[i]);
        }

        Console.Write(sb.ToString());     

    }
}