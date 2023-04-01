#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

const int NUM_SUITS = 4;
const int NUM_RANKS = 13;
const int NUM_JOKERS = 2;

struct Card {
    string suit;
    string rank;
};

// Kreiranje na spilot
vector<Card> createDeck() {
    vector<Card> deck;
    string suits[NUM_SUITS] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    string ranks[NUM_RANKS] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    for (int s = 0; s < NUM_RANKS; s++) {
        for (int r = 0; r < NUM_SUITS; r++) {
            Card c = {suits[r], ranks[s]};
            deck.push_back(c);
        }
    }

    Card bj = {"Black", "Joker"};
    deck.push_back(bj);
    Card rj = {"Red", "Joker"};
    deck.push_back(rj);

    return deck;
}


// Funkcija za pecatenje na spilot
void printDeck(const vector<Card>& deck) {
    for (const auto& card : deck) {
        cout << card.rank << " of " << card.suit << endl;
    }
}

// Funckija za mesanje na silot
void shuffleDeck(vector<Card>& deck) {
    srand(time(0));
    for (int i = 0; i < 100; i++) {
        int index1 = rand() % deck.size();
        int index2 = rand() % deck.size();
        swap(deck[index1], deck[index2]);
    }
}

// Funckija za delenje na kartite na 4 igraci
void dealCards(const vector<Card>& deck) {
    const int NUM_CARDS_PER_PLAYER = deck.size() / 4;
    int cardIndex = 0;
    
    for (int p = 1; p <= 4; p++) {
        cout << "Player " << p << ":" << endl;
        for (int c = 0; c < NUM_CARDS_PER_PLAYER; c++) {
            cout << deck[cardIndex].rank << " of " << deck[cardIndex].suit << "\n";
            cardIndex++;
        }
        cout << endl;
    }
}

int main() {
    vector<Card> deck = createDeck();
    
    cout << "Sorted deck of cards:" << endl;
    printDeck(deck);
    
    shuffleDeck(deck);
    
    cout << "\nShuffled deck of cards:" << endl;
    printDeck(deck);
    
    cout << "\nDealing cards to players:" << endl;
    dealCards(deck);
    
    return 0;
}
