//
// Created by DNS on 06.02.2022.
//

#ifndef LAST_VECTORVOID_H
#define LAST_VECTORVOID_H

#include <limits.h>
#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;             // указатель на нулевой элемент вектора
    size_t size;            // размер вектора
    size_t capacity;        // вместимость вектора
    size_t baseTypeSize;    // размер базового типа:
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений, размера baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество
// памяти, выделенное под хранение элементов вектора v
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную под
//неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v);

// удаляет элементы из вектора v
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору v
void deleteVectorV(vectorVoid *v);

// возвращает true, если вектор пуст, иначе - false
bool isEmptyV(vectorVoid *v);

// возвращает true, если вектор полон, иначе - false
bool isFullV(vectorVoid *v);

// записывает в sourse значение, лежащее в index-ом элементе вектора v
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// записывает в index-ый элемент вектора v значение, лежащее в sourse
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// удаляет последний элемент v
void popBackV(vectorVoid *v);

// добавляет в конце вектора v значение x
void pushBackV(vectorVoid *v, void *source);

#endif //LAST_VECTORVOID_H
