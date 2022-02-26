//
// Created by DNS on 25.02.2022.
//

#ifndef LAST_REMOVEEXTRASPACES_H
#define LAST_REMOVEEXTRASPACES_H

#include "../string_.h"
#include <ctype.h>

void removeExtraSpaces(char *s) {
    char *begin = s;
    char *dst = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ')
            *dst++ = *begin;

        last = *begin++;
    }
    if (last == ' ')
        dst--;

    *dst = '\0';
}

void test_removeExtraSpaces_spacesBetweenBeforeAfterWords() {
    char s[] = "    Hello  World   42    ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hello World 42", s);
}

void test_removeExtraSpaces_oneWord() {
    char s[] = "   Hello  ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hello", s);
}

void test_removeExtraSpaces_spacesBeforeWords() {
    char s[] = "   Hello  ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hello", s);
}

void test_removeExtraSpaces_noSpaces() {
    char s[] = "Hi123";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeExtraSpaces_emptyString() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_allSpaces() {
    char s[] = "            ";
    removeExtraSpaces(s);
    ASSERT_STRING("            ", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_spacesBeforeWords();
    test_removeExtraSpaces_spacesBetweenBeforeAfterWords();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_oneWord();
    test_removeExtraSpaces_allSpaces();
}


#endif //LAST_REMOVEEXTRASPACES_H

