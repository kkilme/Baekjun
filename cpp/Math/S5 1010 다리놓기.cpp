#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, m;
    long long answer = 1;
    cin >> t;
    for (int i=0; i<t; i++)
    {   
        answer = 1;
        cin >> n >> m;
        if (n>m-n){n=m-n;}
        int k = m-n;
        for (m; m>k; m--){answer *= m;}
        for (n; n>0; n--){answer /= n;}
        cout << answer << "\n";
    }

}
