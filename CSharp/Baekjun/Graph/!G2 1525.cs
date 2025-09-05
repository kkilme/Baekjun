// 2025-09-05 퍼즐
// 자료구조 / 그래프 이론 / 그래프 탐색 / BFS / 집합과 맵 / 해시를 사용한 집합과 맵
// 푸는 아이디어를 떠올리기 어려움
// 3x3 퍼즐로, 가능한 경우의 수가 9!이기 때문에 퍼즐의 상태를 string으로 만들어 원하는 배치가 될 때까지 bfs
class P1525
{
    static void Main()
    {
        string s = "";
        for (int i = 0; i < 3; i++)
        {
            var line = Console.ReadLine().Split();
            for (int j = 0; j < 3; j++)
            {
                s += line[j];
            }
        }

        if (s == "123456780")
        {
            Console.Write(0);
            return;
        }

        HashSet<string> visited = new() { s };

        Queue<(string cur, int idx)> q = new();
        int a = s.IndexOf('0');

        q.Enqueue((s, a));

        int[] di = new int[4] { -1, 1, -3, 3 };

        int count = 0;
        bool done = false;

        while (q.Count != 0 && !done)
        {
            int qC = q.Count;
            for (int k = 0; k < qC && !done; k++)
            {
                var (cur, idx) = q.Dequeue();

                for (int i = 0; i < 4; i++)
                {
                    if (idx % 3 == 0 && di[i] == -1) continue;
                    if (idx % 3 == 2 && di[i] == 1) continue;
                    int ni = idx + di[i];
                    if (ni < 0 || ni > 8) continue;

                    char[] curArr = cur.ToCharArray();

                    var c = curArr[ni];
                    curArr[idx] = c;
                    curArr[ni] = '0';
                    string cur2 = new string(curArr);

                    if (cur2 == "123456780")
                    {
                        done = true;
                        break;
                    }

                    if (visited.Contains(cur2)) continue;

                    visited.Add(cur2);
                    q.Enqueue((cur2, ni));
                }
            }
            count++;
        }

        if (!done)
        {
            Console.Write(-1);
        }
        else
        {
            Console.Write(count);
        }
    }
}