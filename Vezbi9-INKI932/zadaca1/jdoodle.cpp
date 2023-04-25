#include <iostream>
#include <ctype.h>
using namespace std;

int main() 
{
    string sentence;
    int lowercase = 0, uppercase = 0, numbers = 0, specialCharacters = 0, stringLength = 0;
    cout << "Write a sentence: ";
    getline(cin, sentence);
    stringLength = sentence.length();

    for(int i = 0; i < stringLength; i++) 
    {
        if(islower(sentence[i])) {
            lowercase++;
        }else if(isupper(sentence[i])){
            uppercase++;
        }else if(isdigit(sentence[i])){
            numbers++;
        }else{
            specialCharacters++;
        }
    }

    cout << "The sentence contains: " << endl;
    cout << lowercase << " lowercase letters" << endl;
    cout << uppercase << " uppercase letters" << endl;
    cout << numbers << " numbers" << endl;
    cout << specialCharacters << " special characters" << endl;
    cout << stringLength << " total characters" << endl;

    return 0;
}