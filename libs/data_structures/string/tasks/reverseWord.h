//
// Created by DNS on 01.03.2022.
//

#ifndef LAST_REVERSEWORD_H
#define LAST_REVERSEWORD_H

#include "../string_.h"
#include <stdio.h>

//Вывести слова данной строки в обратном порядке по одному в строке экрана
void reverseWord(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);

    char *begin = s;
    for (int i = 0; i < _bag.size; i++) {
        begin = copyReverse(_bag.words[i].end - 1, _bag.words[i].begin - 1, begin);
        *begin++ = ' ';
    }
    if (begin != s)
        begin--;

    *begin = '\0';
}

void test_reverseWord_moreLettersInWord() {
    char s[MAX_STRING_SIZE] = "this task has caused me a lot of pain";
    reverseWord(s);

    ASSERT_STRING("siht ksat sah desuac em a tol fo niap", s);
}

void test_reverseWord_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c a b c";
    reverseWord(s);

    ASSERT_STRING("a b c a b c", s);
}

void test_reverseWord_empty() {
    char s[MAX_STRING_SIZE] = "";
    reverseWord(s);

    ASSERT_STRING("", s);
}

void test_reverseWord_oneWord() {
    char s[MAX_STRING_SIZE] = "Hello";
    reverseWord(s);

    ASSERT_STRING("olleH", s);
}



void test_reverseWord() {
    test_reverseWord_moreLettersInWord();
    test_reverseWord_oneLetter();
    test_reverseWord_empty();
    test_reverseWord_oneWord();
}

#endif //LAST_REVERSEWORD_H
