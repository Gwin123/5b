//
// Created by DNS on 03.03.2022.
//

#ifndef LAST_LASTOFWORDSOFTHEFIRSTSTRINGINTHESECONDSTRING_H
#define LAST_LASTOFWORDSOFTHEFIRSTSTRINGINTHESECONDSTRING_H

#include "../string_.h"

//Даны две строки. Определить последнее из слов первой строки, которое есть
//во второй строке (16, 12)
WordDescriptor getLastWordInFirstStringInTheSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    WordDescriptor word = {NULL, NULL};
    bool isFoundLast = false;
    for (int i = _bag.size - 1; i >= 0 && !isFoundLast; i--)
        for (int j = 0; j < _bag2.size && !isFoundLast; j++)
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                word = _bag.words[i];
                isFoundLast = true;
            }
    return word;
}

void test_getLastWordInFirstStringInTheSecondString_hasWordInStrings() {
    char s1[] = "apple string last first second";
    char s2[] = "first third programming apple";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("first", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings() {
    char s1[] = "apple cinema gaming programming";
    char s2[] = "math programming listening";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("programming", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasNotUnion() {
    char s1[] = "apple cinema gaming programming";
    char s2[] = "math cooking listening";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringInTheSecondString_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringInTheSecondString() {
    test_getLastWordInFirstStringInTheSecondString_hasWordInStrings();
    test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings();
    test_getLastWordInFirstStringInTheSecondString_hasNotUnion();
    test_getLastWordInFirstStringInTheSecondString_emptyStrings();
}


#endif //LAST_LASTOFWORDSOFTHEFIRSTSTRINGINTHESECONDSTRING_H
