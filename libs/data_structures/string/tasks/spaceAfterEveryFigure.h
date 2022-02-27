//
// Created by DNS on 27.02.2022.
//

#ifndef LAST_SPACEAFTEREVERYFIGURE_H
#define LAST_SPACEAFTEREVERYFIGURE_H

#include "../string_.h"
#include <ctype.h>
#define CODE_DIFFERENCE 48

void spaceAfterEveryFigure(char *s) {
    char *endOfString = getEndOfString(s);
    char *startBuffer = _stringBuffer;
    char *endOfBuffer = copy(s, endOfString, startBuffer);
    *endOfBuffer = '\0';

    while (*startBuffer != '\0') {
        if (isalpha(*startBuffer))
            *s++ = *startBuffer;
        else if (isdigit(*startBuffer)) {
            unsigned char a = *startBuffer - CODE_DIFFERENCE;
            while (a--)
                *s++ = ' ';
        }
        startBuffer++;
    }
    *s = '\0';
}

void test_spaceAfterEveryFigure_figuresInWord() {
    char s[MAX_STRING_SIZE] = "A3B0C1";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("A   BC ", s);
}

void test_spaceAfterEveryFigure_AfterBeforeWord() {
    char s[MAX_STRING_SIZE] = "4A3B12E0C1";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("    A   B   EC ", s);
}

void test_spaceAfterEveryFigure_noFigures() {
    char s[MAX_STRING_SIZE] = "ABEC";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("ABEC", s);
}

void test_spaceAfterEveryFigure_noLetters() {
    char s[MAX_STRING_SIZE] = "1234";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("          ", s);
}

void test_spaceAfterEveryFigure_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("", s);
}

void test_spaceAfterEveryFigure() {
    test_spaceAfterEveryFigure_figuresInWord();
    test_spaceAfterEveryFigure_AfterBeforeWord();
    test_spaceAfterEveryFigure_noFigures();
    test_spaceAfterEveryFigure_noLetters();
    test_spaceAfterEveryFigure_emptyString();
}

#endif //LAST_SPACEAFTEREVERYFIGURE_H
