#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/matrix/matrix_test.h"
#include "libs/algorithms/algorithms/algorithm.h"
#include <memory.h>

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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_rectangleVerticalMatrix();
    test_sortRowsByMinElement_rectangleHorizontalMatrix();
    test_sortRowsByMinElement_SquareMatrix();
    test_sortRowsByMinElement_oneElem();
    test_sortRowsByMinElement_oneRow();
    test_sortRowsByMinElement_oneCol();
}

//================== task 3 ======================

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement_SquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement_rectangleHorizontalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },
            3, 6);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4
            },
            3, 6);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement_rectangleVerticalMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    4, 8, 1,
                    3, 2, 3,
                    6, 2, 1
            },
            4, 3);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 7,
                    8, 1, 4,
                    2, 3, 3,
                    2, 1, 6
            },
            4, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 2, 4, 6
            },
            1, 4);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, 4, 6, 7
            },
            1, 4);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },
            4, 1);

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7,
                    2,
                    4,
                    6
            },
            4, 1);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_SquareMatrix();
    test_sortColsByMinElement_rectangleHorizontalMatrix();
    test_sortColsByMinElement_rectangleVerticalMatrix();
    test_sortColsByMinElement_oneElem();
    test_sortColsByMinElement_oneRow();
    test_sortColsByMinElement_oneCol();
}

//================== task 4 ======================

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    2, 1, 3
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    54, 17, 21,
                    17, 66, 13,
                    21, 13, 14
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 11, 7,
                    11, 0, 4,
                    7, 4, 22
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    170, 28, 198,
                    28, 137, 165,
                    198, 165, 549
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v3() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    49
            },
            1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix() {
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v1();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v2();
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix_v3();
}

void test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_SymmetricSquareMatrix();
    test_getSquareOfMatrixIfSymmetric_NotSymmetricSquareMatrix();
    test_getSquareOfMatrixIfSymmetric_oneElem();
}

//================== task 6 ======================

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix product = mulMatrices(m1, m2);
    bool isInverse = isEMatrix(product);

    freeMemMatrix(product);

    return isInverse;
}

void test_isMutuallyInverseMatrices_Matrix2x2ProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            },
            2, 2);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, -4,
                    -5, 3
            },
            2, 2);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_Matrix3x3ProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_Matrix4x4ProduceIsEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 1, 0, 0,
                    3, 2, 0, 0,
                    1, 1, 3, 4,
                    2, -1, 2, 3
            },
            4, 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, -1, 0, 0,
                    -3, 2, 0, 0,
                    31, -19, 3, -4,
                    -23, 14, -2, 3
            },
            4, 4);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_Matrix2x2ProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            },
            2, 2);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 4,
                    -5, 3
            },
            2, 2);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_Matrix3x3ProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -1, -1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices_Matrix4x4ProduceIsNotEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2, 1, 0, 1,
                    3, 2, 0, 0,
                    1, 1, 3, 4,
                    2, -1, 2, 3
            },
            4, 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, -1, 0, 0,
                    -3, 2, 0, 0,
                    31, -19, 3, -4,
                    -23, 14, -2, 3
            },
            4, 4);

    assert(!isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_Matrix2x2ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_Matrix3x3ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_Matrix4x4ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_Matrix2x2ProduceIsNotEMatrix();
    test_isMutuallyInverseMatrices_Matrix3x3ProduceIsNotEMatrix();
    test_isMutuallyInverseMatrices_Matrix4x4ProduceIsNotEMatrix();
}

//================== task 5 ======================

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long rowsSums[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowsSums[i] = getSum(m.values[i], m.nCols);

    if (isUnique(rowsSums, m.nRows))
        transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 1,
                    1, 8, 1,
                    3, 1, 3
            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 1, 3,
                    1, 8, 1,
                    1, 1, 3
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_lastsSumIsEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2
            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_oneElem();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_hasNotEqualSum();
    test_transposeIfMatrixHasNotEqualSumOfRows_lastsSumIsEqual();
}

