//
// Created by DNS on 14.12.2021.
//

#include <stdio.h>
#include <assert.h>
#include "array.h"
#include <stdlib.h>
#include <math.h>

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *array, size_t *size, const int value) {
    *size += 1;
    array[*size - 1] = value;
}

void deleteIf(int *a, size_t *size, int (*conditional)(int)) {
    int iWrite = 0;
    for (size_t iRead = 0; iRead < *size; iRead++)
        if (!conditional(a[iRead]))
            a[iWrite++] = a[iRead];
    *size = iWrite;
}

bool isEqual(const int a, const int b) {
    return a == b;
}


size_t binarySearch_(const int *a, size_t n, int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }
    return a[left] == x ? left : n;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

//void copyArray(const int *b, const int *a, size_t size) {
//    for (size_t i = 0; i < size; i++)
//        b[i] = a[i];
//}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

int countNUnique(long long *a, int n) {
    if (n == 1)
        return 1;

    qsort(a, n, sizeof(long long), cmp_long_long);

    int counterOfUnique = 1;
    int i = 1;
    while (i < n) {
        if (a[i] != a[i - 1])
            counterOfUnique++;
        i++;
    }

    return counterOfUnique;
}

// ???????????????????? ?????????????? ???????????????????? ???????????????? ???????????????? ?????? ?????????????? x
// (???????????? -1, ???????? ?????? ?????????? ???????????? x)
int binarySearchLessOrEqual(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }
    return left;
}

void insert_(int *const a, size_t *const n, const size_t pos, const int value) {
    assert (pos <= *n);
    if (*n == pos) {
        append_(a, n, value);
        return;
    }
    (*n)++;
    for (size_t i = *n; i != pos; i--)
        a[i] = a[i - 1];
    a[pos] = value;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    *n -= 1;
}

void insertElement_(int *a, size_t *size, const size_t position, const int x) {
    assert(position <= *size);
    if (*size == position) {
        append_(a, size, x);
        return;
    }

    for (size_t i = *size - 1; i >= position; i--)
        a[i + 1] = a[i];
    a[position] = x;
    *size += 1;
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    *n -= 1;
}

int getMax(int *a, int n) {
    if (n < 1) {
        fprintf(stderr, "empty array");
        exit(1);
    }
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

int getMin(int *a, int n) {
    if (n < 1) {
        fprintf(stderr, "empty array");
        exit(1);
    }
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

bool isUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), compare_ints);
    bool isUnique = true;

    int i = 0;
    while (i < n - 1 && isUnique) {
        isUnique = a[i] != a[i + 1];
        i++;
    }

    return isUnique;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (size_t i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

long long maxArrayLL(long long *a, size_t n) {
    if (n < 1) {
        fprintf(stderr, "empty array");
        exit(1);
    }
    long long max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

float getDistance(int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    return sqrtf(distance);
}

int countValues(const int *a, int n, int value) {
    int counter = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            counter++;

    return counter;
}