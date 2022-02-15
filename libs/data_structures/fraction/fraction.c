//
// Created by DNS on 14.02.2022.
//

#include <math.h>
#include "fraction.h"
#include <stdio.h>
#include "../../algorithms/algorithms/algorithm.h"

//ввод дроби f
void inputFraction(fraction *f) {
    scanf("%d / %d", &f->numerator, &f->denumerator);
}

//ввод дробей массива franctions размера size
void inputFractions(fraction *franctions, size_t size) {
    for (int i = 0; i < size; i++)
        inputFraction(&franctions[i]);
}

//вывод дроби f
void outputFraction(fraction f) {
    printf("%d/%d \n", f.numerator, f.denumerator);
}

//вывод дробей массива fractions размера size
void outputFractions(fraction *fractions, size_t size) {
    for (int i = 0; i < size; i++)
        outputFraction(fractions[i]);
}

//возвращает НОД для a и b
int gcd(int a, int b) {
    while (a != 0 && b != 0)
        if (abs(a) > b)
            a = abs(a) % b;
        else
            b %= abs(a);
    return abs(a) + b;
}

//возвращает НОК для a и b
int lcm(int a, int b) {
    int gcdValue = gcd(a, b);
    if (gcdValue)
        return a * b / gcdValue;
    else
        return 0;
}

// сокращает дробь f
void simpleFraction(fraction *f) {
    int gcdValue = gcd(f->numerator, f->denumerator);
    f->numerator /= gcdValue;
    f->denumerator /= gcdValue;
}

// возвращает дробь, полученную путем умножения дробей f1 и f2
fraction mulFractions(fraction f1, fraction f2) {
    simpleFraction(&f1);
    simpleFraction(&f2);
    f1 = (fraction){f1.numerator, f2.denumerator};
    f2 = (fraction){f2.numerator, f1.denumerator};
    simpleFraction(&f1);
    simpleFraction(&f2);
    int numerator = f1.numerator * f2.numerator;
    int denumerator = f1.denumerator * f2.denumerator;
    fraction result = {numerator, denumerator};
    return result;
}

// возвращает дробь, полученную путём деления дробей f1 и f2,
// если числитель f2 был равен 0, возвращает дробь (0 / 0)
fraction divFraction(fraction f1, fraction f2) {
    if (f2.numerator == 0)
        return (fraction){0, 0};
    swap(&f2.numerator, &f2.denumerator, sizeof(f2.numerator));
    return mulFractions(f1, f2);
}

// возвращает дробь, полученную путем сложения дробей f1 и f2
fraction addFraction(fraction f1, fraction f2) {
    int lcmValue = lcm(f1.denumerator, f2.denumerator);
    int m1 = lcmValue / f1.denumerator;
    int m2 = lcmValue / f2.denumerator;
    int num = f1.numerator * m1 + f2.numerator * m2;
    fraction f3 = {num, lcmValue};
    simpleFraction(&f3);
    return (fraction) f3;
}

// возвращает дробь, полученную путем вычитания из дроби f1 дробь f2
fraction subFraction(fraction f1, fraction f2) {
    f2.numerator = -f2.numerator;
    return addFraction(f1, f2);
}

// возвращает дробь, полученную путем сложения всех
// дробей массива f размера size
fraction sumFractions(fraction *f, size_t size) {
    fraction sum = {f[0].numerator, f[0].denumerator};
    for (int i = 1; i < size; i++)
        sum = addFraction(sum, f[i]);

    return sum;
}