//================== task 7 ======================

#include <limits.h>
#include <math.h>

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int size = m.nRows + m.nCols - 1;
    int elemPseudoDiagonal[size];

    for (int i = 0; i < size; i++)
        elemPseudoDiagonal[i] = INT_MIN;

    elemPseudoDiagonal[m.nRows - 1] = 0; // лежал мусор

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (j != i) {
                int k = j - i + m.nRows - 1;
                elemPseudoDiagonal[k] = max2(elemPseudoDiagonal[k], m.values[i][j]);
            }

    return getSum(elemPseudoDiagonal, size);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -2, -5, -4,
                    -1, -3, -6, -3,
                    -3, -2, -1, -2
            },
            3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -3 + -1 + -2 + -3 + -4);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2,
                    4, 5, 3,
                    1, 5, 7,
                    6, 4, 3
            },
            6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 6 + 4 + 5 + 7 + 3 + 1 + 3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2,
                    -4, -5, -3,
                    -1, -5, -7,
                    -6, -4, -3
            },
            6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -6 + -1 + -3 + -5 + -1 + -1 + -3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2,
            },
            3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 7 + 1 + 1 + 3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2,
            },
            3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -7 + -1 + -1 + -3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3,
                    1,
                    -7,
                    4,
                    -1,
                    6
            },
            6, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, 1, -7, 4, -1, 6
            },
            1, 6);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(m1);
}


void test_findSumOfMaxesOfPseudoDiagonal_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3
            },
            1, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 0);

    freeMemMatrix(m1);
}


void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_oneElem();
    test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix();

}

//================== task 8 ======================

int getMinInArea(matrix m) {
    position minPos = getMaxValuePos(m);
    int minElem = m.values[minPos.rowIndex][minPos.colIndex];

    int jRight = minPos.colIndex;
    int jLeft = minPos.colIndex;
    for (int i = minPos.rowIndex - 1; i >= 0; i--) {
        jLeft = jLeft > 0 ? jLeft - 1 : jLeft;
        jRight = jRight < m.nCols ? jRight + 1 : jRight;

        minElem = min2(getMin(&m.values[i][jLeft], jRight - jLeft), minElem);
    }

    return minElem;
}

void test_getMinInArea_rectangleMatrixMinInBot() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            },
            3, 4);

    assert(getMinInArea(m) == 5);

    freeMemMatrix(m);
}

void test_getMinInArea_rectangleMatrixMinInMiddle() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            },
            3, 4);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

void test_getMinInArea_rectangleVerticalMatrix_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 4,
                    7, 12, 3, 6,
                    10, 11, 5, 15,
                    11, 14, 13, 1,
                    16, 17, 18, 19
            },
            5, 4);

    assert(getMinInArea(m) == 1);

    freeMemMatrix(m);
}

void test_getMinInArea_rectangleVerticalMatrix_2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 4,
                    7, 12, 3, 6,
                    10, 14, 5, 11,
                    11, 1, 13, 15,
                    16, 17, 18, 20
            },
            5, 4);

    assert(getMinInArea(m) == 3);

    freeMemMatrix(m);
}

void test_getMinInArea_oneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6
            },
            1, 1);

    assert(getMinInArea(m) == 6);

    freeMemMatrix(m);
}

void test_getMinInArea_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6,
                    2,
                    8,
                    1,
                    7

            },
            5, 1);

    assert(getMinInArea(m) == 2);

    freeMemMatrix(m);
}

void test_getMinInArea_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    6, 2, 8, 1, 7

            },
            1, 5);

    assert(getMinInArea(m) == 8);

    freeMemMatrix(m);
}


void test_getMinInArea() {
    test_getMinInArea_rectangleMatrixMinInBot();
    test_getMinInArea_rectangleMatrixMinInMiddle();
    test_getMinInArea_rectangleVerticalMatrix_1();
    test_getMinInArea_rectangleVerticalMatrix_2();
    test_getMinInArea_oneElem();
    test_getMinInArea_oneRow();
    test_getMinInArea_oneCol();
}

