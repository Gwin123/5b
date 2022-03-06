//
// Created by DNS on 03.03.2022.
//

#ifndef LAST_GETWORDBEFOREFIRSTWORDWITHA_H
#define LAST_GETWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

//Вывести слово данной строки, предшествующее первому из слов, содержащих
//букву "а".
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    WordDescriptor w1;
    char *begin = s;
    if (!getWord(begin, &w1))
        return EMPTY_STRING;
    else if (find(w1.begin, w1.end, 'A') != w1.end || find(w1.begin, w1.end, 'a') != w1.end)
        return FIRST_WORD_WITH_A;

    begin = w1.end;
    WordDescriptor w2;
    while (getWord(begin, &w2)) {
        if (find(w2.begin, w2.end, 'A') != w2.end || find(w2.begin, w2.end, 'a') != w2.end) {
            *beginWordBefore = w1.begin;
            *endWordBefore = w1.end;

            return WORD_FOUND;
        }
        w1 = w2;
        begin = w2.end;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    char *begin = s;
    char *beginWordBefore, *endWordBefore;

    if (getWordBeforeFirstWordWithA(begin, &beginWordBefore, &endWordBefore) == WORD_FOUND) {
        *endWordBefore = '\0';

        printf("%s\n", beginWordBefore);
    }
}

void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "bc a";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == WORD_FOUND);
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("bc", got);

    char s5[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s5, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}

#endif //LAST_GETWORDBEFOREFIRSTWORDWITHA_H
