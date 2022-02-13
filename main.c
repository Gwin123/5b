#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>

void swapRowsWithMaxAndMinValues(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);

    swapRows(m, minPos.rowIndex, maxPos.rowIndex);
}

void test_swapRowsWithMaxAndMinValues_maxAndMinInSameRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 10, 9,
                    4, 5, 6,
                    7, 8, 2
            },
            3, 3);

    swapRowsWithMaxAndMinValues(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 10, 9,
                    4, 5, 6,
                    7, 8, 2
            },
            3, 3);

    assert(twoMatricesEqual(m1, m2));
}

void test_swapRowsWithMaxAndMinValues_maxAndMinInDifferentRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3);

    swapRowsWithMaxAndMinValues(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 9,
                    4, 5, 6,
                    1, 2, 3
            },
            3, 3);

    assert(twoMatricesEqual(m1, m2));
}

void test_swapRowsWithMaxAndMinValues_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1);

    swapRowsWithMaxAndMinValues(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1);

    assert(twoMatricesEqual(m1, m2));
}

void test_swapRowsWithMaxAndMinValues() {
    test_swapRowsWithMaxAndMinValues_maxAndMinInSameRow();
    test_swapRowsWithMaxAndMinValues_maxAndMinInDifferentRows();
    test_swapRowsWithMaxAndMinValues_oneElem();
}

void test_tasks() {
    test_swapRowsWithMaxAndMinValues();
}

int main() {
    test_tasks();
}