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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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

    assert(twoMatricesEqual(m1, m2));
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
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_Matrix2x2ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_Matrix3x3ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_Matrix4x4ProduceIsEMatrix();
    test_isMutuallyInverseMatrices_Matrix2x2ProduceIsNotEMatrix();
    test_isMutuallyInverseMatrices_Matrix3x3ProduceIsNotEMatrix();
    test_isMutuallyInverseMatrices_Matrix4x4ProduceIsNotEMatrix();
}

void test_tasks() {
    test_sortRowsByMinElement();
    test_swapRowsWithMaxAndMinValues();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_isMutuallyInverseMatrices();
}

int main() {
    test_tasks();
}