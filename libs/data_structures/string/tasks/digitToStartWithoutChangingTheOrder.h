//
// Created by DNS on 27.02.2022.
//

#ifndef LAST_DIGITTOSTARTWITHOUTCHANGINGTHEORDER_H
#define LAST_DIGITTOSTARTWITHOUTCHANGINGTHEORDER_H

#include "../string_.h"
#include <ctype.h>

//Преобразовать строку таким образом, чтобы цифры каждого слова были
//перенесены в начало слова без изменения порядка следования их в слове,
//буквы перенести в конец слова
void digitToStartWithoutChangingOrder(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartForEveryWord(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithoutChangingOrder(word);

        beginSearch = word.end;
    }
}

void test_digitToStartForEveryWord_digitsInEnd() {
    char s[] = "ABC123  FCF312";
    digitToStartForEveryWord(s);
    ASSERT_STRING("123ABC  312FCF", s);
}

void test_digitToStartForEveryWord_digitsInWord() {
    char s[] = "A3B2C1       F42C42F42";
    digitToStartForEveryWord(s);
    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartForEveryWord_digitsInStart() {
    char s[] = "321ABC       424242FCF";
    digitToStartForEveryWord(s);
    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartForEveryWord_noDigits() {
    char s[] = "ABC FCF";
    digitToStartForEveryWord(s);
    ASSERT_STRING("ABC FCF", s);
}

void test_digitToStartForEveryWord_noLetters() {
    char s[] = "123 4 56";
    digitToStartForEveryWord(s);
    ASSERT_STRING("123 4 56", s);
}

void test_digitToStartForEveryWord_allSpaces() {
    char s[] = "\n   \t \n";
    digitToStartForEveryWord(s);
    ASSERT_STRING("\n   \t \n", s);
}

void test_digitToStartForEveryWord_emptyString() {
    char s[] = "";
    digitToStartForEveryWord(s);
    ASSERT_STRING("", s);
}

void test_digitToStartForEveryWord() {
    test_digitToStartForEveryWord_digitsInEnd();
    test_digitToStartForEveryWord_digitsInWord();
    test_digitToStartForEveryWord_digitsInStart();
    test_digitToStartForEveryWord_noDigits();
    test_digitToStartForEveryWord_noLetters();
    test_digitToStartForEveryWord_allSpaces();
    test_digitToStartForEveryWord_emptyString();

}

#endif //LAST_DIGITTOSTARTWITHOUTCHANGINGTHEORDER_H
