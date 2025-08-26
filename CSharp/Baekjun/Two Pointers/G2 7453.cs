// 2025-08-26 합이 0인 네 정수
// 정렬 / 이분 탐색 / 투 포인터 / 중간에서 만나기

class P7453
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
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
여러 풀이 가능
A. 투 포인터 (첫 시도)
AB와 CD의 합 배열을 각각 만들고 정렬한 뒤, 두 배열을 양끝에서 투 포인터로 스캔해서 합이 0인 구간을 처리.

중요: 중복 원소 처리
AB[i] + CD[j] == 0 이면 AB에서 같은 값이 연속으로 몇 개 있는지 세고, CD에서도 같은 값이 몇 개 있는지 세서 곱만큼 결과에 더하기 (cnt += cntA * cntC)
나중에 알게 된 이걸로 틀린 이유: 투 포인터 반복 조건을 (l<=r)로 함.. (l<n*n &&& r >=0)로 제대로 설정했다면 맞았을 듯..

B. 해시맵(single dictionary) 이용 (O(n^2)) (현재 풀이)
AB_sum = A[i] + B[j]를 전부 계산하면서 Dictionary<int, int> cntAB에 개수만 저장.
그 다음 for each (c,d)에 대해 ans += cntAB.GetValueOrDefault(-(c+d)).

C. 정렬 + 이분탐색
AB_array만(크기 n*n) 만들고 Array.Sort(AB_array).

for i in 0..n-1 for j in 0..n-1: target = -(C[i] + D[j]) → cnt += upper_bound(AB, target) - lower_bound(AB, target). (이분탐색)

*/