//
// Created by DNS on 26.02.2022.
//

#ifndef LAST_REMOVEADJACENTEQUALLETTERS_H
#define LAST_REMOVEADJACENTEQUALLETTERS_H

#include "../string_.h"
#include <ctype.h>


//Преобразовать строку, оставляя только один символ
// в каждой последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s) {
    char *begin = s;
    char *dst = begin;
    char last = *begin;
    while (*begin != '\0') {
        if (*begin != last)
            *dst++ = last;

        last = *begin++;
    }
    if (last != '\0')
        *dst++ = last;

    *dst = '\0';
}

void test_removeAdjacentEqualLetters_recurringSymbols() {
    char s[] = " bbbbbbb aaaaaaaaaaa c";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(" b a c", s);
}

void test_removeAdjacentEqualLetters_uniqueSymbol() {
    char s[] = " H e l l o W o r l d ";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(" H e l l o W o r l d ", s);
}

void test_removeAdjacentEqualLetters_spacesSymbols() {
    char s[] = "\t\t \n\n  \t \n";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("\t \n \t \n", s);
}

void test_removeAdjacentEqualLetters_lastSymbolIsUnique() {
    char s[] = "pppaaaiiin";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("pain", s);
}

void test_removeAdjacentEqualLetters_emptyString() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("", s);
}

void test_removeAdjacentEqualLetters_allSpaces() {
    char s[] = "            ";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(" ", s);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_recurringSymbols();
    test_removeAdjacentEqualLetters_uniqueSymbol();
    test_removeAdjacentEqualLetters_spacesSymbols();
    test_removeAdjacentEqualLetters_lastSymbolIsUnique();
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_allSpaces();
}

#endif //LAST_REMOVEADJACENTEQUALLETTERS_H
