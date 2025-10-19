// 2025-10-19 대칭 차집합
// 자료 구조 / 집합과 맵 / 해시를 사용한 집합과 맵 / 트리를 사용한 집합과 맵
class P1269
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        var l = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int a = l[0], b = l[1];

        HashSet<int> A = sr.ReadLine().Split().Select(int.Parse).ToHashSet();
        HashSet<int> B = sr.ReadLine().Split().Select(int.Parse).ToHashSet();

        int cnt = 0;
        foreach (var i in A)
        {
            if (!B.Contains(i)) cnt++;
        }
        foreach (var i in B)
        {
            if (!A.Contains(i)) cnt++;
        }

        Console.Write(cnt);
    }
}