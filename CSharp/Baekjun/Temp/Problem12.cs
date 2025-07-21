using System;
using System.Text;
using System.IO;
using System.Linq;
using System.Collections.Generic;


public class Problem12
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
            sb.AppendLine($"{a + b}");
        }

        sw.Write(sb.ToString());
        sw.Flush();
        sw.Close();
    }
}