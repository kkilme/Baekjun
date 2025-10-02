// 2025-10-02 중복 빼고 정렬하기
// 정렬
using System.Text;

class P10867
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());

        var l = Console.ReadLine().Split().Select(int.Parse).ToHashSet();
        var l2 = l.ToList();
        l2.Sort();

        StringBuilder sb = new();

        foreach(int i in l2)
        {
            sb.Append(i).Append(' ');
        }

        Console.Write(sb.ToString());
    }
}