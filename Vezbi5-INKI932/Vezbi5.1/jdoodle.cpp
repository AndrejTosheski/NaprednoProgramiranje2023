#include <iostream>
#include <cstring>

using namespace std;

void replaceCharactersName(char *ime) 
{
    char symbols[] = "{^&}";
    for (int i = 0; i < 4; i++) 
    {
        *(ime + i) = symbols[i];
    }
}

void replaceCharactersSurname(char *prezime) 
{
    char symbols[] = "%$&*";
    for (int i = 0; i < 4; i++) 
    {
        *(prezime + i) = symbols[i];
    }
}

int main() 
{
    char Ime[] = "Andrej";
    char Prezime[] = "Tosheski";
    
    cout << Ime << endl;
    
    replaceCharactersName(Ime);
    cout <<endl;
    cout << Ime << endl;
    cout <<endl;
    cout << Prezime << endl;
    cout <<endl;
    replaceCharactersSurname(Prezime);
    
    cout << Prezime << endl;
    return 0;
}