//================== task 9 ======================

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_sortByDistances_somePoints() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    10, 11, 5, 1,
                    7, 12, 3, 4
            },
            3, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1
            },
            3, 4);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortByDistances_somePoints2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11,
                    0, 1, 2, 3,
                    4, 5, 6, 7
            },
            3, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 1, 2, 3,
                    4, 5, 6, 7,
                    8, 9, 10, 11,
            },
            3, 4);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortByDistances_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11,
            },
            1, 4);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    8, 9, 10, 11
            },
            1, 4);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortByDistances_oneCols() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    11,
                    9,
                    10,
                    2
            },
            4, 1);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2,
                    9,
                    10,
                    11
            },
            4, 1);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortByDistances_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_sortByDistances() {
    test_sortByDistances_somePoints();
    test_sortByDistances_somePoints2();
    test_sortByDistances_oneRow();
    test_sortByDistances_oneCols();
    test_sortByDistances_oneElem();
}

// =============== task 10 ================

int countEqClassesByRowsSum(matrix m) {
    long long rowSums[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowSums[i] = getSum(m.values[i], m.nCols);

    return countNUnique(rowSums, m.nRows);
}

void test_countEqClassesByRowsSum_verticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            },
            6, 2);

    assert(countEqClassesByRowsSum(m1) == 3);

    freeMemMatrix(m1);
}

void test_countEqClassesByRowsSum_horizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7,
                    5, 4, 4, 4,
                    1, 6, 8, 2
            },
            3, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(m1);
}

void test_countEqClassesByRowsSum_onRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7,
            },
            1, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(m1);
}

void test_countEqClassesByRowsSum_onCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2, 7,
            },
            1, 4);

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(m1);
}

void test_countEqClassesByRowsSum_onElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7
            },
            1, 1);

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(m1);
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_verticalRectangleMatrix();
    test_countEqClassesByRowsSum_horizontalRectangleMatrix();
    test_countEqClassesByRowsSum_onRow();
    test_countEqClassesByRowsSum_onCol();
    test_countEqClassesByRowsSum_onElem();

}

// =============== task 11 ================

int getNSpecialElement(matrix m) {
    int countSpecial = 0;
    for (int j = 0; j < m.nCols; j++) {
        int specialElement = m.values[0][j];
        int sumOfCol = 0;
        for (int i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialElement) {
                sumOfCol += specialElement;
                specialElement = m.values[i][j];
            } else
                sumOfCol += m.values[i][j];
        }
        if (specialElement > sumOfCol)
            countSpecial++;
    }
    return countSpecial;
}

void test_getNSpecialElement_rectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4);

    assert(getNSpecialElement(m1) == 2);

    freeMemMatrix(m1);
}

void test_getNSpecialElement_rectangleMatrixHasNotSpecial() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 4,
                    1, 2, 1, 2
            },
            3, 4);

    assert(getNSpecialElement(m1) == 0);

    freeMemMatrix(m1);
}

void test_getNSpecialElement_rectangleVerticalMatrixHasNotSpecial() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5,
                    4, 2, 3,
                    6, 4, 1,
                    2, 1, 2
            },
            4, 3);

    assert(getNSpecialElement(m1) == 0);

    freeMemMatrix(m1);
}

void test_getNSpecialElement_allElementsEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    5, 5, 5,
                    5, 5, 5,
                    5, 5, 5,
                    5, 5, 5
            },
            4, 3);

    assert(getNSpecialElement(m1) == 0);

    freeMemMatrix(m1);
}

void test_getNSpecialElement_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1,
                    2,
                    3,
                    7
            },
            4, 1);

    assert(getNSpecialElement(m1) == 1);

    freeMemMatrix(m1);
}

void test_getNSpecialElement_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 7
            },
            1, 4);

    assert(getNSpecialElement(m1) == 4);

    freeMemMatrix(m1);
}


