#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

void Game::addKid(const Kid k1) {
 	kids.push_back(k1);
}

list<Kid> Game::getKids() const {
	return this->kids;
}

void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

//=============================================================================
// Exercise 6: Pim Pam Pum
//=============================================================================
// Subexercise 6.1: Loose Game
//=============================================================================
// TODO
Kid Game::loseGame(string phrase) {
    unsigned int n_word = numberOfWords(phrase);
    list<Kid>::iterator it;
    int nextPos = 0;
    while (kids.size() > 1) {
        if (n_word % kids.size() == 0) {
            kids.pop_back();
        }
        else {
            nextPos = n_word % kids.size() - 1;
            it = next(kids.begin(), nextPos);
            it = kids.erase(it);
        }
    }
    return kids.front();
    //Only passes te 1st test
}


//=============================================================================
// Subexercise 6.2: Rearrange
//=============================================================================
// TODO
list<Kid> Game::rearrange() {
    list<Kid> res;
    return res;
}


//=============================================================================
// Subexercise 6.3: Shuffle
//=============================================================================
// TODO
list<Kid> Game::shuffle() const {
    list<Kid> newList;
    return newList;
}