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
    return Kid();
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
