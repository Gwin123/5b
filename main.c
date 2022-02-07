#include "libs/data_structures/vector/vectorVoid.h"

#define EPS 10E-7
////int main() {
////    size_t n;
////    scanf("%zd", &n);
////
////    vectorVoid v = createVectorV(0, sizeof(int));
////    for (int i = 0; i < n; i++) {
////        int x;
////        scanf("%d", &x);
////
////        pushBackV(&v, &x);
////    }
////
////    for (int i = 0; i < n; i++) {
////        int x;
////        getVectorValueV(&v, i, &x);
////
////        printf("%d ", x);
////    }
////
////    return 0;
////}
//
//int main() {
////    size_t n;
////    scanf("%zd", &n);
//
//    double c[5] = {1, 2, 3, 4, 5};
//
//    vectorVoid v = createVectorV(0, sizeof(double));
//    for (int i = 0; i < 5; i++) {
//        double x = c[i];
//        printf("%lf", x);
//        pushBackV(&v, &x);
//    }
//
//    for (int i = 0; i < 5; i++) {
//        double x;
//        getVectorValueV(&v, i, &x);
//
//        printf("%lf ", x);
//    }
//
//    return 0;
//}

double fabs(const double x) {
    return x > 0 ? x : -x;
}

int isEqual(const double x, const double y) {
    return fabs(x - y) < EPS;
}

void test_createVector_ZeroCapacityInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_createVector_NotZeroCapacityInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    assert(v.size == 0);
    assert(v.capacity == 5);
    assert(v.data != NULL);

    deleteVectorV(&v);
}

void test_createVectorInt() {
    test_createVector_ZeroCapacityInt();
    test_createVector_NotZeroCapacityInt();
}

void test_reserve_FromZeroToZeroInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    reserveV(&v, 0);

    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_reserve_FromZeroToNotZeroInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    reserveV(&v, 5);

    assert(v.capacity == 5);
    assert(v.size == 0);
    assert(v.data != NULL);

    deleteVectorV(&v);
}

void test_reserve_FromNotZeroToZeroInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    reserveV(&v, 0);

    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_reserve_toLesserInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int a[] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++)
        pushBackV(&v, a + i);

    reserveV(&v, 2);

    assert(v.capacity == 2);
    assert(v.size == 2);
    assert(v.data != NULL);

    for (int i = 0; i < v.size; i++) {
        int elem;
        getVectorValueV(&v, i, &elem);
        assert(elem == a[i]);
    }
    deleteVectorV(&v);
}

void test_reserve_toMoreInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int a[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        pushBackV(&v, a + i);

    reserveV(&v, 10);

    assert(v.capacity == 10);
    assert(v.size == 5);
    assert(v.data != NULL);

    for (int i = 0; i < v.size; i++) {
        int elem;
        getVectorValueV(&v, i, &elem);
        assert(elem == a[i]);
    }

    deleteVectorV(&v);
}

void test_reserveInt() {
    test_reserve_FromZeroToZeroInt();
    test_reserve_FromNotZeroToZeroInt();
    test_reserve_toLesserInt();
    test_reserve_FromZeroToNotZeroInt();
    test_reserve_toMoreInt();
}

void test_shrinkToFit_toZeroInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    shrinkToFitV(&v);

    assert(v.capacity == 0);
    assert(v.size == 0);

    deleteVectorV(&v);
}

void test_shrinkToFit_toNotZeroInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    for (int i = 0; i < 3; i++)
        pushBackV(&v, &i);

    shrinkToFitV(&v);

    assert(v.capacity == 3);
    assert(v.size == 3);

    deleteVectorV(&v);
}

void test_shrinkToFitInt() {
    test_shrinkToFit_toZeroInt();
    test_shrinkToFit_toNotZeroInt();
}

void test_pushBack_emptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int elem = 5;
    pushBackV(&v, &elem);

    assert(v.size == 1);
    assert(v.capacity == 1);

    getVectorValueV(&v, 0, &elem);

    assert(elem == 5);

    deleteVectorV(&v);
}

