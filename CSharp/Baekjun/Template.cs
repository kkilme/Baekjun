using System;
using System.Text;
using System.IO;
using System.Linq;
using System.Collections.Generic;


class ProblemTemplate
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
    static StringBuilder sb = new StringBuilder();

    public void Solve()
    {
        int T = int.Parse(sr.ReadLine());
        for (int t = 0; t < T; t++)
        {
            string[] line = sr.ReadLine().Split();
            int a = int.Parse(line[0]);
            int b = int.Parse(line[1]);
        }

        sw.Write(sb.ToString());
        sw.Flush();
        sw.Close();
    }
}

// sw.Flush()는 출력 전 꼭 하기
/*
StringBuilder 적극 활용. Console.WriteLine()을 반복하는 것 보다 훨 빠름.
StringBuilder sb = new StringBuilder();
sb.AppendLine("Hello");
sb.AppendLine("World");
Console.Write(sb.ToString());
*/