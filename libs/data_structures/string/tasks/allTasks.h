//
// Created by DNS on 25.02.2022.
//

#ifndef LAST_ALLTASKS_H
#define LAST_ALLTASKS_H

#include "removeNonLetters.h"
#include "removeExtraSpaces.h"
#include "removeAdjacentEqualLetters.h"
#include "digitToStartWithoutChangingTheOrder.h"

void allTests() {
    test_removeNonLetters();
    test_removeExtraSpaces();
    test_removeAdjacentEqualLetters();
    test_digitToStartForEveryWord();
}

#endif //LAST_ALLTASKS_H
