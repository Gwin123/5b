//
// Created by DNS on 25.02.2022.
//

#ifndef LAST_REMOVENONLETTERS_H
#define LAST_REMOVENONLETTERS_H

#include "../string_.h"
#include <ctype.h>

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_noSpaces() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_withSpacesInWord() {
    char s[] = "H i 12 3";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_withSpaceSymbols() {
    char s[] = "\t H i\t 1\t2 \n 3  \t";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_emptyString() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_allSpaceSymbols() {
    char s[] = "\t \n    \n \t";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_noSpaces();
    test_removeNonLetters_withSpacesInWord();
    test_removeNonLetters_withSpaceSymbols();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_allSpaceSymbols();

}

#endif //LAST_REMOVENONLETTERS_H
