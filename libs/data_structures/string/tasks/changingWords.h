//
// Created by DNS on 02.03.2022.
//

#ifndef LAST_CHANGINGWORDS_H
#define LAST_CHANGINGWORDS_H

#include "../string_.h"

void changingWords(char *s, char *s1, char *s2) {
    char *beginCopy = s;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            beginCopy = copy(word1.begin, word1.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            beginCopy = copy(word2.begin, word2.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch2 = word2.end;
        }

    }
    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}

void test_changingWords_equalWordCount() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "Hello World", "Wow Beautiful");
    ASSERT_STRING("Hello Wow World Beautiful", s);
}

void test_changingWords_moreWordInFirstString() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "Hello World Beautiful", "Wow");
    ASSERT_STRING("Hello Wow World Beautiful", s);
}

void test_changingWords_moreWordInSecondString() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "Wow", "Hello World Beautiful");
    ASSERT_STRING("Wow Hello World Beautiful", s);
}

void test_changingWords_firstStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "", "Hello World Beautiful");
    ASSERT_STRING("Hello World Beautiful", s);
}

void test_changingWords_secondStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "Hello World Beautiful", "");
    ASSERT_STRING("Hello World Beautiful", s);
}

void test_changingWords_stringsAreEmpty() {
    char s[MAX_STRING_SIZE];
    changingWords(s, " ", " ");
    ASSERT_STRING("", s);
}

void test_changingWords() {
    test_changingWords_equalWordCount();
    test_changingWords_moreWordInFirstString();
    test_changingWords_moreWordInSecondString();
    test_changingWords_firstStringIsEmpty();
    test_changingWords_secondStringIsEmpty();
    test_changingWords_stringsAreEmpty();
}


#endif //LAST_CHANGINGWORDS_H
