//player.cpp
//
//Author: Nicholas Taylor
//Date: 11/6/19
//ngt333
//EE312


#include "player.h"
#include "deck.h"
#include "card.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

    Player::Player(){
        unsigned int currentTime = (unsigned)time(NULL);     //Seeds for picking random card in hand
        srand(currentTime);
    }

    Player::Player(string name){
        myName = name;
        unsigned int currentTime = (unsigned)time(NULL);     //Seeds for picking random card in hand
        srand(currentTime);
    }

    void Player::addCard(Card c){
        myHand.push_back(c);
    }

    void Player::bookCards(Card c1, Card c2){
        myBook.push_back(c1);
        myBook.push_back(c2);
    }

    bool Player::checkHandForBook(Card &c1, Card &c2){
        for(unsigned int i = 0; i < myHand.size(); i++){
            for(unsigned int compare = i + 1; compare < myHand.size(); compare++){
                if(myHand[i].getRank() == myHand[compare].getRank()){
                    c1 = myHand[i];
                    c2 = myHand[compare];
                    removeCardFromHand(c1);
                    removeCardFromHand(c2);
                    return true;
                }
            }
        }
        return false;
    }

    bool Player::rankInHand(Card c) const{
        for(unsigned int v = 0; v < myHand.size(); v++){
            if(myHand[v].getRank() == c.getRank()){
                return true;
            }
        }
        return false;
    }

    Card Player::chooseCardFromHand() const{
        int numCards = myHand.size();
        int chosenCard = 0;
        for(int i = rand() % numCards; i > 0; i--){
            chosenCard++;
        }
        return myHand[chosenCard];
    }

    bool Player::cardInHand(Card c) const{
        for(unsigned int v = 0; v < myHand.size(); v++){
            if(myHand[v] == c){
                return true;
            }
        }
        return false;
    }

    Card Player::removeCardFromHand(Card c){
        Card removedCard;
        int index = 0;
        for(std::vector<Card>::iterator it = myHand.begin(); it < myHand.end(); it++){
            if(myHand[index] == c){
                removedCard = myHand[index];
                myHand.erase(it);
                return removedCard;
            }
            index++;
        }
        return removedCard;
    }

    Card Player::removeRankFromHand(Card c){
        Card removedCard;
        int index = 0;
        for(std::vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++){
            if(myHand[index].getRank() == c.getRank()){
                removedCard = myHand[index];
                myHand.erase(it);
                return removedCard;
            }
            index++;
        }
        return removedCard;
    }

    string Player::showHand() const{
        string handString;
        for(unsigned int v = 0; v < myHand.size(); v++){
            handString += (myHand[v].toString() + " ");
        }
        return(handString);
    }

    string Player::showBooks() const{
        string bookString;
        for(unsigned int v = 0; v < myBook.size(); v++){
            bookString += (myBook[v].toString() + " ");
        }
        return(bookString);
    }

    int Player::getHandSize() const{
        return myHand.size();
    }

    int Player::getBookSize() const{
        return myBook.size();
    }
