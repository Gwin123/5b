//
// Created by DNS on 28.02.2022.
//

#ifndef LAST_REVERSEWORDSINSTRING_H
#define LAST_REVERSEWORDSINSTRING_H

#include "../string_.h"

//Преобразовать строку, изменив порядок следования слов в строке на обратный
void reverseWords(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    char *beginCopy = s;

    char *beginSearch = end - 1;
    WordDescriptor w;
    while (getWordReverse(beginSearch, _stringBuffer - 1, &w)) {
        beginCopy = copy(w.begin, w.end, beginCopy);
        *beginCopy++ = ' ';

        beginSearch -= w.end - w.begin + 1;
        beginSearch = findNonSpaceReverse(beginSearch, _stringBuffer - 1);
    }

    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}

void test_reverseWords_moreLettersInWord() {
    char s[MAX_STRING_SIZE] = "this   task   has   caused me   a lot of pain ";
    reverseWords(s);

    ASSERT_STRING("pain of lot a me caused has task this", s);
}

void test_reverseWords_oneWord() {
    char s[MAX_STRING_SIZE] = "pain";
    reverseWords(s);

    ASSERT_STRING("pain", s);
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
    test_reverseWords_oneLetter();
    test_reverseWords_empty();
    test_reverseWords_oneWord();
}

#endif //LAST_REVERSEWORDSINSTRING_H
