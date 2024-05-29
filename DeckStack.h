#ifndef GO_FISH_DECKSTACK_H
#define GO_FISH_DECKSTACK_H

#include <string>
#include <iostream>
#include <vector>
#include "Card.h"

using namespace std;

class DeckStack {
public:
    int topIndex;
    vector<Card> deckOfCards;

    DeckStack(int s) : topIndex(-1) {
        deckOfCards.reserve(52);

        string value[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        string suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

        // concatenate two arrays of value + suit together
        for(const auto & x : value) {
            for (const auto &y : suit) {
                Card card = Card(x, y);
                push(card);
            }
        }
    }

    // for testing
    void displayDeck() {
        cout << "_____DISPLAY DECK STACK_____" << '\n';
        for (int i = 0; i < deckOfCards.size(); i++) {
            cout << deckOfCards[i].getValue() << " of " << deckOfCards[i].getSuit() << ", ";
        }
    }

    void push(const Card& i) {
        cout << "_____PUSH_____" << '\n';
        topIndex = topIndex + 1;
        deckOfCards[topIndex] = i;
        deckOfCards.push_back(i);
        cout << "Element pushed: " << deckOfCards[topIndex].getValue() << " of " << deckOfCards[topIndex].getSuit() << ", topIndex value: " << topIndex << ", Actual stack size: " << deckOfCards.size() << '\n';
    }


    void pop() {
        cout << "_____POP_____" << '\n';
        Card temp = deckOfCards[topIndex];
        deckOfCards.pop_back();
        topIndex = topIndex - 1;
        cout << "Element popped: " << temp.getValue() << " of " << temp.getSuit() << ", topIndex value: " << topIndex << ", Actual stack size: " << deckOfCards.size() << '\n';
    }

    void peek() {
        cout << '\n';
        cout << "_____TOP CARD_____" << '\n';
        cout << "Last element: " << deckOfCards.back().getValue() << " of " << deckOfCards.back().getSuit() << "\n";
    }
};

#endif //GO_FISH_DECKSTACK_H
