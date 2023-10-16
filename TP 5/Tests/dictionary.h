#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include <set>
using namespace std;

class WordMean {
    string word;
    string meaning;
public:
    WordMean(string w, string m);
    string getWord() const;
    string getMeaning() const;
    void setMeaning(string m);
    void setWord(string w);
    bool operator < (const WordMean& wm2) const;
};

class Dictionary
{
      set<WordMean> words;
public:
      set<WordMean> getWords() const;
      void addWord(WordMean wm);
      void readFile(ifstream& f);
      string consult(string word1, WordMean& previous, WordMean& next) const;
      bool update(string word1, string mean1);
      void print() const;
};

#endif