void test_getNSpecialElement() {
    test_getNSpecialElement_rectangleMatrix();
    test_getNSpecialElement_rectangleMatrixHasNotSpecial();
    test_getNSpecialElement_rectangleVerticalMatrixHasNotSpecial();
    test_getNSpecialElement_allElementsEqual();
    test_getNSpecialElement_oneRow();
    test_getNSpecialElement_oneCol();
}

// task 12

position getLeftMin(matrix m) {
    int min = m.values[0][0];
    position minPos = {0, 0};

    for (int j = 0; j < m.nCols; j++)
        for (int i = 0; i < m.nRows; i++)
            if (m.values[i][j] < min) {
                min = m.values[i][j];
                minPos.colIndex = j;
                minPos.rowIndex = i;
            }

    return minPos;
}

void swapPenultimateRow(matrix m) {
    if (m.nRows < 2) {
        fprintf(stderr, "has not penultimate row");
        exit(43);
    }

    position min = getLeftMin(m);

    int col[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        col[i] = m.values[i][min.colIndex];

    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);
}

void test_swapPenultimateRow_squareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1,
            },
            3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1,
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow_twoRows() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    4, 5
            },
            2, 2);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 4,
                    4, 5
            },
            2, 2);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow_someMinimums() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    4, 2, 1,
                    4, 5, 4,
                    1, 6, 7
            },
            3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 2, 1,
                    4, 4, 1,
                    1, 6, 7
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow_EMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);

    swapPenultimateRow(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    1, 0, 0,
                    0, 0, 1
            },
            3, 3);

    assert(isTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_squareMatrix();
    test_swapPenultimateRow_twoRows();
    test_swapPenultimateRow_someMinimums();
    test_swapPenultimateRow_EMatrix();
}

// task 13

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int counter = 0;
    for (int k = 0; k < nMatrix; k++)
        if (hasAllNonDescendingRows(ms[k]))
            counter++;

    return counter;
}

void test_countNonDescendingRowsMatrices_SquareMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_RectangleMatrixHasSuitableMatrix() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0, 1,
                    1, 3, 2,

                    1, 6, 7,
                    2, 2, 2,

                    -1, 0, 1,
                    2, 1, 2,

                    1, 2, 3,
                    1, 2, 3
            },
            4, 2, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 2);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneRow() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 0, 1,

                    1, 6, 7,

                    -1, 0, 1,

                    1, 2, 3,
            },
            4, 1, 3);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneCol() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0,
                    0,
                    1,

                    1,
                    6,
                    7,

                    -1,
                    0,
                    1,

                    1,
                    2,
                    3,
            },
            4, 3, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_oneElem() {
    matrix *ms = createArrayOfMatrixFromArray(
            (int[]) {
                    0,

                    1,

                    -1,

                    1
            },
            4, 1, 1);

    assert(countNonDescendingRowsMatrices(ms, 4) == 4);

    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_SquareMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_RectangleMatrixHasSuitableMatrix();
    test_countNonDescendingRowsMatrices_oneRow();
    test_countNonDescendingRowsMatrices_oneCol();
    test_countNonDescendingRowsMatrices_oneElem();
}

// task 14

int countZeroRows(matrix m) {
    int zeroCounter = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            zeroCounter++;

    return zeroCounter;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int zeroCount[nMatrix];
    for (int k = 0; k < nMatrix; k++)
        zeroCount[k] = countZeroRows(ms[k]);

    int max = getMax(zeroCount, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (zeroCount[i] == max)
            outputMatrix(ms[i]);
}

void test_countZeroRows_rectangleMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    4, 0, 1,
                    7, 0, 0,
                    0, 0, 0
            },
            4, 3);

    assert(countZeroRows(m) == 2);

    freeMemMatrix(m);
}

void test_countZeroRows_squareZeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3);

    assert(countZeroRows(m) == 3);

    freeMemMatrix(m);
}

