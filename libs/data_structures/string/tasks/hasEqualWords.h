//
// Created by DNS on 03.03.2022.
//

#ifndef LAST_HASEQUALWORDS_H
#define LAST_HASEQUALWORDS_H

#include "../string_.h"

//Определить, есть ли в данной строке одинаковые слова
bool hasEqualWords(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;

    return false;
}

void test_hasEqualWords_LettersHasEqualWords() {
    char s[] = "a b a d e";
    assert(hasEqualWords(s));
}

void test_hasEqualWords_hasEqualWords() {
    char s[] = "Hello World Hello";
    assert(hasEqualWords(s));
}

void test_hasEqualWords_hasNotEqualWords() {
    char s[] = "Hello World Hell";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords_oneWord() {
    char s[] = "Hello";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords_empty() {
    char s[] = "";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords() {
    test_hasEqualWords_hasEqualWords();
    test_hasEqualWords_LettersHasEqualWords();
    test_hasEqualWords_hasNotEqualWords();
    test_hasEqualWords_oneWord();
    test_hasEqualWords_empty();
}

#endif //LAST_HASEQUALWORDS_H
