//
// Created by DNS on 28.02.2022.
//

#ifndef LAST_REVERSEWORDSINSTRING_H
#define LAST_REVERSEWORDSINSTRING_H

#include "../string_.h"

void reverseWords(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    char *beginCopy = s;

    char *beginSearch = end;
    WordDescriptor word;
    while (getWordReverse(beginSearch, _stringBuffer, &word)) {
        beginCopy = copy(word.begin, word.end, beginCopy);

        beginSearch -= word.end - word.begin;
    }
}

void test_reverseWords_moreLettersInWord() {
    char s[MAX_STRING_SIZE] = "this task has caused me a lot of pain";
    reverseWords(s);

    ASSERT_STRING("pain of lot a me caused has task this", s);
}

void test_reverseWords_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c a b c";
    reverseWords(s);

    ASSERT_STRING("c b a c b a", s);
}

void test_reverseWords_empty() {
    char s[MAX_STRING_SIZE] = "";
    reverseWords(s);

    ASSERT_STRING("", s);
}

void test_reverseWords() {
    test_reverseWords_moreLettersInWord();
//    test_reverseWords_oneLetter();
//    test_reverseWords_empty();
}

#endif //LAST_REVERSEWORDSINSTRING_H
