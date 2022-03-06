//
// Created by DNS on 03.03.2022.
//

#ifndef LAST_AREWORDSFROMSAMELETTERS_H
#define LAST_AREWORDSFROMSAMELETTERS_H

#include "../string_.h"
#include "stdlib.h"
#include "hasEqualWords.h"

int cmp(const void *a, const void *b) {
    return *(const char *) a - *(const char *) b;
}

//Определить, есть ли в данной строке пара слов, составленных из одинаковых букв.
bool areWordsFromSameLetters(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);

    for (int i = 0; i < _bag.size; i++)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin, sizeof(char), cmp);

    return hasEqualWords(_stringBuffer);
}

void test_areWordsFromSameLetters_hasThisWords() {
    char s[] = "bananz apple banzan";
    assert(areWordsFromSameLetters(s));
}

void test_areWordsFromSameLetters_hasThisWords2() {
    char s[] = "gognsog gosggon";
    assert(areWordsFromSameLetters(s));
}

void test_areWordsFromSameLetters_hasNotThisWords() {
    char s[] = "bananz apple banvan";
    assert(!areWordsFromSameLetters(s));
}

void test_areWordsFromSameLetters_empty() {
    char s[] = "";
    assert(!areWordsFromSameLetters(s));
}

void test_areWordsFromSameLetters_oneWord() {
    char s[] = "banana";
    assert(!areWordsFromSameLetters(s));
}

void test_areWordsFromSameLetters_differentRegisters() {
    char s[] = "banana bAnana";
    assert(!areWordsFromSameLetters(s));
}

void test_areWordsFromSameLetters() {
    test_areWordsFromSameLetters_hasThisWords();
    test_areWordsFromSameLetters_hasNotThisWords();
    test_areWordsFromSameLetters_hasThisWords2();
    test_areWordsFromSameLetters_empty();
    test_areWordsFromSameLetters_oneWord();
    test_areWordsFromSameLetters_differentRegisters();
}

#endif //LAST_AREWORDSFROMSAMELETTERS_H
