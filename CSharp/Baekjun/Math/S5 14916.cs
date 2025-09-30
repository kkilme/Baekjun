// 2025-09-29 거스름돈
// 수학 / DP? / 그리디?

class P14916
{
    static void _Main()
    {
        int n = int.Parse(Console.ReadLine());

        if (n == 1 || n == 3)
        {
            Console.Write(-1);
            return;
        }

        int quotient = n / 5;
        int remainder = n % 5;

        Console.Write(remainder switch
        {
            0 => quotient,
            2 => quotient + 1,
            3 => quotient + 3,
            _ => quotient + 2
        });
    }
}
/*
int n=int.Parse(Console.ReadLine());
Console.Write((n==1||n==3)?-1:(n%5)switch{0=>n/5,2=>n/5+1,3=>n/5+3,_=>n/5+2});
*/