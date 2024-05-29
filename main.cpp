#include "Deck.h"
#include "DeckStack.h"

using namespace std;


int main() {

    DeckStack stack(52);
    stack.displayDeck();
    stack.peek();
    stack.pop();
    stack.displayDeck();
    stack.peek();

//    Deck deck;
//    pass pointers of vector<Card> to methods
//    Deck::displayDeck(&deck.sortedCards);
//    deck.popCardTop(&deck.sortedCards);
//
//    deck.shuffleDeck(&deck.sortedCards);
//    Deck::displayDeck(&deck.shuffledCards);
//    deck.popCardTop(&deck.shuffledCards);

    return 0;
}
