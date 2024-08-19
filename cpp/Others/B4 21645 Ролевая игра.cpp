#include <iostream>

using namespace std;

int main(){
    
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n,m,k,answer;

    cin >> n >> m >> k;

    if (m<k){
    answer = n*m;
    }
    else{answer = (n*(m/k)) + ((k-1)*n);}
    cout << answer << endl;

}