void test_pushBack_fullVectorInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int a[] = {0, 1, 2, 3, 4};
    for (int i = 0; i < v.capacity; i++) {
        pushBackV(&v, a + i);
    }

    assert(v.size == 5);

    int elem = 5;
    pushBackV(&v, &elem);

    getVectorValueV(&v, v.size - 1, &elem);
    assert(elem == 5);
    assert(v.size == 6);
    assert(v.capacity == 10);

    deleteVectorV(&v);
}

void test_pushBackInt() {
    test_pushBack_emptyVectorInt();
    test_pushBack_fullVectorInt();
}

void test_popBack_notEmptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int elem = 10;
    pushBackV(&v, &elem);

    assert(v.size == 1);
    popBackV(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVectorV(&v);
}

void test_popBackInt() {
    test_popBack_notEmptyVectorInt();
}

void test_getVectorValue_lastElementInt() {
    vectorVoid v = createVectorV(5, sizeof(int));
    int a[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < v.capacity; i++)
        pushBackV(&v, a + i);

    int elem;
    getVectorValueV(&v, v.size - 1, &elem);
    assert(elem == 4);

    deleteVectorV(&v);
}

void test_getVectorValueInt() {
    test_getVectorValue_lastElementInt();
}

void test_isEmpty_emptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(isEmptyV(&v));

    deleteVectorV(&v);
}

void test_isEmpty_notEmptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int elem = 5;
    pushBackV(&v, &elem);

    assert(!isEmptyV(&v));

    deleteVectorV(&v);
}

void test_isFull_emptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(isFullV(&v));

    deleteVectorV(&v);
}

void test_isFull_notEmptyNotFullVectorInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int elem = 5;
    pushBackV(&v, &elem);

    assert(!isFullV(&v));

    deleteVectorV(&v);
}

void test_isFull_FullVectorInt() {
    vectorVoid v = createVectorV(3, sizeof(int));

    int elem = 5;
    pushBackV(&v, &elem);
    pushBackV(&v, &elem);
    pushBackV(&v, &elem);

    assert(isFullV(&v));

    deleteVectorV(&v);
}

void test_isEmptyInt() {
    test_isEmpty_emptyVectorInt();
    test_isEmpty_notEmptyVectorInt();
}

void test_isFullInt() {
    test_isFull_emptyVectorInt();
    test_isFull_notEmptyNotFullVectorInt();
    test_isFull_FullVectorInt();
}

void testInt() {
    test_createVectorInt();
    test_pushBackInt();
    test_popBackInt();
    test_getVectorValueInt();
    test_isEmptyInt();
    test_isFullInt();
    test_reserveInt();
    test_shrinkToFitInt();
}

//////////////////////////////////////////////////////////
void test_createVector_ZeroCapacityDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_createVector_NotZeroCapacityDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    assert(v.size == 0);
    assert(v.capacity == 5);
    assert(v.data != NULL);

    deleteVectorV(&v);
}

void test_createVectorDouble() {
    test_createVector_ZeroCapacityDouble();
    test_createVector_NotZeroCapacityDouble();
}

void test_reserve_FromZeroToZeroDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    reserveV(&v, 0);

    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_reserve_FromZeroToNotZeroDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    reserveV(&v, 5);

    assert(v.capacity == 5);
    assert(v.size == 0);
    assert(v.data != NULL);

    deleteVectorV(&v);
}

void test_reserve_FromNotZeroToZeroDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    reserveV(&v, 0);

    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_reserve_toLesserDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    double a[] = {4.5, 5.5, 6.5, 4.5, 1.5};

    for (int i = 0; i < 5; i++)
        pushBackV(&v, a + i);

    reserveV(&v, 2);

    assert(v.capacity == 2);
    assert(v.size == 2);
    assert(v.data != NULL);

    deleteVectorV(&v);
}

void test_reserve_toMoreDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    double a[] = {1.4, 2.4, 3.5, 4.1, 5.5};

    for (int i = 0; i < 5; i++)
        pushBackV(&v, a + i);

    reserveV(&v, 10);

    assert(v.capacity == 10);
    assert(v.size == 5);
    assert(v.data != NULL);

    for (int i = 0; i < v.size; i++) {
        double elem;
        getVectorValueV(&v, i, &elem);
        assert(isEqual(elem, a[i]));
    }

    deleteVectorV(&v);
}

