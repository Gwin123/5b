//
// Created by DNS on 04.03.2022.
//

#ifndef LAST_ARELETTERSFIRSTWORDINSECONDSTRING_H
#define LAST_ARELETTERSFIRSTWORDINSECONDSTRING_H

#include "ctype.h"
#include "../string_.h"

bool areLettersFirstWordInSecondString(char *word, char *s) {
    if (*word == '\0' || *s == '\0')
        return false;

    bool isLetterInString[255];
    for (int i = 0; i < 255; i++)
        isLetterInString[i] = false;

    while (*s != '\0') {
        if (isalpha(*s) && !isLetterInString[*s])
            isLetterInString[*s] = true;
        s++;
    }

    while (*word != '\0') {
        if (!isLetterInString[*word])
            return false;

        word++;
    }

    return true;
}

void test_areLettersFirstWordInSecondString_hasEqualLetters() {
    char s[MAX_STRING_SIZE] = "olelh";
    char word[MAX_STRING_SIZE] = "hel";

    assert(areLettersFirstWordInSecondString(word, s));
}

void test_areLettersFirstWordInSecondString_hasNotFullEqualLetters() {
    char s[MAX_STRING_SIZE] = "oreh";
    char word[MAX_STRING_SIZE] = "hel";

    assert(!areLettersFirstWordInSecondString(word, s));
}

void test_areLettersFirstWordInSecondString_moreSpaces() {
    char s[MAX_STRING_SIZE] = "h e o l ";
    char word[MAX_STRING_SIZE] = "hel";

    assert(areLettersFirstWordInSecondString(word, s));
}

void test_areLettersFirstWordInSecondString_wordIsEmpty() {
    char s[MAX_STRING_SIZE] = "oreh";
    char word[MAX_STRING_SIZE] = "";

    assert(!areLettersFirstWordInSecondString(word, s));
}

void test_areLettersFirstWordInSecondString_stringIsEmpty() {
    char s[MAX_STRING_SIZE] = "oreh";
    char word[MAX_STRING_SIZE] = "";

    assert(!areLettersFirstWordInSecondString(word, s));
}

void test_areLettersFirstWordInSecondString() {
    test_areLettersFirstWordInSecondString_hasEqualLetters();
    test_areLettersFirstWordInSecondString_hasNotFullEqualLetters();
    test_areLettersFirstWordInSecondString_wordIsEmpty();
    test_areLettersFirstWordInSecondString_stringIsEmpty();
    test_areLettersFirstWordInSecondString_moreSpaces();
}





#endif //LAST_ARELETTERSFIRSTWORDINSECONDSTRING_H
