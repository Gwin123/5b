#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TIME_TEST(testCode, time) { \
    clock_t start_time = clock(); \
    testCode \
        clock_t end_time = clock(); \
    clock_t sort_time = end_time - start_time; \
    time = (double) sort_time / CLOCKS_PER_SEC; \
    }

#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])

// функция сортировки
typedef struct SortFunc {
    void (*sort )(int *a, size_t n); // указатель на функцию
    // сортировки
    char name[64];                   // имя сортировки,
    // используемое при выводе
} SortFunc;

// функция генерации
typedef struct GeneratingFunc {
    void (*generate )(int *a, size_t n); // указатель на функцию
    // генерации последоват.
    char name[64];                       // имя генератора,
    // используемое при выводе
} GeneratingFunc;

bool isOrdered(const int *a, size_t size) {
    for (int i = 0; i < size - 1; i++)
        if (a[i] > a[i + 1])
            return false;

    return true;
}

void outputArray_(const int *a, size_t size) {
    for (size_t i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void checkTime(void (*sortFunc)(int *, size_t),
               void (*generateFunc)(int *, size_t),
               size_t size, char *experimentName) {
    static size_t runCounter = 1;

    // генерация последовательности
    static int innerBuffer[100000];
    generateFunc(innerBuffer, size);
    printf("Run #%zu| ", runCounter++);
    printf("Name: %s\n", experimentName);

    // замер времени
    double time;

    TIME_TEST({ sortFunc(innerBuffer, size); }, time);

    // результаты замера
    printf("Status: ");
    if (isOrdered(innerBuffer, size)) {
        printf("OK! Time : %.3f s.\n", time);

        // запись в файл
        char filename[256];
        sprintf(filename, "./data/%s.csv", experimentName);
        FILE *f = fopen(filename, "a");
        if (f == NULL) {
            printf("FileOpenError %s", filename);
            exit(1);
        }
        fprintf(f, "%zu; %.3f\n", size, time);
        fclose(f);
    } else {
        printf("Wrong!\n");

        // вывод массива, который не смог быть отсортирован
        outputArray_(innerBuffer, size);

        exit(1);
    }
}

#include "libs/algorithms/algorithms/algorithm.h"

void selectionSort(int *a, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos], sizeof(int));
    }
}

void insertionSort(int *a, size_t size) {
    for (size_t i = 1; i < size; i++) {
        int t = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j], sizeof(int));
}

void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j], sizeof(int));
                swapped = 1;
            }
    }
}

void shellSort(int *a, size_t size) {
    for (size_t step = size / 2; step > 0; step /= 2)
        for (size_t i = step; i < size; i++) {
            int tmp = a[i];
            size_t j;
            for (j = i; j >= step; j -= step) {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
}


#include "malloc.h"

int digit(int n, int k, int N, int M) {
    return (n >> (N * k) & (M - 1));
}

void _radixSort(int *l, int *r, int N) {
    int k = (32 + N - 1) / N;
    int M = 1 << N;
    int sz = r - l;
    int *b = (int *) malloc(sizeof(int) * sz);
    int *c = (int *) malloc(sizeof(int) * M);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;

        for (int *j = l; j < r; j++)
            c[digit(*j, i, N, M)]++;

        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];

        for (int *j = r - 1; j >= l; j--)
            b[--c[digit(*j, i, N, M)]] = *j;

        int cur = 0;
        for (int *j = l; j < r; j++)
            *j = b[cur++];
    }
    free(b);
    free(c);
}

void radixSort(int *a, size_t n) {
    _radixSort(a, a + n, 8);
}

/* sort unsigned ints */
static void rad_sort_u(unsigned *begin, unsigned *end, unsigned bit) {
    if (!bit || end < begin + 1)
        return;

    unsigned *ll = begin;
    unsigned *rr = end - 1;
    while (1) {
        while (ll < rr && !(*ll & bit))
            ll++;
        while (ll < rr && (*rr & bit))
            rr--;
        if (ll >= rr)
            break;
        swap(ll, rr, sizeof(int));
    }

    if (!(bit & *ll) && ll < end)
        ll++;

    bit >>= 1;

    rad_sort_u(begin, ll, bit);
    rad_sort_u(ll, end, bit);
}

