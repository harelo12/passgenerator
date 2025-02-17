// PASSGENERATOR - Generador de Contrase�as Seguras
// Creado por harelo12, 13 de febrero de 2025

#define PROJECT_NAME    "PASSGENERATOR"
#define DESCRIPTION     "Generador de contraseñas"
#define AUTHOR          "harelo12"
#define CREATION_DATE   "13022025"
#define VERSION         "1.0.6"
#define LAST_UPDATE     "17022025"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "corelib.h"
#include "main.h" 
#include <locale.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int main(void){
    printf("\033]0;%s\007", PROJECT_NAME);

#ifdef _WIN32
    SetConsoleCP(1253);
    SetConsoleOutputCP(1252);
    system("color a");
#else
    
    printf(LGRN);
#endif

    int retFlag;

    int retVal = mainfunc(&retFlag);
    if (retFlag == 1)
        return retVal;

    return 0;
}