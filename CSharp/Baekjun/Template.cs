using System.Text;

class P
{
    static StreamReader sr = new StreamReader(Console.OpenStandardInput());
    static StreamWriter sw = new StreamWriter(Console.OpenStandardOutput());
    static StringBuilder sb = new StringBuilder();

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
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