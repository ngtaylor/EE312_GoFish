//go_fish.cpp
//
//Author: Nicholas Taylor
//Date: 11/6/19
//ngt333
//EE312

#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);


int main( )
{
    ofstream oFile;
    oFile.open("go_fish.txt");

    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    cout << "Playing..." << endl;

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    oFile << p1.getName() <<" has : " << p1.showHand() << endl;
    oFile << p2.getName() <<" has : " << p2.showHand() << endl;

    Card c1;                                                                //dummy cards for booking
    Card c2;

    while(p1.checkHandForBook(c1, c2)) {
        oFile << p1.getName() << " books " << c1.rankString(c1.getRank()) << endl;
        p1.bookCards(c1, c2);
    }

    while(p2.checkHandForBook(c1, c2)) {
        oFile << p2.getName() << " books " << c1.rankString(c1.getRank()) << endl;
        p2.bookCards(c1, c2);
    }

    Player *isTurn = &p1;
    Player *notTurn = &p2;

    oFile << "First turn is " << p1.getName();

    //This loop is the game loop and keeps going turn after turn until there are 26 books
    while((p1.getBookSize() + p2.getBookSize()) < 26){
        oFile << endl << endl;

        Card chosenCard = isTurn->chooseCardFromHand();
        oFile << isTurn->getName() << " asks - Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;

        if(notTurn->rankInHand(chosenCard)){
            isTurn->addCard(notTurn->removeRankFromHand(chosenCard));
            oFile << notTurn->getName() << " says - Yes I have a " << chosenCard.rankString(chosenCard.getRank()) << endl;
            if(isTurn->checkHandForBook(c1, c2)) {
                isTurn->bookCards(c1, c2);
                oFile << isTurn->getName() << " books the " << chosenCard.rankString(chosenCard.getRank()) << endl;
                if(isTurn->getHandSize() == 0){
                    Card drawCard = d.dealCard();
                    isTurn->addCard(drawCard);
                    oFile << isTurn->getName() << " is out of cards and draws a " << drawCard.rankString(drawCard.getRank()) << endl;
                }
            }
        } else {
            oFile << notTurn->getName() << " says - Go Fish!" << endl;
            if(d.size() > 0) {
                Card drawCard = d.dealCard();
                isTurn->addCard(drawCard);
                oFile << isTurn->getName() << " draws a " << drawCard.rankString(drawCard.getRank()) << endl;
                if(isTurn->checkHandForBook(c1, c2)){
                    isTurn->bookCards(c1, c2);
                    oFile << isTurn->getName() << " books the " << drawCard.rankString(drawCard.getRank()) << endl;
                    if(isTurn->getHandSize() == 0){
                        drawCard = d.dealCard();
                        isTurn->addCard(drawCard);
                        oFile << isTurn->getName() << " is out of cards and draws a " << drawCard.rankString(drawCard.getRank()) << endl;
                    }
                } else {
                    Player *temp = isTurn;
                    isTurn = notTurn;
                    notTurn = temp;
                }
            }
        }

    }

    oFile << endl;
    oFile << p1.getName() << " has " << p1.getBookSize() << " books" << endl;
    oFile << p2.getName() << " has " << p2.getBookSize() << " books" << endl;

    Player *winner;
    if(p1.getBookSize() > p2.getBookSize()){
        winner = &p1;
    } else {
        winner = &p2;
    }

    oFile << "The winner is " << winner->getName() << "!" << endl;
    oFile.close();

    cout << "Game Over" << endl;

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}