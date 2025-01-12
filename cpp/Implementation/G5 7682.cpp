// 2025-01-13 틱택토
// 구현
#include <iostream>
#include <string>
using namespace std;

string s;
char st[3][3];
bool found, Ofound, Xfound;
pair<int, int> ds[8] = {make_pair(0, 1), make_pair(0, -1), make_pair(1, 0), make_pair(-1, 0),
make_pair(1, 1), make_pair(-1, -1), make_pair(1, -1), make_pair(-1, 1)};

void findrow(char letter, int depth, pair<int, int> pos, pair<int,int> direction){
    pos.first += direction.first;
    pos.second += direction.second;
    if(pos.first < 0 || pos.first > 2 || pos.second < 0 || pos.second > 2) return;
    if(st[pos.first][pos.second] != letter) return;
    
    depth++;
    if(depth == 3){
        found = true;
        if(letter == 'O') Ofound = true;
        else if(letter == 'X') Xfound = true;
        return;
    }

    findrow(letter, depth, pos, direction);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> s;
        if(s=="end") break;

        int a, b, c;
        a = b = c = 0;
        for(char cr: s){
            if(cr == 'X') a++;
            if(cr == 'O') b++;
            if(cr == '.') c++;
        }

        if(a < b || a - b > 1) {
            cout << "invalid\n";
            continue;
        }
        
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                st[i][j] = s[i*3 + j];
            }
        }

        found = Ofound = Xfound = false;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                for(int k = 0; k<9; k++){
                    if(st[i][j] != '.') findrow(st[i][j], 1, make_pair(i, j), ds[k]);
                }
            }
        }

        if(Ofound && a>b){
            cout << "invalid\n";
        } 
        else if(Xfound && b>=a){
            cout << "invalid\n";
        }
        else if(found) {
            cout << "valid\n";
        }
        else if(c == 0) {
            cout << "valid\n";
        } 
        else {
            cout << "invalid\n";
        }
    }
    
}