void test_countZeroRows_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0,
                    0,
                    1
            },
            3, 1);

    assert(countZeroRows(m) == 2);

    freeMemMatrix(m);
}

void test_countZeroRows_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 1
            },
            1, 3);

    assert(countZeroRows(m) == 0);

    freeMemMatrix(m);
}

void test_countZeroRows_oneColZero() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0
            },
            1, 3);

    assert(countZeroRows(m) == 1);

    freeMemMatrix(m);
}

void test_countZeroRows_oneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0
            },
            1, 1);

    assert(countZeroRows(m) == 1);

    freeMemMatrix(m);
}

void test_countZeroRows() {
    test_countZeroRows_rectangleMatrix();
    test_countZeroRows_squareZeroMatrix();
    test_countZeroRows_oneRow();
    test_countZeroRows_oneCol();
    test_countZeroRows_oneColZero();
    test_countZeroRows_oneElem();
}

//void test() {
//    matrix *ms = createArrayOfMatrixFromArray(
//            (int[]) {
//                    0, 1,
//                    1, 0,
//                    0, 0,
//
//                    1, 1,
//                    2, 1,
//                    1, 1,
//
//                    0, 0,
//                    0, 1,
//                    4, 7,
//
//                    2, 0,
//                    0, 1,
//                    0, 0,
//
//                    0, 1,
//                    0, 2,
//                    0, 3
//            },
//            5, 3, 2);
//
//    printMatrixWithMaxZeroRows(ms, 5);
//}

// task 15

int getMatrixNorm(matrix m) {
    int norm = abs(m.values[0][0]);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (abs(m.values[i][j]) > norm)
                norm = abs(m.values[i][j]);

    return norm;
}

void printMatrixWithMaxNorm(matrix *ms, int nMatrix) {
    int norms[nMatrix];
    for (int k = 0; k < nMatrix; k++)
        norms[k] = getMatrixNorm(ms[k]);

    int min = getMin(norms, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (norms[i] == min)
            outputMatrix(ms[i]);
}

void test_getMatrixNorm_rectangleMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, -7, 11,
                    4, 13, 10,
                    7, -17, 16,
                    12, 1, -56
            },
            4, 3);

    assert(getMatrixNorm(m) == 56);

    freeMemMatrix(m);
}

void test_getMatrixNorm_squareZeroMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3);

    assert(getMatrixNorm(m) == 0);

    freeMemMatrix(m);
}

void test_getMatrixNorm_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2,
                    0,
                    1
            },
            3, 1);

    assert(getMatrixNorm(m) == 2);

    freeMemMatrix(m);
}

void test_getMatrixNorm_oneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 1
            },
            1, 3);

    assert(getMatrixNorm(m) == 1);

    freeMemMatrix(m);
}

void test_getMatrixNorm_oneColZero() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 1, -12
            },
            1, 3);

    assert(getMatrixNorm(m) == 12);

    freeMemMatrix(m);
}

void test_getMatrixNorm_oneElem() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -12
            },
            1, 1);

    assert(getMatrixNorm(m) == 12);

    freeMemMatrix(m);
}

void test_getMatrixNorm() {
    test_getMatrixNorm_rectangleMatrix();
    test_getMatrixNorm_oneElem();
    test_getMatrixNorm_oneColZero();
    test_getMatrixNorm_oneRow();
    test_getMatrixNorm_squareZeroMatrix();
    test_getMatrixNorm_oneCol();
}

// task 17

double getScalarProduct(const int *a, const int *b, int n) {
    double scalarProduct = 0;
    for (int i = 0; i < n; i++)
        scalarProduct += a[i] * b[i];

    return scalarProduct;
}

double getVectorLength(const int *a, int n) {
    double length = 0;
    for (int i = 0; i < n; i++)
        length += a[i] * a[i];

    return sqrt(length);
}

