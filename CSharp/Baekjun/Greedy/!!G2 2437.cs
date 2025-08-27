// 2025-08-22 저울
// 그리디 / 정렬
// 떠올리기 힘든 기발한 아이디어
class P2437
{
    static void _Main()
    {
        Console.ReadLine();
        var line = Console.ReadLine().Split().Select(int.Parse).ToList();

        line.Sort();

        int next = 1;
        foreach (var i in line)
        {
            if (next < i) break;
            next += i;
        }

        Console.Write(next);
    }
}
/*
n개의 수들 중 일부를 합해서 만들 수 없는 가장 작은 수를 구하는 문제

i번째로 가벼운 추를 보고 있을 때, 
이 추의 무게(wi)가 next보다 크면 next만큼의 무게를 만들 방법이 없는 게 확정되고, next-1까지는 모두 가능하다고 가정했으니 next가 정답.

아니라면(wi <= next), (i-1)번째까지의 추들만을 사용해서 0부터 next-1까지 만드는 법을 모두 알고 있으니, 
거기에 i번째 추만 추가하여 wi부터 wi+next-1까지 만드는 방법도 알 수 있고, 이 두 범위가 겹치기 때문에 (wi <= next) 빈틈이 생기지 않음. 따라서 결과적으로 next가 wi만큼 증가하는 꼴.
0              next-1
+---------------+
            +---------------+
            wi           wi+next-1 => 0부터 wi+next-1까지 전부 만들 수 있다.
*/