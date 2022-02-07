//
// Created by DNS on 06.02.2022.
//

#include "vectorVoid.h"
#include <malloc.h>

void memoryAllocateError(const void *data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}


vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data;
    if (n) {
        data = malloc(n * baseTypeSize);
        memoryAllocateError(data);
    } else
        data = NULL;

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
        memoryAllocateError(v->data);

        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
    } else
        deleteVectorV(v);
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    clearV(v);
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    return !v->size;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void indexOutOfRange(vectorVoid *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    indexOutOfRange(v, index);

    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    indexOutOfRange(v, index);

    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void elementAccessError(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
}

void popBackV(vectorVoid *v) {
    elementAccessError(v);

    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);

    char *destination = (char *) v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);

    v->size++;
}
