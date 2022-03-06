//
// Created by DNS on 27.02.2022.
//

#ifndef LAST_ISWORDSORDERED_H
#define LAST_ISWORDSORDERED_H

#include <stdbool.h>
#include "../string_.h"
#include <assert.h>

//Определить, упорядочены ли лексикографически слова данного предложения
bool isWordsOrdered(char *s) {
    char *beginSearch = s;
    WordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return true;

    WordDescriptor previousWord = currentWord;
    beginSearch = previousWord.end;

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

void test_isWordsOrdered_unorderedLastLetterAreDifferent() {
    char s[] = "bananz bananf";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_orderedLastLetterAreDifferent() {
    char s[] = "bananf bananz";
    assert(isWordsOrdered(s));
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
    test_isWordsOrdered_unorderedLastLetterAreDifferent();
    test_isWordsOrdered_oneLetterOrdered();
    test_isWordsOrdered_oneLetterUnordered();
    test_isWordsOrdered_ordered();
    test_isWordsOrdered_orderedLastLetterAreDifferent();
    test_isWordsOrdered_oneWord();
    test_isWordsOrdered_emptyString();
}


#endif //LAST_ISWORDSORDERED_H
