//deck.cpp
//
//Author: Nicholas Taylor
//Date: 11/6/19
//ngt333
//EE312

#include "card.h"
#include "deck.h"
#include <ctime>
#include <cstdlib>

using namespace std;

    Deck::Deck(){
        for(int i = 0; i < SIZE; i++){
            if(i < 13){
                myCards[i].setSuit(Card::spades);
                myCards[i].setRank(i+1);
            }
            if(i >= 13 && i < 26){
                myCards[i].setSuit(Card::hearts);
                myCards[i].setRank(i-12);
            }
            if(i >= 26 && i < 39){
                myCards[i].setSuit(Card::diamonds);
                myCards[i].setRank(i-25);
            }
            if(i >= 39){
                myCards[i].setSuit(Card::clubs);
                myCards[i].setRank(i-38);
            }
        }
        myIndex = 51;
        unsigned int currentTime = (unsigned)time(NULL);     //Seeds for shuffle
        srand(currentTime);
    }

    void Deck::shuffle(){
        int numCards = size();
        for(int numSwaps = numCards*4; numSwaps > 0; numSwaps--){
            int firstCard = 0;
            int secondCard = 0;
            for(int first = rand() % numCards; first > 0; first--){
                firstCard++;
            }
            for(int second = rand() % numCards; second > 0; second--){
                secondCard++;
            }
            myCards[firstCard].swap(myCards[secondCard]);
        }
    }

    Card Deck::dealCard(){
        Card c = myCards[myIndex];
        myIndex--;
        return(c);
    }

    int  Deck::size() const{
        return myIndex+1;
    }