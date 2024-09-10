#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;
    string arr[n];
    

    for (int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    int length = arr[0].size();
    string answer = arr[0];

    for (int l = 0; l<length; l++)
    {   
        for (int i = 0; i<n-1; i++)
        {        
            if (arr[i][l] != arr[i+1][l])
            {
                answer[l] = '?';
            }        
        }
    }
    
    cout << answer << endl;
    
    return 0;
    
}
