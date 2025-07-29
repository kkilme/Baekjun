// 2025-07-30 괄호 추가하기
// 구현 / 브루트포스
class P16637
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());

    static void Main()
    {
        int n = int.Parse(sr.ReadLine());
        int m = (n - 1) / 2;
        string s = sr.ReadLine();

        int[] nums = new int[m + 1];
        char[] ops = new char[m];

        for (int i = 0; i < m; i++)
        {
            nums[i] = s[i * 2] - '0';
            ops[i] = s[i * 2 + 1];
        }
        nums[m] = s[n - 1] - '0';

        int answer = int.MinValue;

        for (int mask = 0; mask < (1 << m); mask++)
        {
            if ((mask & (mask << 1)) != 0) continue; // 2개 이상 비트가 1이면 겹치는 괄호. ((a+b)+c)
            List<int> nums2 = new(); // 실제 계산할 수
            List<char> ops2 = new(); // 실제 계산할 연산자
            int i = 0;
            for (; i < m; i++)
            {
                if ((mask & (1 << i)) != 0) // 연산자에 괄호 적용
                {
                    nums2.Add(calc(nums[i], nums[i + 1], ops[i]));
                    if (i + 1 < m) ops2.Add(ops[i + 1]);
                    i++;
                }
                else
                {
                    nums2.Add(nums[i]);
                    ops2.Add(ops[i]);
                }
            }
            if (i == m) nums2.Add(nums[m]);

            int result = nums2[0];
            for (int j = 0; j < ops2.Count; j++)
            {
                result = calc(result, nums2[j + 1], ops2[j]);
            }


            answer = Math.Max(answer, result);
        }

        Console.WriteLine(answer);
    }

    static int calc(int a, int b, char op)
    {
        return op switch
        {
            '+' => a + b,
            '-' => a - b,
            '*' => a * b,
        };
    }
}