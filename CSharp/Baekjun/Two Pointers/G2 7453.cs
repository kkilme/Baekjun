// 2025-08-26 합이 0인 네 정수
// 정렬 / 이분 탐색 / 투 포인터 / 중간에서 만나기
// 시간 제한 12초인데도 시간 초과로 고생.. 풀이 방향은 처음부터 맞았는데 C++이였다면 바로 통과 가능했을까
class P7453
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        int[] A = new int[n], B = new int[n], C = new int[n], D = new int[n];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();

            A[i] = int.Parse(line[0]);
            B[i] = int.Parse(line[1]);
            C[i] = int.Parse(line[2]);
            D[i] = int.Parse(line[3]);
        }

        int[] AB = new int[n * n];
        Dictionary<int, int> ABcnt = new(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int aa = A[i] + B[j];
                AB[i * n + j] = aa;

                if (ABcnt.ContainsKey(aa)) ABcnt[aa]++;
                else ABcnt[aa] = 1;
            }
        }

        long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cnt += ABcnt.GetValueOrDefault(-(C[i] + D[j]));
            }
        }

        Console.Write(cnt);
    }
}

/*
두가지 풀이 가능
A. 해시맵(single dictionary) 이용 (O(n^2)) (내 풀이)
AB_sum = A[i] + B[j]를 전부 계산하면서 Dictionary<int, int> cntAB에 개수만 저장.
그 다음 for each (c,d)에 대해 ans += cntAB.GetValueOrDefault(-(c+d)).


B. 정렬 + 이분탐색
AB_array만(크기 n*n) 만들고 Array.Sort(AB_array).

for i in 0..n-1 for j in 0..n-1: target = -(C[i] + D[j]) → cnt += upper_bound(AB, target) - lower_bound(AB, target). (이분탐색)
*/