double getCosine(int *a, int *b, int n) {
    double aLength = getVectorLength(a, n);
    double bLength = getVectorLength(b, n);

    if (aLength == 0 || bLength == 0) {
        fprintf(stderr, "Length is a zero");
        exit(1);
    }

    return getScalarProduct(a, b, n) / (aLength * bLength);
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    double maxCornerCos = getCosine(m.values[0], b, m.nCols);
    int maxCornerCosPos = 0;
    for (int i = 0; i < m.nRows; i++) {
        double currentCos = getCosine(m.values[i], b, m.nCols);
        if (currentCos < maxCornerCos) {
            maxCornerCos = currentCos;
            maxCornerCosPos = i;
        }
    }

    return maxCornerCosPos;
}

void test_getVectorIndexWithMaxAngle_positiveCos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 7, 11,
                    4, 13, 10,
                    7, 17, 16,
                    12, 1, 56
            },
            4, 3);

    int v[] = {1, 2, 3};

    assert(getVectorIndexWithMaxAngle(m, v) == 3);

    freeMemMatrix(m);
}

void test_getVectorIndexWithMaxAngle_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 7, 11
            },
            1, 3);

    int v[] = {1, 2, 3};

    assert(getVectorIndexWithMaxAngle(m, v) == 0);

    freeMemMatrix(m);
}


void test_getVectorIndexWithMaxAngle_negativeCos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 7, -11,
                    4, -13, -10,
                    7, -1, -1,
                    12, 1, -56
            },
            4, 3);

    int v[] = {1, 2, 3};

    assert(getVectorIndexWithMaxAngle(m, v) == 1);

    freeMemMatrix(m);
}

//void test_getVectorIndexWithMaxAngle_zeroVector() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    1, 7, 11,
//                    4, 13, 10,
//                    7, 17, 16,
//                    12, 1, 56
//            },
//            4, 3);
//
//    int v[] = {0, 0, 0};
//
//    assert(getVectorIndexWithMaxAngle(m, v) == 3);
//
//    freeMemMatrix(m);
//}

void test_getVectorIndexWithMaxAngle_negativeAndPositiveCos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 7, -11,
                    4, 13, 10,
                    7, 1, 1,
                    12, 1, -6
            },
            4, 3);

    int v[] = {1, 2, 3};

    assert(getVectorIndexWithMaxAngle(m, v) == 0);

    freeMemMatrix(m);
}

void test_getVectorIndexWithMaxAngle_negativeVector() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 7, -11,
                    4, 13, 10,
                    7, 1, 1,
                    12, 1, -6
            },
            4, 3);

    int v[] = {-1, -1, -1};

    assert(getVectorIndexWithMaxAngle(m, v) == 1);

    freeMemMatrix(m);
}

void test_getVectorIndexWithMaxAngle() {
    test_getVectorIndexWithMaxAngle_positiveCos();
    test_getVectorIndexWithMaxAngle_negativeCos();
    test_getVectorIndexWithMaxAngle_negativeAndPositiveCos();
//    test_getVectorIndexWithMaxAngle_zeroVector();
    test_getVectorIndexWithMaxAngle_oneRow();
    test_getVectorIndexWithMaxAngle_negativeVector();
}

// task 16

int getNSpecialElement2(matrix m) {
    int count = 0;

    for (int i = 0; i < m.nRows; i++) {
        int maxV = m.values[i][0];
        for (int j = 0; j < m.nCols; j++) {
            bool left = j == 0 ? true : false;

            if (!left && m.values[i][j] > maxV) {
                left = true;
                maxV = m.values[i][j];
            }

            bool right = m.nCols - 1 == j ? true : false;

            if (!right) {
                int min = getMin(m.values[i] + j + 1, m.nCols - j - 1);
                if (min > m.values[i][j])
                    right = true;
            }
            if (left && right)
                count++;
        }
    }
    return count;
}

void test_getNSpecialElement2_leftAndRightElemIsSpecial() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 3, 8, 12,
                    12, 12, 2, 1, 2
            }, 3, 5
    );

    assert(getNSpecialElement2(testMatrix) == 4);

    freeMemMatrix(testMatrix);
}

