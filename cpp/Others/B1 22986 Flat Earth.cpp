#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    long long N,K;
    cin >> t;
    for (int i=0; i<t; i++)
    {   
        long long answer = 0;
        cin >> N >> K;
        if (N<K){K = N;}
        answer = ((K+1)*((8*N)-(4*K)))/2;   //등차수열의 합
        cout << answer << "\n";
    }

}
