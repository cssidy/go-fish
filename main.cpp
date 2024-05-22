/*
 * Cassidy Arden
 * SDEV-345-81
 * Week 3: Discussion - Go Fish
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

string value[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
string suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

class Card {
public:
    string value;
    string suit;
};

class Deck {
public:
    vector<Card> sortedCards;
    vector<Card> shuffledCards;

    void createDeck() {
        // concatenate two arrays of value + suit together
        for(const auto & x : value) {
            for (const auto & y : suit) {
                Card card;
                card.value = x;
                card.suit = y;
                sortedCards.push_back(card);
            }
        }
    }

    static void displayDeck(vector<Card>* cards) {
        cout << "_____DISPLAY DECK_____" << '\n';
        // print individual cards in deck
        for (int i=0; i<52; i++) {
            // dereference pointer to access its elements
            cout << (*cards)[i].value << " of " << (*cards)[i].suit << '\n';
        }
    }

    // TODO
    void dealCards() {}

    // using the Fisher–Yates shuffle algorithm
    // every permutation of array element equally likely
    // rand() works here but is a subpar random number generator
    void shuffleDeck(vector<Card>* cards) {
        cout << "_____SHUFFLE_____" << '\n';
        int s = cards->size();
        shuffledCards.resize(s );

        // use current time as seed for random number generation
        srand(time(0));
        for (int i = s - 1; i > 0 - 1; --i) {
            int r = rand() % (s - 1);
            swap((*cards)[i], (*cards)[r]);
            shuffledCards[i] = (*cards)[i];
        }
    }

    // because deck is face down, the card on top is actually the last element in vector
    static Card takeCardFromTop(vector<Card>* cards) {
        cout << "_____TOP CARD____" << '\n';
        Card top_card = cards->back();
        cout << "Card on top: " << top_card.value << " of " << top_card.suit << '\n';
        return top_card;
    }
};

void initialize() {
    Deck deck;
    deck.createDeck();

    // pass pointers of vector<Card> to methods
    Deck::displayDeck(&deck.sortedCards);
    Deck::takeCardFromTop(&deck.sortedCards);

    deck.shuffleDeck(&deck.sortedCards);
    Deck::displayDeck(&deck.shuffledCards);
    Deck::takeCardFromTop(&deck.shuffledCards);
}

void input() {}
void update() {}
void render() {}
bool game_is_playing() {
    return true;
}

int main() {

    initialize();

    // TODO
    //    while (game_is_playing()) {
    //        input();
    //        update();
    //        render();
    //    }

    return 0;
}
