// 2025-10-21 스택 2
// 자료 구조 / 스택
using System.Text;

class P28278
{
    static StreamReader sr = new(Console.OpenStandardInput());
    static StreamWriter sw = new(Console.OpenStandardOutput());
    static StringBuilder sb = new();

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        List<int> st = new();
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split().Select(int.Parse).ToArray();
            int cmd = line[0];
            switch(cmd){
                case 1:
                    st.Add(line[1]);
                    break;
                case 2:
                    if (st.Count != 0)
                    {
                        sb.AppendLine(st[^1].ToString());
                        st.RemoveAt(st.Count - 1);
                    }
                    else
                    {
                        sb.AppendLine("-1");
                    }
                    break;
                case 3:
                    sb.AppendLine(st.Count.ToString());
                    break;
                case 4:
                    sb.AppendLine(st.Count == 0 ? "1" : "0");
                    break;
                case 5:
                    sb.AppendLine(st.Count == 0 ? "-1" : st[^1].ToString());
                    break;
            }
        }

        sw.Write(sb.ToString());
        sw.Flush();
        sw.Close();
    }
}