#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funWithCycles.h"

using testing::Eq;

//=============================================================================
// Exercise 1: Palindromes
//=============================================================================

TEST(test_1, examples) {
    cout << "Testando 'palindrome'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    EXPECT_TRUE(FunWithCycles::palindrome("abba"));
    EXPECT_FALSE(FunWithCycles::palindrome("abcdba"));
    EXPECT_TRUE(FunWithCycles::palindrome("reviver"));
    EXPECT_FALSE(FunWithCycles::palindrome("revive"));
}

TEST(test_1, other_true) {
    cout << "  . Outros casos com TRUE como resposta" << endl;
    EXPECT_TRUE(FunWithCycles::palindrome("racecar"));
    EXPECT_TRUE(FunWithCycles::palindrome("madam"));
    EXPECT_TRUE(FunWithCycles::palindrome("level"));
    EXPECT_TRUE(FunWithCycles::palindrome("aaaaaaaaaa"));
    EXPECT_TRUE(FunWithCycles::palindrome("aaabbbcccbbbaaa"));
    EXPECT_TRUE(FunWithCycles::palindrome("z"));
}

TEST(test_1, other_false) {
    cout << "  . Outros casos com FALSE como resposta" << endl;
    EXPECT_FALSE(FunWithCycles::palindrome("ab"));
    EXPECT_FALSE(FunWithCycles::palindrome("aabcaa"));
    EXPECT_FALSE(FunWithCycles::palindrome("abcdeffdecba"));
    EXPECT_FALSE(FunWithCycles::palindrome("racear"));
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================

TEST(test_2, examples) {
    cout << "Testando 'palindromeSentence'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    EXPECT_TRUE(FunWithCycles::palindromeSentence("Madam, I'm Adam"));
    EXPECT_TRUE(FunWithCycles::palindromeSentence("O bolo do   lobo"));
    EXPECT_FALSE(FunWithCycles::palindromeSentence("o bolo d lobo"));
    EXPECT_TRUE(FunWithCycles::palindromeSentence("Anotaram a data da maratona"));
}

TEST(test_2, other_true) {
    cout << "  . Outros casos com TRUE como resposta" << endl;
    EXPECT_TRUE(FunWithCycles::palindromeSentence("ato idiota"));
    EXPECT_TRUE(FunWithCycles::palindromeSentence("Socorram Marrocos"));
    EXPECT_TRUE(FunWithCycles::palindromeSentence("a_BASe_do_teTO_DeSaBa!!$$"));
    EXPECT_TRUE(FunWithCycles::palindromeSentence("A       A24A"));
}

TEST(test_2, other_false) {
    cout << "  . Outros casos com FALSE como resposta" << endl;
    EXPECT_FALSE(FunWithCycles::palindromeSentence("Madam, I'm Aaam"));
    EXPECT_FALSE(FunWithCycles::palindromeSentence("A      BA   A    A"));
    EXPECT_FALSE(FunWithCycles::palindromeSentence("$$C$$D$$C$$D$$"));
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================

TEST(test_3, examples) {
    cout << "Testando 'nextInterestingNumber'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    EXPECT_EQ(95726193, FunWithCycles::nextInterestingNumber(95726184, 42));
    EXPECT_EQ(429999, FunWithCycles::nextInterestingNumber(424242, 42));
    EXPECT_EQ(799, FunWithCycles::nextInterestingNumber(1, 25));
    EXPECT_EQ(319, FunWithCycles::nextInterestingNumber(299, 13));
}

TEST(test_3, other) {
    cout << "  . Outros casos" << endl;
    EXPECT_EQ(8705, FunWithCycles::nextInterestingNumber(8660, 20));
    EXPECT_EQ(4300001, FunWithCycles::nextInterestingNumber(4253816, 8));
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================

TEST(test_4, examples) {
    cout << "Testando 'winter'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    EXPECT_EQ(4, FunWithCycles::winter({23,24,22,21,18,17,17,22,14,13}));
}

TEST(test_4, others) {
    cout << "  . Outros casos" << endl;
    EXPECT_EQ(0, FunWithCycles::winter({1,2,3}));
    EXPECT_EQ(2, FunWithCycles::winter({3,2,1,1,1}));
    EXPECT_EQ(2, FunWithCycles::winter({3,3,3,2,1}));
    EXPECT_EQ(3, FunWithCycles::winter({11,12,11,10,9,10}));
    EXPECT_EQ(5, FunWithCycles::winter({54,45,36,27,18,9}));
    EXPECT_EQ(1, FunWithCycles::winter({1,10,2,9,3,7,4,6,5}));
    EXPECT_EQ(6, FunWithCycles::winter({30,35,30,31,28,25,15,20,15,18,15,13,12,10,5,3,7}));
}


//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
TEST(test_5, count_examples) {
    cout << "Testando 'count'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    EXPECT_EQ(2, FunWithCycles::count({1,2,3,2,6,1,2,2},1));
    EXPECT_EQ(4, FunWithCycles::count({1,2,3,2,6,1,2,2}, 2));
    EXPECT_EQ(1, FunWithCycles::count({1,2,3,2,6,1,2,2}, 3));
    EXPECT_EQ(0, FunWithCycles::count({1,2,3,2,6,1,2,2},4));
}

TEST(test_5, count_other) {
    cout << "  . Outros casos" << endl;
    EXPECT_EQ(2, FunWithCycles::count({17,10,15,15,10,13,14,19,11,14,12,11,19,18,20,14,17,17}, 15));
    EXPECT_EQ(0, FunWithCycles::count({17,10,15,15,10,13,14,19,11,14,12,11,19,18,20,14,17,17}, 16));
    EXPECT_EQ(3, FunWithCycles::count({17,10,15,15,10,13,14,19,11,14,12,11,19,18,20,14,17,17}, 17));
    EXPECT_EQ(1, FunWithCycles::count({17,10,15,15,10,13,14,19,11,14,12,11,19,18,20,14,17,17}, 13));
    EXPECT_EQ(8, FunWithCycles::count({42,42,42,42,42,42,42,42}, 42));
    EXPECT_EQ(0, FunWithCycles::count({42,42,42,42,42,42,42,42}, 41));
}


//=============================================================================
// b) hasDuplicates
TEST(test_5, hasDuplicates_examples) {
    cout << "Testando 'hasDuplicates'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    EXPECT_TRUE(FunWithCycles::hasDuplicates({1,2,3,2,6,1,2,2}));
    EXPECT_FALSE(FunWithCycles::hasDuplicates({2,4,6,8,3,5,7}));
    EXPECT_TRUE(FunWithCycles::hasDuplicates({10,20,30,10}));
}

TEST(test_5, hasDuplicates_other_true) {
    cout << "  . Outros casos com TRUE como resposta" << endl;
    EXPECT_TRUE(FunWithCycles::hasDuplicates({3,5,7,9,11,3}));
    EXPECT_TRUE(FunWithCycles::hasDuplicates({4,5,6,7,7,8,9}));
    EXPECT_TRUE(FunWithCycles::hasDuplicates({1,1,1,1,1,1,1,1,1,1,1}));
    EXPECT_TRUE(FunWithCycles::hasDuplicates({10,70,30,40,50,30,70,80,90}));
}

TEST(test_5, hasDuplicates_other_false) {
    cout << "  . Outros casos com FALSE como resposta" << endl;
    EXPECT_FALSE(FunWithCycles::hasDuplicates({1,2,3,4,5,6}));
    EXPECT_FALSE(FunWithCycles::hasDuplicates({90,10,80,20,30,70,40,60,50}));
    EXPECT_FALSE(FunWithCycles::hasDuplicates({100,42,234,126}));
}


//=============================================================================
// c) removeDuplicates
TEST(test_5, removeDuplicates_examples) {
    cout << "Testando 'removeDuplicates'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    vector<int> v = {1,2,3,2,6,1,2,2};
    FunWithCycles::removeDuplicates(v);
    vector<int> answer = {1,2,3,6};
    EXPECT_EQ(v, answer);
}

TEST(test_5, removeDuplicates_other) {
    cout << "  . Outros casos" << endl;

    vector<int> v1 = {5,1,2,2,2,4,3};
    FunWithCycles::removeDuplicates(v1);
    vector<int> answer1 = {5,1,2,4,3};
    EXPECT_EQ(v1, answer1);

    vector<int> v2 = {42,42,42,42,42,42};
    FunWithCycles::removeDuplicates(v2);
    vector<int> answer2 = {42};
    EXPECT_EQ(v2, answer2);

    vector<int> v3 = {17,10,15,15,10,13,14,19,11,14,12,11,19,18,20,14,17,17};
    FunWithCycles::removeDuplicates(v3);
    vector<int> answer3 = {17,10,15,13,14,19,11,12,18,20};
    EXPECT_EQ(v3, answer3);
}


//=============================================================================
// d) merge
TEST(test_5, merge_examples) {
    cout << "Testando 'merge'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    vector<int> v = FunWithCycles::merge({1, 5, 5, 7}, {2, 3, 6});
    vector<int> answer = {1, 2, 3, 5, 5, 6, 7};
    EXPECT_EQ(v, answer);
}

TEST(test_5, merge_other) {
    cout << "  . Outros casos" << endl;

    vector<int> v1 = FunWithCycles::merge({2, 4, 6, 8}, {10, 12, 14, 16, 18});
    vector<int> answer1 = {2,4,6,8,10,12,14,16,18};
    EXPECT_EQ(v1, answer1);

    vector<int> v2 = FunWithCycles::merge({5,7}, {1,3});
    vector<int> answer2 = {1,3,5,7};
    EXPECT_EQ(v2, answer2);

    vector<int> v3 = FunWithCycles::merge({2,4,6,8,10},
                                          {3,5,7});
    vector<int> answer3 = {2,3,4,5,6,7,8,10};
    EXPECT_EQ(v3, answer3);

    vector<int> v4 = FunWithCycles::merge({11,11,12,12,13,13,13,14,15,18},
                                          {10,10,11,12,13,14,14,15,15,16});
    vector<int> answer4 = {10,10,11,11,11,12,12,12,13,13,13,13,14,14,14,15,15,15,16,18};
    EXPECT_EQ(v4, answer4);
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
TEST(test_6, isPrime_examples) {
    cout << "Testando 'isPrime'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    EXPECT_TRUE(FunWithCycles::isPrime(13));
    EXPECT_FALSE(FunWithCycles::isPrime(15));
    EXPECT_FALSE(FunWithCycles::isPrime(49));
    EXPECT_TRUE(FunWithCycles::isPrime(89));
}

TEST(test_6, isPrime_other_true) {
    cout << "  . Outros casos com TRUE como resposta" << endl;
    EXPECT_TRUE(FunWithCycles::isPrime(2447));
    EXPECT_TRUE(FunWithCycles::isPrime(5003));
    EXPECT_TRUE(FunWithCycles::isPrime(7351));
    EXPECT_TRUE(FunWithCycles::isPrime(3469));
}

TEST(test_6, isPrime_other_false) {
    cout << "  . Outros casos com FALSE como resposta" << endl;
    EXPECT_FALSE(FunWithCycles::isPrime(5027));
    EXPECT_FALSE(FunWithCycles::isPrime(4551));
    EXPECT_FALSE(FunWithCycles::isPrime(1915));
    EXPECT_FALSE(FunWithCycles::isPrime(2279));
}


//=============================================================================
// b) factorize
TEST(test_6, factorize_examples) {
    cout << "Testando 'factorize'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    vector<int> v1 = FunWithCycles::factorize(1176);
    vector<int> answer1 = {2,2,2,3,7,7};
    EXPECT_EQ(v1, answer1);

    vector<int> v2 = FunWithCycles::factorize(3037);
    vector<int> answer2 = {3037};
    EXPECT_EQ(v2, answer2);
}

TEST(test_6, factorize_other) {
    cout << "  . Outros casos" << endl;
    vector<int> v1 = FunWithCycles::factorize(12345);
    vector<int> answer1 = {3,5,823};
    EXPECT_EQ(v1, answer1);

    vector<int> v2 = FunWithCycles::factorize(6877);
    vector<int> answer2 = {13,23,23};
    EXPECT_EQ(v2, answer2);

    vector<int> v3 = FunWithCycles::factorize(5939);
    vector<int> answer3 = {5939};
    EXPECT_EQ(v3, answer3);

    vector<int> v4 = FunWithCycles::factorize(269500);
    vector<int> answer4 = {2,2,5,5,5,7,7,11};
    EXPECT_EQ(v4, answer4);

    vector<int> v5 = FunWithCycles::factorize(5615610);
    vector<int> answer5 = {2,3,5,7,11,11,13,17};
    EXPECT_EQ(v5, answer5);
}


//=============================================================================
// c) listPrimes
TEST(test_6, listPrime_examples) {
    cout << "Testando 'listPrime'" << endl;

    cout << "  . Exemplos do enunciado" << endl;
    vector<int> v = FunWithCycles::listPrimes(100);
    vector<int> answer = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    EXPECT_EQ(v, answer);
}

TEST(test_6, listPrime_other) {
    cout << "  . Outros casos" << endl;

    vector<int> v1 = FunWithCycles::listPrimes(23);
    vector<int> answer1 = {2,3,5,7,11,13,17,19,23};
    EXPECT_EQ(v1, answer1);

    vector<int> v2 = FunWithCycles::listPrimes(178);
    vector<int> answer2 = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,
                           101,103,107,109,113,127,131,137,139,149,151,157,163,167,173};
    EXPECT_EQ(v2, answer2);
}
