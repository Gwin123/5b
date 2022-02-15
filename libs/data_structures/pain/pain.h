//
// Created by DNS on 15.02.2022.
//

#ifndef LAST_PAIN_H
#define LAST_PAIN_H

#include "../fraction/fraction.h"
#include <stdbool.h>

typedef struct matrix {
    fraction **values;       // элементы матрицы
    int nRows;          // количество рядов
    int nCols;          // количество столбцов
} matrix;

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

bool isTwoMatricesEqual(matrix m1, matrix m2);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);


#endif //LAST_PAIN_H
