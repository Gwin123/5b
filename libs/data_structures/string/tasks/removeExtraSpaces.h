//
// Created by DNS on 25.02.2022.
//

#ifndef LAST_REMOVEEXTRASPACES_H
#define LAST_REMOVEEXTRASPACES_H

#include "../string_.h"
#include <ctype.h>

void removeExtraSpaces(char *s) {
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

void test_removeExtraSpaces_allSpaceSymbols() {
    char s[] = "\t \n    \t \n \t";
    removeExtraSpaces(s);
    ASSERT_STRING(" ", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_allSpaceSymbols();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_emptyString();

}


#endif //LAST_REMOVEEXTRASPACES_H
