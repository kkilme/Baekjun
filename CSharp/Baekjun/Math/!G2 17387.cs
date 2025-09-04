// 2025-09-05 선분 교차 2
// 기하학 / 많은 조건 분기 / 선분 교차 판정
// CCW를 사용하는 예. CCW를 쓴다는 걸 안 후에도 구현은 쉽지 않았다.
class P17387
{
    struct Point
    {
        public long x, y;
        public Point(long x, long y) { this.x = x; this.y = y; }
    }

    static long CCW(in Point a, in Point b, in Point c)
    {
        return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    }

    static bool Intersect(Point a, Point b, Point c, Point d)
    {
        // 교차하려면 A-B-C의 방향과 A-B-D의 방향이 반대여야 함
        // 동시에 C-D-A의 방향과 C-D-B의 방향이 반대여야 함
        long abc = CCW(a, b, c);
        long abd = CCW(a, b, d);
        long cda = CCW(c, d, a);
        long cdb = CCW(c, d, b);

        // A-B-C-D가 일직선상에 놓였을 경우
        if (abc == 0 && abd == 0 && cda == 0 && cdb == 0)
        {
            return Overlap(a, b, c, d);
        }

        // abc * abd <= 0 && cda * cdb <= 0일 시 교차하는 것
        // 직접 계산 시 범위가 초과되기 때문에 이렇게 판단해야함
        return ((abc <= 0 && abd >= 0) || (abc >= 0 && abd <= 0)) && ((cda <= 0 && cdb >= 0) || (cda >= 0 && cdb <= 0));
    }

    // 모든 점이 일직선에 놓였을 경우.
    static bool Overlap(Point a, Point b, Point c, Point d)
    {
        var aMinX = Math.Min(a.x, b.x);
        var aMaxX = Math.Max(a.x, b.x);
        var aMinY = Math.Min(a.y, b.y);
        var aMaxY = Math.Max(a.y, b.y);
        var cMinX = Math.Min(c.x, d.x);
        var cMaxX = Math.Max(c.x, d.x);
        var cMinY = Math.Min(c.y, d.y);
        var cMaxY = Math.Max(c.y, d.y);
        // a-b / c-d 또는 c-d / a-b 형태인 경우 (안겹침)
        if (aMaxX < cMinX || cMaxX < aMinX) return false;
        if (aMaxY < cMinY || cMaxY < aMinY) return false;
        return true;
    }


    static void _Main()
    {
        var l = Console.ReadLine().Split().Select(long.Parse).ToArray();
        Point A = new(l[0], l[1]);
        Point B = new(l[2], l[3]);
        l = Console.ReadLine().Split().Select(long.Parse).ToArray();
        Point C = new(l[0], l[1]);
        Point D = new(l[2], l[3]);

        if (Intersect(A, B, C, D)) Console.Write(1); else Console.Write(0);
    }
}