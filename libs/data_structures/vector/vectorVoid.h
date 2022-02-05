//
// Created by DNS on 06.02.2022.
//

#ifndef LAST_VECTORVOID_H
#define LAST_VECTORVOID_H

#include <limits.h>

typedef struct vectorVoid {
    void *data;             // указатель на нулевой элемент вектора
    size_t size;            // размер вектора
    size_t capacity;        // вместимость вектора
    size_t baseTypeSize;    // размер базового типа:
} vectorVoid;

#endif //LAST_VECTORVOID_H
