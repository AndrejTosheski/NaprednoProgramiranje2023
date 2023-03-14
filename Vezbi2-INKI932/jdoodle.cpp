#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int DECK_SIZE = 54;
const int SUIT_SIZE = 13;
string suits[6] = {"Hearts", "Diamonds", "Clubs", "Spades", "BLACK JOKER", "RED JOKER"};
string ranks[SUIT_SIZE] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    
    
/*Na pocetok ja zadavame goleminata na spilot, gi zadavame vidot na karti i vrednosta na kartata, algoritmot raboti taka sto vo niza od stringovi so dva vgezdeni for ciklusi
gi spojuvame vidot na kartata so vrednosta od vekje zadadenite nizi od stringovi (pr. 2 of Spades), koga 'i' kje ima vrednost 4 ili 5 togas na kraj gi dodavame samo crniot i crveniot joker,
sledno go pecatime spilot na karti podreden, potoa se povikuva funkcijata shuffleDeck koja go mesa spilot taka sto ja upotrebuvame funkcijata rand() koja generira random broj i go so % od momentalnata golemina
(size) se dobiva ostatokot i toa e random generiraniot broj, otkako kje go dobieme vrsime zamena so pomosna promenliva na momentalnata vrednost od spilot so dobieniot random broj od spilot, i taka
site karti vo spilot kje se izmesaat.
*/
void shuffleDeck(string deck[], int size)   
{
    for (int i = 0; i < size; i++) 
    {
        int j = rand() % size;
        string temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}
int main()
{
    string deck[DECK_SIZE];
    int index = 0;
    for (int i = 0; i < 6; i++)
    {
        if(i == 4 || i == 5){
            deck[index] = suits[i];
            index++;
            continue;
        }
        for (int j = 0; j < SUIT_SIZE; j++)
        {
            deck[index] = ranks[j] + " of " + suits[i];
            index++;
        }
    }
    
    cout<<"PODREDEN: "<<endl;
    for (int i = 0; i < DECK_SIZE; i++)
    {
        cout << deck[i] << endl;
    }
    cout<<endl;
    srand(time(NULL)); 
    shuffleDeck(deck, DECK_SIZE);
    
    cout<<"IZMESAN: "<<endl;
    for (int i = 0; i < DECK_SIZE; i++)
    {
    cout << deck[i] << endl;
    }
    
    return 0 ;
}

