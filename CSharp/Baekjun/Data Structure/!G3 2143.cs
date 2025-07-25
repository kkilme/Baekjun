// 2025-07-26 두 배열의 합
// 자료 구조 / 이분 탐색? / 누적 합 / 해시를 사용한 집합과 맵 / 집합과 맵
// 알고 나니 이걸 왜 못 풀었지 싶은
class P2143
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static void Main()
    {
        int T = int.Parse(sr.ReadLine());
        int n = int.Parse(sr.ReadLine());
        int[] A = sr.ReadLine().Split().Select(int.Parse).ToArray();
        int m = int.Parse(sr.ReadLine());
        int[] B = sr.ReadLine().Split().Select(int.Parse).ToArray();
        List<int> Asums = new();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += A[j];
                Asums.Add(sum);
            }
        }
        List<int> Bsums = new();
        for (int i = 0; i < m; i++)
        {
            int sum = 0;
            for (int j = i; j < m; j++)
            {
                sum += B[j];
                Bsums.Add(sum);
            }
        }

        Dictionary<int, int> cnts = new();
        foreach (var v in Bsums)
        {
            if (cnts.ContainsKey(v)) cnts[v]++;
            else cnts[v] = 1;
        }

        long answer = 0;
        foreach (var v in Asums)
        {
            if (cnts.ContainsKey(T - v)) answer += cnts[T - v];
        }

        Console.WriteLine(answer);
    }
}
