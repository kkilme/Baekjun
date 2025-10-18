// 2025-10-18 큐 2
// 자료 구조 / 큐
using System.Text;

class P18258
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        StringBuilder sb = new();
        List<int> q = new();
        int aliveIdx = 0;
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            string cmd = line[0];
            switch (cmd)
            {
                case "push":
                    q.Add(int.Parse(line[1]));
                    break;
                case "pop":
                    if (q.Count != aliveIdx)
                        sb.AppendLine(q[aliveIdx++].ToString());
                    else
                        sb.AppendLine("-1");
                    break;
                case "size":
                    sb.AppendLine((q.Count - aliveIdx).ToString());
                    break;
                case "empty":
                    sb.AppendLine((q.Count - aliveIdx) == 0 ? "1" : "0");
                    break;
                case "front":
                    if (q.Count != aliveIdx)
                        sb.AppendLine(q[aliveIdx].ToString());
                    else
                        sb.AppendLine("-1");
                    break;
                case "back":
                    if (q.Count != aliveIdx)
                        sb.AppendLine(q[^1].ToString());
                    else
                        sb.AppendLine("-1");
                    break;
            }
        }

        Console.Write(sb.ToString());
    }
}