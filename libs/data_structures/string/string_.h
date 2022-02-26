#include <stdio.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

size_t strlen_(char *begin);

char *find(char *begin, const char *end, int ch);

char *findNonSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* getEndOfString(char *begin);