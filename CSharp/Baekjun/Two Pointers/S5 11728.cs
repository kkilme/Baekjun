// 2025-09-26 배열 합치기
// 배열 / 두 포인터
using System.Text;
class P11728
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split();
        int n = int.Parse(l[0]), m = int.Parse(l[1]);

        int[] arr1 = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int[] arr2 = sr.ReadLine().Split().Select(int.Parse).ToArray();

        int i = 0, j = 0;
        StringBuilder sb = new();

        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j]) sb.Append(new string(arr1[i++].ToString())).Append(' ');
            else sb.Append(new string(arr2[j++].ToString())).Append(' ');
        }

        while (i < n) sb.Append(new string(arr1[i++].ToString())).Append(' ');
        while (j < m) sb.Append(new string(arr2[j++].ToString())).Append(' ');

        Console.Write(sb.ToString());
    }
}