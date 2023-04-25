#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    srand(time(0));
    int randomNumber = rand() % 100 + 1; // +1 za da pocnuva od 1 namesto od 0
    int guess;
    int attempts = 0;
    bool isCorrect = false;

    while (!isCorrect) 
    {
        cout << "Pogodi go brojot od 1 do 100: ";
        cin >> guess;
        attempts++;

        if (guess == randomNumber){
            isCorrect = true;
            cout << "Correct! Total of " << attempts << " attempts." << endl;
            
        }else if (guess < randomNumber){
            cout << "Your guess is smaller than the number, try again!" << endl;
        }else{
            cout << "Your guess is greater than the number, try again!" << endl;
        }
    }

    return 0;
}