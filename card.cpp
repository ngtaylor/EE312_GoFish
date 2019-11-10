//card.cpp
//
//Author: Nicholas Taylor
//Date: 11/6/19
//ngt333
//EE312


#include <iostream>
#include <string>
#include "card.h"

using namespace std;

    Card::Card(){
        myRank = 1;
        mySuit = spades;
    }

    Card::Card(int rank, Suit s){
        myRank = rank;
        mySuit = s;
    }

    string Card::toString()              const{
        return(rankString(myRank) + suitString(mySuit));
    }

    bool Card::sameSuitAs(const Card& c) const{
        return mySuit == c.mySuit;
    }

    int  Card::getRank()                 const{
        return(myRank);
    }

    void Card::setRank(int r){
        myRank = r;
    }

    void Card::setSuit(Suit s){
        mySuit = s;
    }

    string Card::suitString(Suit s)      const{
        switch(s){
            case spades:
                return("s");
            case hearts:
                return("h");
            case diamonds:
                return("d");
            case clubs:
                return("c");
        }
        return "";
    }

    string Card::rankString(int r)       const{
        switch(r){
            case 1:
                return("A");
            case 2:
                return("2");
            case 3:
                return("3");
            case 4:
                return("4");
            case 5:
                return("5");
            case 6:
                return("6");
            case 7:
                return("7");
            case 8:
                return("8");
            case 9:
                return("9");
            case 10:
                return("10");
            case 11:
                return("J");
            case 12:
                return("Q");
            case 13:
                return("K");
            default:
                return "";
        }
    }

    void Card::swap(Card &c){
    Card tempCard(myRank, mySuit);
    setRank(c.getRank());
    setSuit(c.mySuit);
    c.setSuit(tempCard.mySuit);
    c.setRank(tempCard.getRank());
    }

    bool Card::operator == (const Card& rhs) const{
        return(myRank == rhs.myRank && mySuit == rhs.mySuit);
    }

    bool Card::operator != (const Card& rhs) const{
        return(myRank != rhs.myRank || mySuit != rhs.mySuit);
    }