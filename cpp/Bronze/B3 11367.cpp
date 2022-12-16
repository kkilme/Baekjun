#include <iostream>
using namespace std;

int main(){

    int n;
    double b;
    cin >> n;
    for(int i =0;i<n;i++){
        string name;
        int score;
        string grade;
        cin >> name >> score;
        if(score >= 97){
            grade = "A+";
        } else if(score >=90){
            grade = "A";
        } else if(score >=87){
            grade = "B+";
        } else if(score >=80){
            grade = "B";
        } else if(score >=77){
            grade = "C+";
        } else if(score >=70){
            grade = "C";
        } else if(score >=67){
            grade = "D+";
        } else if(score >=60){
            grade = "D";
        } else {
            grade = "F";
        }
        cout << name << " " << grade << endl;
    }
}