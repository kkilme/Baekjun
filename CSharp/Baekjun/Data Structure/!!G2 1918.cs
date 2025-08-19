// 2025-08-19 후위 표기식
// 자료 구조 / 스택
// 어렵다
using System.Text;

class P1918
{
    static int priority(char op)
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    static void _Main()
    {
        string s = Console.ReadLine().Trim();
        var st = new Stack<char>(); // 스택엔 연산자와 (만 푸시됨
        var sb = new StringBuilder();

        foreach (char ch in s)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                sb.Append(ch); // 피연산자: 바로 출력
            }
            else if (ch == '(')
            {
                st.Push(ch); // ( 는 스택에 바로 푸시
            }
            else if (ch == ')')
            {   // )일 경우: (가 나올때 까지 연산자 출력, (는 버림
                while (st.Count > 0 && st.Peek() != '(')
                    sb.Append(st.Pop());
                if (st.Count > 0 && st.Peek() == '(') st.Pop();
            }
            else
            { // 연산자일 경우: 스택 맨 위 연산자부터 우선순위 비교해서, 우선순위가 같거나 더 높은 연산자들을 꺼내 출력
                while (st.Count > 0 && priority(st.Peek()) >= priority(ch))
                {
                    if (st.Peek() == '(') break;
                    sb.Append(st.Pop());
                }
                st.Push(ch); // 현재 연산자는 스택에 푸시
            }
        }

        while (st.Count > 0)
        { // 남은 연산자 모두 출력
            sb.Append(st.Pop());
        }

        Console.WriteLine(sb.ToString());
    }
}