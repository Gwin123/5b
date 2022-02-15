//
// Created by DNS on 14.02.2022.
//

#ifndef LAST_FRACTION_H
#define LAST_FRACTION_H

typedef struct fraction {
    int numerator;
    int denumerator;
} fraction;

void inputFraction(fraction *f);

void inputFractions(fraction *franctions, size_t size);

void outputFraction(fraction f);

void outputFractions(fraction *fractions, size_t size);

int gcd(int a, int b);

int lcm(int a, int b);

void simpleFraction(fraction *f);

fraction mulFractions(fraction f1, fraction f2);

fraction divFraction(fraction f1, fraction f2);

fraction addFraction(fraction f1, fraction f2);

fraction subFraction(fraction f1, fraction f2);

fraction sumFractions(fraction *f, size_t size);

#endif //LAST_FRACTION_H
