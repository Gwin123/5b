//
// Created by DNS on 01.03.2022.
//

#ifndef LAST_COUNTOFPALINDORME_H
#define LAST_COUNTOFPALINDORME_H

#include <stdio.h>
#include <assert.h>
#include "../string_.h"

bool isPalindrome(char *begin, char *end);

//В данной строке соседние слова разделены запятыми. Определить количество
//слов-палиндромов.
size_t countOfPalindrome(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPal = 0;

    char *commaPos = find(beginSearch, endS, ',');
    bool lastComma = *commaPos == '\0' && endS != beginSearch;
    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);

        countPal += isPalindrome(beginSearch, commaPos);

        beginSearch = commaPos + 1;

        if (lastComma)
            break;

        commaPos = find(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }
    return countPal;
}

//R A D A R
//0 1 2 3 4
//
//P O O P
//0 1 2 3

bool isPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return false;

        begin++;
        end--;
    }
    return true;
}

void test_countOfPalindrome_hasPalindromes() {
    char s[] = "radar, tot, noon, redder, stats, apple, poop";
    assert(countOfPalindrome(s) == 6);
}

void test_countOfPalindrome_oneWord() {
    char s[] = "radar";
    assert(countOfPalindrome(s) == 1);
}

void test_countOfPalindrome_noSpaces() {
    char s[] = "radar,tot,noon,redder,stats,apple,poop";
    assert(countOfPalindrome(s) == 6);
}

void test_countOfPalindrome_oneLetter() {
    char s[] = "a,b,c,d,e,f,g";
    assert(countOfPalindrome(s) == 7);
}

void test_countOfPalindrome() {
    test_countOfPalindrome_hasPalindromes();
    test_countOfPalindrome_noSpaces();
    test_countOfPalindrome_oneLetter();
    test_countOfPalindrome_oneWord();
}


#endif //LAST_COUNTOFPALINDORME_H
