/*Write a program that reads a student name followed by five test scores. The program should output the
student’s name, the five test scores, and the average test score. Output the average test score with two
decimal places.*/

#include <iostream>
#include <iomanip>   
using namespace std;
int main()
{
    string first_name, last_name;
    float score_1, score_2, score_3, score_4, score_5;
    cout << "Enter the student name and five test scores: ";
    cin >> first_name >> last_name >> score_1 >> score_2 >> score_3 >> score_4 >> score_5;

    float average_score = (score_1 + score_2 + score_3 + score_4 + score_5) / 5;
    cout << fixed << setprecision(2);
    cout << "student name: " << first_name << " " << last_name << endl;
    cout << "test scores: " << score_1 << " " << score_2 << " " << score_3 << " " << score_4 << " " << score_5 << endl;
    cout << "average test score: " << average_score << endl;

    return 0;
}
