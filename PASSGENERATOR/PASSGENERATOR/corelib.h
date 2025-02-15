#pragma once
#ifndef CORELIB_H
#define CORELIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLK "\x1B[0;30m"
#define RED "\x1B[0;31m"
#define GRN "\x1B[0;32m"
#define YEL "\x1B[0;33m"
#define BLU "\x1B[0;34m"
#define MAG "\x1B[0;35m"
#define CYN "\x1B[0;36m"
#define WHT "\x1B[0;37m"

#define BBLK "\x1B[1;30m"
#define BRED "\x1B[1;31m"
#define BGRN "\x1B[1;32m"
#define BYEL "\x1B[1;33m"
#define BBLU "\x1B[1;34m"
#define BMAG "\x1B[1;35m"
#define BCYN "\x1B[1;36m"
#define BWHT "\x1B[1;37m"

#define UBLK "\x1B[4;30m"
#define URED "\x1B[4;31m"
#define UGRN "\x1B[4;32m"
#define UYEL "\x1B[4;33m"
#define UBLU "\x1B[4;34m"
#define UMAG "\x1B[4;35m"
#define UCYN "\x1B[4;36m"
#define UWHT "\x1B[4;37m"

#define BLKB "\x1B[40m"
#define REDB "\x1B[41m"
#define GRNB "\x1B[42m"
#define YELB "\x1B[43m"
#define BLUB "\x1B[44m"
#define MAGB "\x1B[45m"
#define CYNB "\x1B[46m"
#define WHTB "\x1B[47m"

#define BLKHB "\x1B[0;100m"
#define REDHB "\x1B[0;101m"
#define GRNHB "\x1B[0;102m"
#define YELHB "\x1B[0;103m"
#define BLUHB "\x1B[0;104m"
#define MAGHB "\x1B[0;105m"
#define CYNHB "\x1B[0;106m"
#define WHTHB "\x1B[0;107m"

#define HBLK "\x1B[0;90m"
#define HRED "\x1B[0;91m"
#define HGRN "\x1B[0;92m"
#define HYEL "\x1B[0;93m"
#define HBLU "\x1B[0;94m"
#define HMAG "\x1B[0;95m"
#define HCYN "\x1B[0;96m"
#define HWHT "\x1B[0;97m"

#define BHBLK "\x1B[1;90m"
#define BHRED "\x1B[1;91m"
#define BHGRN "\x1B[1;92m"
#define BHYEL "\x1B[1;93m"
#define BHBLU "\x1B[1;94m"
#define BHMAG "\x1B[1;95m"
#define BHCYN "\x1B[1;96m"
#define BHWHT "\x1B[1;97m"

#define CRST "\x1B[0m"
#define COLOR_RESET "\x1B[0m"
#define CRESET "\x1B[0m"


#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+"

void generate_password(char* password, int length) {
    size_t charset_len = strlen(CHARSET);
    for (int i = 0; i < length; i++) {
        password[i] = CHARSET[rand() % charset_len];
    }
    password[length] = '\0'; 
}

bool is_unique_password(const char* password, char* passwords[], int total_passwords) {
    for (int i = 0; i < total_passwords; i++) {
        if (strcmp(passwords[i], password) == 0) {
            return false;
        }
    }
    return true; 
}

static inline void swap_int(int* _0xA, int* _0xB) {
    int _0xC = *_0xA;
    *_0xA = *_0xB;
    *_0xB = _0xC;
}

static inline void bubble_sort(int _0xArr[], int _0xN) {
    for (int _0xI = 0; _0xI < _0xN - 1; _0xI++) {
        for (int _0xJ = 0; _0xJ < _0xN - _0xI - 1; _0xJ++) {
            if (_0xArr[_0xJ] > _0xArr[_0xJ + 1])
                swap_int(&_0xArr[_0xJ], &_0xArr[_0xJ + 1]);
        }
    }
}

static inline void insertion_sort(int _0xArr[], int _0xN) {
    int _0xK, _0xJ;
    for (int _0xI = 1; _0xI < _0xN; _0xI++) {
        _0xK = _0xArr[_0xI];
        _0xJ = _0xI - 1;
        while (_0xJ >= 0 && _0xArr[_0xJ] > _0xK) {
            _0xArr[_0xJ + 1] = _0xArr[_0xJ];
            _0xJ--;
        }
        _0xArr[_0xJ + 1] = _0xK;
    }
}

static inline int partition(int _0xArr[], int _0xL, int _0xH) {
    int _0xP = _0xArr[_0xH];
    int _0xI = _0xL - 1;
    for (int _0xJ = _0xL; _0xJ <= _0xH - 1; _0xJ++) {
        if (_0xArr[_0xJ] < _0xP) {
            _0xI++;
            swap_int(&_0xArr[_0xI], &_0xArr[_0xJ]);
        }
    }
    swap_int(&_0xArr[_0xI + 1], &_0xArr[_0xH]);
    return _0xI + 1;
}

static inline void quick_sort(int _0xArr[], int _0xL, int _0xH) {
    if (_0xL < _0xH) {
        int _0xPI = partition(_0xArr, _0xL, _0xH);
        quick_sort(_0xArr, _0xL, _0xPI - 1);
        quick_sort(_0xArr, _0xPI + 1, _0xH);
    }
}

static inline int linear_search(int _0xArr[], int _0xN, int _0xKey) {
    for (int _0xI = 0; _0xI < _0xN; _0xI++) {
        if (_0xArr[_0xI] == _0xKey)
            return _0xI;
    }
    return -1;
}

static inline int binary_search(int _0xArr[], int _0xN, int _0xKey) {
    int _0xL = 0, _0xH = _0xN - 1;
    while (_0xL <= _0xH) {
        int _0xM = _0xL + (_0xH - _0xL) / 2;
        if (_0xArr[_0xM] == _0xKey)
            return _0xM;
        else if (_0xArr[_0xM] < _0xKey)
            _0xL = _0xM + 1;
        else
            _0xH = _0xM - 1;
    }
    return -1;
}

static inline void print_array(const int _0xArr[], int _0xN) {
    printf("[ ");
    for (int _0xI = 0; _0xI < _0xN; _0xI++) {
        printf("%d ", _0xArr[_0xI]);
    }
    printf("]\n");
}

#endif // CORELIB_H
