// 2025-10-27 좋은 단어
// 자료 구조 / 스택
// 다른 방식으로 풀 수 있었겠지만 스택을 쓰면 된다는 발상을 하지 못함
class P3986
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            var s = sr.ReadLine();
            Stack<char> st = new();

            foreach (var c in s)
            {
                if (st.Count == 0) st.Push(c);
                else if (c == 'A')
                {
                    if (st.Peek() == 'A') st.Pop();
                    else st.Push(c);
                }
                else
                {
                    if (st.Peek() == 'B') st.Pop();
                    else st.Push(c);
                }
            }

            if (st.Count == 0) cnt++;
        }

        Console.Write(cnt);
    }
}