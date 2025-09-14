// 2025-09-14 숫자 카드
// 자료 구조 / 정렬,이분탐색? / 집합과 맵, 해시를 사용한 집합과 맵
using System.Text;

class P10815
{

    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
        HashSet<int> has = new();
        foreach (int i in arr)
        {
            has.Add(i);
        }

        int m = int.Parse(Console.ReadLine());
        int[] q = Console.ReadLine().Split().Select(int.Parse).ToArray();
        StringBuilder sb = new();
        foreach (int i in q)
        {
            if (has.Contains(i)) sb.Append("1 ");
            else sb.Append("0 ");
        }

        Console.Write(sb.ToString());
    }
}