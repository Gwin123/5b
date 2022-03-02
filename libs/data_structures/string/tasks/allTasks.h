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
#include "reverseWord.h"
#include "deleteMatchesWithTheLastWord.h"
#include "changingWords.h"

//TODO 7 11 12 13 14 18 19

void allTests() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_removeAdjacentEqualLetters();
    test_digitToStartForEveryWord();
    test_spaceAfterEveryFigure();
    test_isWordsOrdered();
//    test_reverseWords();
    test_reverseWord();
    test_changingWords();
    test_countOfPalindrome();
    test_deleteMatchesWithTheLastWord();
}

#endif //LAST_ALLTASKS_H
