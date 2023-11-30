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
    bets.insert(b);
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
// TODO
unsigned Jackpot::betsInNumber(unsigned num) const {
	unsigned counter = 0;
    for (const Bet& bet : bets) {
        vector<int> numbers = bet.getNumbers();
        counter += count(numbers.begin(), numbers.end(), num);
    }
	return counter;
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
// TODO
vector<string> Jackpot::drawnBets(vector<int> draw) const {
	vector<string> res;
    for (const Bet& bet : bets) {
        unsigned matches = 0;
        vector<int> numbers = bet.getNumbers();
        for (int i : numbers) {
            if (find(draw.begin(), draw.end(), i) != draw.end()) {
                matches++;
            }
        }
        if (matches > 3) {
            res.push_back(bet.getPlayer());
        }
    }
	return res;
}
