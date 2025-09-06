// 2025-09-06 새로운 게임 2
// 구현 / 시뮬레이션
class P17837
{
    class Piece
    {
        public int r, c, dir;
        public Piece(int r, int c, int dir) { this.r = r; this.c = c; this.dir = dir; }
    }

    static StreamReader sr = new(Console.OpenStandardInput());
    static int n, k;
    static int[,] board;

    static Dictionary<(int, int), List<int>> boardStatus = new();
    static List<Piece> pieces = new();

    static void _Main()
    {
        var l = sr.ReadLine().Split();
        n = int.Parse(l[0]);
        k = int.Parse(l[1]);
        board = new int[n, n];
        for (int i = 0; i < n; i++)
        {
            var line = sr.ReadLine().Split();
            for (int j = 0; j < n; j++)
            {
                board[i, j] = int.Parse(line[j]);
                boardStatus.Add((i, j), new());
            }
        }

        for (int i = 0; i < k; i++)
        {
            var l2 = sr.ReadLine().Split();
            int r = int.Parse(l2[0]) - 1, c = int.Parse(l2[1]) - 1;
            pieces.Add(
                new Piece(r, c, int.Parse(l2[2]) - 1)
            );
            boardStatus[(r, c)].Add(i);
        }

        List<(int r, int c)> dirs = new() { (0, 1), (0, -1), (-1, 0), (1, 0) };
        int turn = 0;
        while (++turn < 1002)
        {
            for (int i = 0; i < pieces.Count; i++)
            {
                Piece curPiece = pieces[i];

                int nr = curPiece.r + dirs[curPiece.dir].r;
                int nc = curPiece.c + dirs[curPiece.dir].c;

                if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr, nc] == 2)
                {
                    int d = curPiece.dir;
                    d = d == 0 ? 1 : (d == 1 ? 0 : (d == 2 ? 3 : 2));
                    curPiece.dir = d;

                    nr = curPiece.r + dirs[curPiece.dir].r;
                    nc = curPiece.c + dirs[curPiece.dir].c;

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr, nc] == 2) continue;
                }

                if (Move(i, curPiece, nr, nc))
                {
                    Console.Write(turn);
                    return;
                }
            }
        }

        if (turn < 1001) Console.Write(turn);
        else Console.Write(-1);
    }

    static bool Move(int curturn, Piece piece, int nr, int nc)
    {
        var curList = boardStatus[(piece.r, piece.c)];
        var nextList = boardStatus[(nr, nc)];

        int idx = curList.IndexOf(curturn);

        if (board[nr, nc] == 1)
        {
            for (int i = curList.Count - 1; i >= idx; i--)
            {
                pieces[curList[i]].r = nr;
                pieces[curList[i]].c = nc;
                nextList.Add(curList[i]);
                curList.RemoveAt(i);
            }
        }
        else
        {
            for (int i = idx; i < curList.Count; i++)
            {
                pieces[curList[i]].r = nr;
                pieces[curList[i]].c = nc;
                nextList.Add(curList[i]);
            }
            for (int i = curList.Count - 1; i >= idx; i--)
            {
                curList.RemoveAt(i);
            }
        }

        return nextList.Count >= 4;
    }
}