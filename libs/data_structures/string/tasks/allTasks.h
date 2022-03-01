//
// Created by DNS on 25.02.2022.
//

#ifndef LAST_ALLTASKS_H
#define LAST_ALLTASKS_H

#include "removeNonLetters.h"
#include "removeExtraSpaces.h"
#include "removeAdjacentEqualLetters.h"
#include "digitToStartWithoutChangingTheOrder.h"
#include "spaceAfterEveryFigure.h"
#include "isWordsOrdered.h"
#include "reverseWordsInString.h"
#include "countOfPalindorme.h"

void allTests() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_removeAdjacentEqualLetters();
    test_digitToStartForEveryWord();
    test_spaceAfterEveryFigure();
    test_isWordsOrdered();
//    test_reverseWords();
    test_countOfPalindrome();
}

#endif //LAST_ALLTASKS_H
