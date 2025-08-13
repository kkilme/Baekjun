// 2025-08-13 가장 긴 증가하는 부분 수열 2
// 이분 탐색 / LIS 문제
class P12015
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        int[] A = sr.ReadLine().Split().Select(int.Parse).ToArray();

        List<int> lis = new();

        foreach (var i in A)
        {
            if (lis.Count == 0 || i > lis[^1]) lis.Add(i);
            else
            {
                // C# 기본 BinarySearch 사용 시
                // int idx = lis.BinarySearch(i);
                /* 만약 리스트에 x가 있으면, x가 있는 인덱스를 반환
                만약 없으면, -(삽입 위치) - 1을 반환
                여기서 삽입 위치는 x 이상이 처음 나오는 위치(lower_bound)
                ~idx 를 통해 비트 반전(1의 보수)하면 원하는 인덱스로 변환됨
                */
                // if (idx < 0) idx = ~idx; 
                // lis[idx] = i;
                int low = 0, high = lis.Count; // 보통 이분탐색은 반열림구간으로 함
                while (low < high) // 반열림 구간 시 조건 l<h. 닫힌 구간이면 l<=h.
                {
                    int mid = (low + high) / 2;
                    if (i <= lis[mid]) high = mid; // 반열림구간으로 할 시 high = mid로 갱신. 닫힌 구간 시 high = mid-1. 또한, lower bound일 때 조건 i <= lis[mid]. upper bound면 i < lis[mid]
                    else low = mid + 1;
                }
                lis[low] = i;
            }
        }

        Console.Write(lis.Count);

    }
}