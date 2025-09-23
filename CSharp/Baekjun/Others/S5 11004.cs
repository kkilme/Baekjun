// 2025-09-23 K번째 수
// 정렬
class P11004
{
    static void Main()
    {
        int k = int.Parse(Console.ReadLine().Split()[1]);
        var a = Console.ReadLine().Split().Select(int.Parse).ToList();
        a.Sort();
        Console.Write(a[k - 1]);
    }
}