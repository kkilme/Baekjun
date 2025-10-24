using System.Text;
// 2025-10-24 국영수
// 정렬
class P10825
{
    static StreamReader sr = new(Console.OpenStandardInput());

    class Student
    {
        public string name;
        public int kor, eng, math;
        public Student(string n, string k, string e, string m)
        {
            name = n;
            kor = int.Parse(k);
            eng = int.Parse(e);
            math = int.Parse(m);
        }
    }

    static void _Main()
    {
        int n = int.Parse(sr.ReadLine());

        List<Student> students = new();

        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            students.Add(new Student(line[0], line[1], line[2], line[3]));
        }

        students.Sort((Student s1, Student s2) =>
        {
            if (s1.kor == s2.kor)
            {
                if (s1.eng == s2.eng)
                {
                    if (s1.math == s2.math)
                    {
                        return s1.name.CompareTo(s2.name);
                    }
                    return s2.math.CompareTo(s1.math);
                }
                return s1.eng.CompareTo(s2.eng);
            }
            return s2.kor.CompareTo(s1.kor);
        });

        StringBuilder sb = new();

        foreach (var s in students)
        {
            sb.AppendLine(s.name);
        }

        Console.Write(sb.ToString());
    }
}