void test_reserveDouble() {
    test_reserve_FromZeroToZeroDouble();
    test_reserve_FromNotZeroToZeroDouble();
    test_reserve_toLesserDouble();
    test_reserve_FromZeroToNotZeroDouble();
    test_reserve_toMoreDouble();
}

void test_shrinkToFit_toZeroDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    shrinkToFitV(&v);

    assert(v.capacity == 0);
    assert(v.size == 0);

    deleteVectorV(&v);
}

void test_shrinkToFit_toNotZeroDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    for (int i = 0; i < 3; i++) {
        double elem = (double) i;
        pushBackV(&v, &elem);
    }

    shrinkToFitV(&v);

    assert(v.capacity == 3);
    assert(v.size == 3);

    double elem;
    getVectorValueV(&v, v.size - 1, &elem);
    assert(isEqual(elem, 2));

    deleteVectorV(&v);
}

void test_shrinkToFitDouble() {
    test_shrinkToFit_toZeroDouble();
    test_shrinkToFit_toNotZeroDouble();
}

void test_pushBack_emptyVectorDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    double elem = 5;
    pushBackV(&v, &elem);

    assert(v.size == 1);
    assert(v.capacity == 1);

    getVectorValueV(&v, 0, &elem);

    assert(isEqual(elem, 5.0));

    deleteVectorV(&v);
}

void test_pushBack_fullVectorDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));
    for (int i = 0; i < v.capacity; i++) {
        double elem = i * 1.;
        pushBackV(&v, &elem);
    }

    assert(v.size == 5);

    double elem = 5;
    pushBackV(&v, &elem);

    getVectorValueV(&v, v.size - 1, &elem);
    assert(isEqual(elem, 5));
    assert(v.size == 6);
    assert(v.capacity == 10);

    deleteVectorV(&v);
}

void test_pushBackDouble() {
    test_pushBack_emptyVectorDouble();
    test_pushBack_fullVectorDouble();
}

void test_popBack_notEmptyVectorDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    double elem = 10;
    pushBackV(&v, &elem);

    assert(v.size == 1);
    popBackV(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVectorV(&v);
}

void test_popBackDouble() {
    test_popBack_notEmptyVectorDouble();
}

void test_getVectorValue_lastElementDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    double a[] = {1.2, 3.4, 5.5, 6.5};

    for (int i = 0; i < 4; i++) {
        pushBackV(&v, a + i);
    }

    double elem;
    getVectorValueV(&v, v.size - 1, &elem);

    assert(isEqual(elem, 6.5));

    deleteVectorV(&v);
}

void test_getVectorValueDouble() {
    test_getVectorValue_lastElementDouble();
}

void test_isEmpty_emptyVectorDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    assert(isEmptyV(&v));

    deleteVectorV(&v);
}

void test_isEmpty_notEmptyVectorDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    double elem = 5;
    pushBackV(&v, &elem);

    assert(!isEmptyV(&v));

    deleteVectorV(&v);
}

void test_isFull_emptyVectorDouble() {
    vectorVoid v = createVectorV(0, sizeof(double));

    assert(isFullV(&v));

    deleteVectorV(&v);
}

void test_isFull_notEmptyNotFullVectorDouble() {
    vectorVoid v = createVectorV(5, sizeof(double));

    double elem = 5;
    pushBackV(&v, &elem);

    assert(!isFullV(&v));

    deleteVectorV(&v);
}

void test_isFull_FullVectorDouble() {
    vectorVoid v = createVectorV(3, sizeof(double));

    double elem = 5.1;
    pushBackV(&v, &elem);
    pushBackV(&v, &elem);
    pushBackV(&v, &elem);

    assert(isFullV(&v));

    deleteVectorV(&v);
}

void test_isEmptyDouble() {
    test_isEmpty_emptyVectorDouble();
    test_isEmpty_notEmptyVectorDouble();
}

void test_isFullDouble() {
    test_isFull_emptyVectorDouble();
    test_isFull_notEmptyNotFullVectorDouble();
    test_isFull_FullVectorDouble();
}

void testDouble() {
    test_createVectorDouble();
    test_pushBackDouble();
    test_popBackDouble();
    test_getVectorValueDouble();
    test_isEmptyDouble();
    test_shrinkToFitDouble();
    test_isFullDouble();
    test_reserveDouble();
}

void testVoid() {
    testInt();
    testDouble();

}

int main() {
    testVoid();
}


