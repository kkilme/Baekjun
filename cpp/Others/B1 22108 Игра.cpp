#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        bool k = true;
        cin >> n;
        int arr[n][n];
        for (int j = 0; j < n; j++)
        {
            for (int p = 0; p < n; p++)
            {
                cin >> arr[j][p];
                if (arr[j][p] == 0){k = false;}
            }
        }

        while (k)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - 1; j++)
                {
                    if (arr[i][j] == arr[i][j + 1]){k = false;}
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n-1; j++)
                {
                    if (arr[j][i] == arr[j+1][i]){k = false;}
                }
            }
            break;
        }

        if (k){cout << "NO" << "\n";}
        else {cout << "YES" << "\n";}
    }
}