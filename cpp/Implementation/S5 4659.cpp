// 2025-01-19 비밀번호 발음하기
// 구현 / 문자열
#include <iostream>
#include <string>
using namespace std;

bool is_vowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    while (true)
    {
        cin >> s;
        if(s == "end") break;

        char prev = ' ';
        bool has_vowel = false;
        bool accpetable = true;
        int streak = 0;
        int vowel_streak = 0;

        for(char c : s){
            bool current_is_vowel = false;
            if(is_vowel(c)){
                has_vowel |= true;
                current_is_vowel = true;
            }

            if(c == prev){
                if(++streak == 2 && c != 'e' && c != 'o'){
                    accpetable = false;
                    break;
                }
            } else {
                streak = 1;
            }

            if(current_is_vowel && is_vowel(prev)){
                if(++vowel_streak == 3){
                    accpetable = false;
                    break;
                }
            } else if(!current_is_vowel && !is_vowel(prev)){
                if(++vowel_streak == 3){
                    accpetable = false;
                    break;
                }
            } else if((current_is_vowel && !is_vowel(prev)) || (!current_is_vowel && is_vowel(prev))){ 
                vowel_streak = 1;
            }

            prev = c;
        }

        string result = accpetable && has_vowel ? "acceptable" : "not acceptable";

        cout << "<" << s << "> is " << result << ".\n";
    }
    
}
