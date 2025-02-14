// PASSGENERATOR - Generador de Contraseñas Seguras
// Creado por harelo12, 13 de febrero de 2025

#define PROJECT_NAME    "PASSGENERATOR"
#define DESCRIPTION     "Generador de contraseñas"
#define AUTHOR          "harelo12"
#define CREATION_DATE   "13022025"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "corelib.h"
#include "main.h" 

int main(void) {
    SetConsoleTitleA(PROJECT_NAME);
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    system("color a");
    int retFlag;

    int retVal = mainfunc(&retFlag);
    if (retFlag == 1)
        return retVal;

    return 0;
}