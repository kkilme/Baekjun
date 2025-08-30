// 2025-08-31 버블 소트
// 정렬
// 구현은 쉽지만 아이디어가 어려운 문제
// 버블 소트에서 왼쪽으로는 한 루프에 최대 한 칸씩만 갈 수 있다는 것을 이용
// n만큼 떨어진 제자리에 가려면 n번 루프가 필요함 
class P1377
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        (int, int)[] A = new (int, int)[n];
        for (int i = 0; i < n; i++)
        {
            int a = int.Parse(sr.ReadLine());
            A[i] = (a, i);
        }

        Array.Sort(A, (a, b) =>
        {
            if (a.Item1 == b.Item1) return a.Item2.CompareTo(b.Item2); // 정렬 시 같은 원소는 순서 유지(stable)
            return a.Item1.CompareTo(b.Item1);
        });

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = Math.Max(mx, A[i].Item2 - i);
        }

        Console.Write(mx + 1);
    }
}

/*
어떤 원소가 원래 위치 orig에서 정렬 후 위치 pos로 왼쪽으로 이동해야 한다면(즉 orig > pos), 
그 원소를 왼쪽으로 옮기려면 다른 작은 원소들이 오른쪽으로 지나가야 하고, 
한 번의 패스 당 최대 한 칸씩 이동(또는 다른 원소들이 한 칸씩 오도록 유도)밖에 안됨. 
따라서 그 원소가 제자리를 찾으려면 최소 orig - pos 패스가 필요.
*/