/* sort signed ints: flip highest bit, sort as unsigned, flip back */
static void radix_sort(int *a, const size_t size) {
    unsigned *x = (unsigned *) a;

    for (size_t i = 0; i < size; i++)
        x[i] ^= INT_MIN;

    rad_sort_u(x, x + size, INT_MIN);

    for (size_t i = 0; i < size; i++)
        x[i] ^= INT_MIN;
}

int cmp_int(const void *a, const void *b) {
    return *(const int *) a - *(const int *) b;
}

int cmp_intReverse(const void *a, const void *b) {
    return *(const int *) b - *(const int *) a;
}


#include <memory.h>

void merge(const int *a, const size_t n,
           const int *b, const size_t m, int *c) {
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (j == m || i < n && a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }
}

void mergeSort_(int *source, size_t l, size_t r, int *buffer) {
    size_t n = r - l;
    if (n <= 1)
        return;

    size_t m = (l + r) / 2;
    mergeSort_(source, l, m, buffer);
    mergeSort_(source, m, r, buffer);

    merge(source + l, m - l, source + m, r - m, buffer);
    memcpy(source + l, buffer, sizeof(int) * n);
}

void mergeSort(int *a, size_t n) {
    int *buffer = (int *) malloc(sizeof(int) * n);
    mergeSort_(a, 0, n, buffer);
    free(buffer);
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest], sizeof(int));

        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, size_t n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i], sizeof(int));

        heapify(arr, i, 0);
    }
}

void quicksort(int *A, size_t len) {
    if (len < 2)
        return;

    int pivot = A[len / 2];

    int i, j;
    for (i = 0, j = len - 1;; i++, j--) {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(A + i, A + j, sizeof(int));
    }

    quicksort(A, i);
    quicksort(A + i, len - i);
}

void generateRandomArray(int *a, size_t size) {
    srand(time(0));
    for (int i = 0; i < size; i++)
        a[i] = rand() % 10000 - 5000;
}

void generateOrderedArray(int *a, size_t size) {
    generateRandomArray(a, size);
    qsort(a, size, sizeof(int), cmp_int);
}

void generateOrderedBackwards(int *a, size_t size) {
    generateRandomArray(a, size);
    qsort(a, size, sizeof(int), cmp_intReverse);
}

////////////////////////////////////////////////////
void insertionSort_(int *arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergeA(int arr[], int l, int m, int r) {

    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

#define RUN 32

void timSort(int *arr, size_t n) {
    for (int i = 0; i < n; i += RUN)
        insertionSort_(arr, i, min2((i + RUN - 1),
                                   (n - 1)));

    for (int size = RUN; size < n;
         size = 2 * size) {

        for (int left = 0; left < n;
             left += 2 * size) {

            int mid = left + size - 1;
            int right = min2((left + 2 * size - 1),
                             (n - 1));

            if (mid < right)
                mergeA(arr, left, mid, right);
        }
    }
}

void qSort(int *a, size_t size) {
    qsort(a, size, sizeof(int), cmp_int);
}

////////////////////////////////////////////////////

void timeExperiment() {
    SortFunc sorts[] = {
            {selectionSort, "selectionSort"},
            {insertionSort, "insertionSort"},
            {bubbleSort,    "bubbleSort"},
            {combsort,      "combSort"},
            {shellSort, "shellSort"},
            {radix_sort, "radixSort"},
            {mergeSort, "mergeSort"},
            {heapSort, "heapSort"},
            {quicksort, "quickSort"},
            {timSort, "timSort"},
            {qSort, "qSort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);

    // описание функций генерации
    GeneratingFunc generatingFuncs[] = {
            {generateRandomArray,      "random"},
            {generateOrderedArray,     "ordered"},
            {generateOrderedBackwards, "orderedBackwards"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generatingFuncs);

    // запись статистики в файл
    for (size_t size = 10000; size <= 100000; size += 10000) {
        printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("Size : %d\n", size);
        for (int i = 0; i < FUNCS_N; i++) {
            for (int j = 0; j < CASES_N; j++) {
                // генерация имени файла
                static char filename[128];
                sprintf(filename, "%s_%s_time",
                        sorts[i].name, generatingFuncs[j].name);
                checkTime(sorts[i].sort,
                          generatingFuncs[j].generate,
                          size, filename);
            }
        }
        printf("\n");
    }
}

int main() {
    timeExperiment();

    return 0;
}


