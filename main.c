#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/matrix/matrix_test.h"
#include "libs/algorithms/algorithms/algorithm.h"

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
    return isEMatrix(mulMatrices(m1, m2));
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
                elemPseudoDiagonal[k] = max(elemPseudoDiagonal[k], m.values[i][j]);
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

        minElem = min(getMin(&m.values[i][jLeft], jRight - jLeft), minElem);
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
}

int main() {
    testMatrix();
    test_tasks();

    return 0;
}
