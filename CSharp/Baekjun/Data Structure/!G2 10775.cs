// 2025-08-27 공항
// 자료 구조 / 분리 집합 / 그리디
// 처음엔 O(n^2) 풀이밖에 떠올리지 못함.
// 유니온 파인드를 써야할 줄은 상상도 못했다.
// 정해는 유니온 파인드지만, 세그먼트 트리나 SortedSet을 써도 풀 수 있다는 듯.
// 특히 첫 아이디어에 SortedSet을 사용했다면 쉽게 풀 수 있었을 것 같다.
class P10775
{
    static int[] parent; // parent[x]는 "x 게이트보다 작거나 같은 게이트 중 가장 마지막으로 사용 가능한 게이트 번호"
    static StreamReader sr = new(Console.OpenStandardInput());

    static int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    static void union(int a, int b)
    {
        a = find(a);
        b = find(b);
        parent[a] = b;
    }

    static void _Main()
    {
        int g = int.Parse(sr.ReadLine());
        int p = int.Parse(sr.ReadLine());

        parent = new int[g + 1];
        for (int j = 0; j <= g; j++) parent[j] = j;

        int i;
        for (i = 0; i < p; i++)
        {
            int cur = int.Parse(sr.ReadLine());
            int rt = find(cur);
            if (rt == 0) break;
            union(rt, rt - 1); // 어떤 게이트 x에 비행기를 도킹하면, x는 사용 불가능해지므로 parent[x]를 find(x-1)로 갱신
        }
        Console.Write(i);
    }
}