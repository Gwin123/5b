#include "string_.h"
#include <ctype.h>
#include <memory.h>
#include <math.h>

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    int x = strcmp(expected, got);
    if (x) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs && (*lhs == *rhs))
        lhs++, rhs++;

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            *beginDestination++ = *beginSource;

        beginSource++;
    }
    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))
            *beginDestination++ = *rbeginSource;

        rbeginSource--;
    }
    return beginDestination;
}

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource != rendSource) {
        *beginDestination++ = *rbeginSource;

        rbeginSource--;
    }
    return beginDestination;
}

char *getEndOfString(char *begin) {
    while (*begin != '\0')
        begin++;

    return begin;
}

bool getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return false;

    word->end = findSpace(word->begin);

    return true;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend) + 1;

    if (word->end == rend)
        return false;

    word->begin = findSpaceReverse(word->end, rend) + 1;

    return true;
}

char *strstr_(char *source, char *word) {
    while (*source != '\0') {

        if (*source == *word) {
            bool isFound = true;

            char *beginSearchWord = word;
            char *beginSearchSource = source;

            while (*beginSearchWord && isFound)
                isFound = *beginSearchWord++ == *beginSearchSource++;

            if (isFound)
                return source;
        }
        source++;
    }
    return source;
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        *copy(source, getEndOfString(source), _stringBuffer) = '\0';
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while (*readPtr != '\0') {
        char *beginWord = strstr_(readPtr, word1.begin);
        recPtr = copy(readPtr, beginWord, recPtr);
        readPtr = beginWord + w1Size;

        if (*beginWord == '\0') {
            *recPtr = '\0';
            return;
        }

        memcpy(recPtr, word2.begin, w2Size);

        recPtr += w2Size;
    }
    *recPtr = '\0';
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *begin1 = w1.begin;
    char *begin2 = w2.begin;
    while (begin1 != w1.end - 1 && begin2 != w2.end - 1 && (*begin1 == *begin2))
        begin1++, begin2++;

    return *begin1 - *begin2;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *beginSearch = s;
    bag->size = 0;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        bag->words[bag->size] = word;

        bag->size++;
        beginSearch = word.end;
    }
}

