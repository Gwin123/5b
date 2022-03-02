//
// Created by DNS on 02.03.2022.
//

#ifndef LAST_DELETEMATCHESWITHTHELASTWORD_H
#define LAST_DELETEMATCHESWITHTHELASTWORD_H

#include "../string_.h"

void deleteMatchesWithTheLastWord(char *s) {
    WordDescriptor lastWord;
    bool isLast = getWordReverse(getEndOfString(s), s - 1, &lastWord);

    if (!isLast)
        return;

    char *beginSearch = s;
    char *beginCopy = s;
    WordDescriptor currentWord;
    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, lastWord) != 0) {
            beginCopy = copy(currentWord.begin, currentWord.end, beginCopy);
            *beginCopy++ = ' ';
        }

        beginSearch = currentWord.end;
    }
    if (beginCopy != s)
        --beginCopy;

    *beginCopy = '\0';
}

void test_deleteMatchesWithTheLastWord_someLastWords() {
    char s[] = "Hello World Hello Hello Book Hello";
    deleteMatchesWithTheLastWord(s);
    ASSERT_STRING("World Book", s);
}

void test_deleteMatchesWithTheLastWord_equalWords() {
    char s[] = "Hello Hello Hello Hello";
    deleteMatchesWithTheLastWord(s);
    ASSERT_STRING("", s);
}

void test_deleteMatchesWithTheLastWord_oneWord() {
    char s[] = "Hello";
    deleteMatchesWithTheLastWord(s);
    ASSERT_STRING("", s);
}

void test_deleteMatchesWithTheLastWord_empty() {
    char s[] = "";
    deleteMatchesWithTheLastWord(s);
    ASSERT_STRING("", s);
}

void test_deleteMatchesWithTheLastWord() {
    test_deleteMatchesWithTheLastWord_someLastWords();
    test_deleteMatchesWithTheLastWord_oneWord();
    test_deleteMatchesWithTheLastWord_empty();
    test_deleteMatchesWithTheLastWord_equalWords();
}

#endif //LAST_DELETEMATCHESWITHTHELASTWORD_H
