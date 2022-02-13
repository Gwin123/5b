//
// Created by DNS on 10.02.2022.
//

#ifndef LAST_MATRIX_H
#define LAST_MATRIX_H

#include <stdbool.h>

typedef struct matrix {
    int **values;       // элементы матрицы
    int nRows;          // количество рядов
    int nCols;          // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;       // индекс ряда
    int colIndex;       // индекс столбца
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

matrix mulMatrices(matrix m1, matrix m2);

bool isSquareMatrix(matrix m);

bool isEMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

#endif //LAST_MATRIX_H
