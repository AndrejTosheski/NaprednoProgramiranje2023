#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Andrej Tosheski INKI932
/*
Vo ovoj kod imame spil na karti koi se mesaat i se delat na igraci. 
Se definiraat dve konstanti CARDS - 52 i FACES - 13.
Se definira struktura "card" so clenovi "face" i "suit". Definirame Card preku typedef od strukturata "card".
Isto taka gi imame funkciite: fillDeck (Koja go popolnuva spilot i gi spojuva "face" i "suit"); shuffle(Koja go mesa spilot na karti) i deal(Koja gi deli kartite od spilot na igracite).
*/

#define CARDS 52
#define FACES 13

// card structure definition
struct card {
   const char *face; // define pointer face
   const char *suit; // define pointer suit
}; // end struct card

typedef struct card Card; // new type name for struct card

// prototypes
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );

int main( void )
{
   Card deck[ CARDS ]; // define array of Cards

   // sto se pravi vo ovoj red ? Definira niza char od pokazuvaci *face[] i se dodavaat vrednostite
   const char *face[] = { "Ace", "Deuce", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Jack", "Queen", "King"};

   // sto se pravi vo ovoj red ? Definira niza char od pokazuvaci *suit[] i i se dodavaat vrednostite
   const char *suit[] = { "Hearts", "Diamonds", "Clubs", "Spades"};

   srand( time( NULL ) ); // sto e ovaa naredba ?
   //Funkcijata srand so argument time( NULL ) e ovozmozeno generiranje na slucaen broj.

   fillDeck( deck, face, suit ); 
   shuffle( deck ); 
   deal( deck ); 
} // end main

// place strings into Card structures
void fillDeck( Card * const wDeck, const char * wFace[],
   const char * wSuit[] )
{
   size_t i; 

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
   } // end for
} // end function fillDeck

// shuffle cards
void shuffle( Card * const wDeck )
{
   size_t i; // sto e ovaa promenliva ?
   size_t j; // sto e ovaa promenliva i vo koi vrednosti se dvizi ? vidi kod 
   Card temp; // define temporary structure for swapping Cards
    // - size_t e data type koja sluzi za golemina na objekti(sizeof) i se koristi kako brojac na brojot na objekti. 
    // 'i' i 'j' se brojaci za for jamkata

   // loop thr
   for ( i = 0; i < CARDS; ++i ) {
      j = rand() % CARDS; // 
      temp = wDeck[ i ];
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;
   } // end for
} // end function shuffle

// deal cards
void deal( const Card * const wDeck )
{
   size_t i; // counter

   // loop through wDeck
   for ( i = 0; i < CARDS; ++i ) {
      printf( "%5s of %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 4 ? "  " : "\n" );
   } // end for
} // end function deal