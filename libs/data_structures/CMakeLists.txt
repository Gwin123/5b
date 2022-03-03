add_library(
        data_structures

        bitset/bitset.c

        unordered_array/unordered_array_set.c

        ordered_array_set/ordered_array_set.c

        List/list.c

        vector/vector.c

        vector/vectorVoid.c

        matrix/matrix.c
        matrix/matrix_test.c matrix/matrix_test.h

        fraction/fraction.h fraction/fraction.c

        string/string_.c string/string_.h
        string/tasks/removeNonLetters.h
        string/tasks/allTasks.h
        string/tasks/removeExtraSpaces.h
        string/tasks/removeAdjacentEqualLetters.h
        string/tasks/digitToStartWithoutChangingTheOrder.h
        string/tasks/spaceAfterEveryFigure.h string/tasks/isWordsOrdered.h string/tasks/reverseWordsInString.h string/tasks/countOfPalindorme.h string/tasks/reverseWord.h string/tasks/deleteMatchesWithTheLastWord.h string/tasks/changingWords.h string/tasks/hasEqualWords.h)

target_link_libraries(data_structures algorithms)


