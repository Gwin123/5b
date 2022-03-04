//
// Created by DNS on 04.03.2022.
//

#ifndef LAST_ADDLASTWORDSSECONDSTRINGTOFIRSTSTRING_H
#define LAST_ADDLASTWORDSSECONDSTRINGTOFIRSTSTRING_H

#include "../string_.h"

void addLastWordsSecondStringToFirstString_(char *s1, char *s2, size_t size1, size_t size2) {
    size_t difference = size1 - size2;

    char *beginSearch = getEndOfString(s1) - 1;
    WordDescriptor w;
    while (difference--) {
        getWordReverse(beginSearch, s1 - 1, &w);

        beginSearch -= w.end - w.begin + 1;
        beginSearch = findNonSpaceReverse(beginSearch, s1 - 1);
    }
    char *endS2 = getEndOfString(s2);
    *endS2++ = ' ';
    *copy(w.begin, getEndOfString(s1), endS2) = '\0';
}

void addLastWordsSecondStringToFirstString(char *s1, char *s2, size_t size1, size_t size2) {
    if (size1 == size2)
        return;

    if (size1 > size2)
        addLastWordsSecondStringToFirstString_(s1, s2, size1, size2);
    else
        addLastWordsSecondStringToFirstString_(s2, s1, size2, size1);
}

void test_addLastWordsSecondStringToFirstString_firstStringMoreSecond() {
    char s1[MAX_STRING_SIZE] = "Hello Fucking World Bye";
    char s2[MAX_STRING_SIZE] = "Cat Home";

    addLastWordsSecondStringToFirstString(s1, s2, 4, 2);

    ASSERT_STRING("Cat Home World Bye", s2);
}

void test_addLastWordsSecondStringToFirstString_oneWordInFirst() {
    char s1[MAX_STRING_SIZE] = "Hello";
    char s2[MAX_STRING_SIZE] = "Cat Home";

    addLastWordsSecondStringToFirstString(s1, s2, 1, 2);

    ASSERT_STRING("Hello Home", s1);
}

void test_addLastWordsSecondStringToFirstString_oneWordInStrings() {
    char s1[MAX_STRING_SIZE] = "Hello";
    char s2[MAX_STRING_SIZE] = "";

    addLastWordsSecondStringToFirstString(s1, s2, 1, 0);

    ASSERT_STRING("Hello", s1);
}

void test_addLastWordsSecondStringToFirstString_emptyStrings() {
    char s1[MAX_STRING_SIZE] = "";
    char s2[MAX_STRING_SIZE] = "";

    addLastWordsSecondStringToFirstString(s1, s2, 0, 0);

    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}

void test_addLastWordsSecondStringToFirstString_secondStringMoreFirstString() {
    char s1[MAX_STRING_SIZE] = "Cat Home";
    char s2[MAX_STRING_SIZE] = "Hello Fucking World Bye";

    addLastWordsSecondStringToFirstString(s1, s2, 2, 4);

    ASSERT_STRING("Cat Home World Bye", s1);
}

void test_addLastWordsSecondStringToFirstString() {
    test_addLastWordsSecondStringToFirstString_secondStringMoreFirstString();
    test_addLastWordsSecondStringToFirstString_firstStringMoreSecond();
    test_addLastWordsSecondStringToFirstString_oneWordInFirst();
    test_addLastWordsSecondStringToFirstString_oneWordInStrings();
    test_addLastWordsSecondStringToFirstString_emptyStrings();
}

#endif //LAST_ADDLASTWORDSSECONDSTRINGTOFIRSTSTRING_H