void test_getNSpecialElement2_notSpecialElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    4, 3, 5, 5, 4,
                    6, 2, 3, 8, 7,
                    12, 12, 2, 1, 2
            }, 3, 5
    );

    assert(getNSpecialElement2(testMatrix) == 0);

    freeMemMatrix(testMatrix);
}

void test_getNSpecialElement2_oneElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    4
            }, 1, 1
    );

    assert(getNSpecialElement2(testMatrix) == 1);

    freeMemMatrix(testMatrix);
}

void test_getNSpecialElement2_oneRow() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    4, 3, 5, 7, 6
            }, 1, 5
    );

    assert(getNSpecialElement2(testMatrix) == 1);

    freeMemMatrix(testMatrix);
}

void test_getNSpecialElement2_oneCol() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    4,
                    3,
                    5,
                    7,
                    6
            }, 5, 1
    );

    assert(getNSpecialElement2(testMatrix) == 5);

    freeMemMatrix(testMatrix);
}

void test_getNSpecialElement2() {
    test_getNSpecialElement2_leftAndRightElemIsSpecial();
    test_getNSpecialElement2_notSpecialElement();
    test_getNSpecialElement2_oneElement();
    test_getNSpecialElement2_oneRow();
    test_getNSpecialElement2_oneCol();
}

// task 18

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    long long res = 0;

    int colElem[m.nRows];
    for (int iRow = 0; iRow < m.nRows; iRow++)
        colElem[iRow] = m.values[iRow][j];

    for (int jCol = 0; jCol < m.nRows; jCol++) {
        res += colElem[jCol] * m.values[i][jCol];
    }

    return res;
}

long long getSpecialScalarProduct(matrix m) {
    position maxPosRow = getMaxValuePos(m);
    position minPosCol = getMinValuePos(m);

    return getScalarProductRowAndCol(m, maxPosRow.rowIndex, minPosCol.colIndex);
}

void test_getSpecialScalarProduct_positiveElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 3, 4,
                    5, 6, 7,
                    8, 9, 0
            }, 3, 3
    );

    assert(getSpecialScalarProduct(m) == 4 * 8 + 7 * 9);

    freeMemMatrix(m);
}

void test_getSpecialScalarProduct_negativeElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, -3, -4,
                    -5, -10, -7,
                    -8, -9, -2
            }, 3, 3
    );

    assert(getSpecialScalarProduct(m) == -1 * -3 + -3 * -10 + -4 * -9);

    freeMemMatrix(m);
}

void test_getSpecialScalarProduct_minAndMaxInOneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 1, 5,
                    4, 7, 8,
                    6, 3, 2
            }, 3, 3
    );

    assert(getSpecialScalarProduct(m) == 10 * 1 + 1 * 7 + 5 * 3);

    freeMemMatrix(m);
}

void test_getSpecialScalarProduct_minAndMaxInOneCol() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 4, 5,
                    6, 7, 8,
                    1, 3, 2
            }, 3, 3
    );

    assert(getSpecialScalarProduct(m) == 10 * 10 + 4 * 6 + 5 * 1);

    freeMemMatrix(m);
}

void test_getSpecialScalarProduct_oneElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10
            }, 1, 1
    );

    assert(getSpecialScalarProduct(m) == 10 * 10);

    freeMemMatrix(m);
}


void test_getSpecialScalarProduct() {
    test_getSpecialScalarProduct_positiveElements();
    test_getSpecialScalarProduct_negativeElements();
    test_getSpecialScalarProduct_minAndMaxInOneRow();
    test_getSpecialScalarProduct_minAndMaxInOneCol();
    test_getSpecialScalarProduct_oneElement();
}

void test_tasks() {
    test_sortRowsByMinElement();
    test_swapRowsWithMaxAndMinValues();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_getMatrixNorm();
    test_getVectorIndexWithMaxAngle();
    test_getNSpecialElement2();
    test_getSpecialScalarProduct();
}

int main() {
    testMatrix();
    test_tasks();
}
