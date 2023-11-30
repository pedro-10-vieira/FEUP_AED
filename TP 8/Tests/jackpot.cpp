#include "jackpot.h"


Bet::Bet(vector<int> ns, string p): numbers(ns), player(p) {}

vector<int> Bet::getNumbers() const {
    return numbers;
}

string Bet::getPlayer() const {
    return player;
}

Jackpot::Jackpot()  {}

unsigned Jackpot::getNumBets() const {
    return bets.size();
}


//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
// Subexercise 2.1: Add Bet
//=============================================================================
// TODO
void Jackpot::addBet(const Bet& b) {
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned count = 0;
	return count;
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
	return res;
}
