#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "libs/algorithms/array/array.h"

//================== task 1 ======================

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

//================== task 2 ======================

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMinElement_SquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },
            3, 3);

    assert(twoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElement_rectangleHorizontalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 3,
                    1, 8, 1, 6,
                    3, 2, 3, 8
            },
            3, 4);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 3,
                    1, 8, 1, 6,
                    3, 2, 3, 8
            },
            3, 4);

    assert(twoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElement_rectangleVerticalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
                    6, 2, 1
            },
            4, 3);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    6, 2, 1,
                    7, 1, 2,
                    1, 8, 1
            },
            4, 3);

    assert(twoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElement_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    assert(twoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },
            1, 4);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },
            1, 4);

    assert(twoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },
            4, 1);

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2,
                    4,
                    6,
                    7
            },
            4, 1);

    assert(twoMatricesEqual(m1, m2));
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_rectangleVerticalMatrix();
    test_sortRowsByMinElement_rectangleHorizontalMatrix();
    test_sortRowsByMinElement_SquareMatrix();
    test_sortRowsByMinElement_oneElem();
    test_sortRowsByMinElement_oneRow();
    test_sortRowsByMinElement_oneCol();
}

void test_tasks() {
    test_sortRowsByMinElement();
    test_swapRowsWithMaxAndMinValues();
}

int main() {
    test_tasks();
}