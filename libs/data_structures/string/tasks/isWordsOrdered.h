//
// Created by DNS on 27.02.2022.
//

#ifndef LAST_ISWORDSORDERED_H
#define LAST_ISWORDSORDERED_H

#include <stdbool.h>
#include "../string_.h"
#include <assert.h>

bool isWordsOrdered(char *s) {
    char *beginSearch = s;
    WordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return true;

    WordDescriptor previousWord = currentWord;

    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return false;

        previousWord = currentWord;
        beginSearch = currentWord.end;
    }
    return true;
}

void test_isWordsOrdered_oneLetterOrdered() {
    char s[] = "a b c d e";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneLetterUnordered() {
    char s[] = "a b a d e";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_ordered() {
    char s[] = "c c++ java javaScript python ruby";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_unordered() {
    char s[] = "banana banana apple";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_oneWord() {
    char s[] = "banana";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_emptyString() {
    char s[] = "";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered() {
    test_isWordsOrdered_oneLetterOrdered();
    test_isWordsOrdered_oneLetterUnordered();
    test_isWordsOrdered_ordered();
    test_isWordsOrdered_unordered();
    test_isWordsOrdered_oneWord();
    test_isWordsOrdered_emptyString();
}


#endif //LAST_ISWORDSORDERED_H
