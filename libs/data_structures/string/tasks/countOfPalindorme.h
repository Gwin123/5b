//
// Created by DNS on 01.03.2022.
//

#ifndef LAST_COUNTOFPALINDORME_H
#define LAST_COUNTOFPALINDORME_H

#include <stdio.h>
#include <assert.h>

bool isPalindrome(char *begin, char *end);

size_t countOfPalindrome(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPal = 0;

    char *commaPos = find(beginSearch, endS, ',');
    bool lastComma = false;
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
}


#endif //LAST_COUNTOFPALINDORME_H
