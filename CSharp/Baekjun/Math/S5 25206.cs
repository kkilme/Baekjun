// 2025-09-15 너의 평점은
// 수학 / 구현 / 문자열
class P25206
{
    static StreamReader sr = new(Console.OpenStandardInput());

    static void _Main()
    {
        double creditsum = 0;
        double gradesum = 0;
        for (int i = 0; i < 20; i++)
        {
            var line = sr.ReadLine().Split();
            double credit = double.Parse(line[1]);
            string grade = line[2];
            if (grade == "P") continue;

            double gradenum = grade switch
            {
                "A+" => 4.5,
                "A0" => 4.0,
                "B+" => 3.5,
                "B0" => 3.0,
                "C+" => 2.5,
                "C0" => 2.0,
                "D+" => 1.5,
                "D0" => 1.0,
                "F" => 0.0,
            };

            creditsum += credit;
            gradesum += credit * gradenum;
        }

        double avg = gradesum / creditsum;

        Console.Write(avg);
    }
}