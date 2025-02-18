/* main.h */
#pragma once
#include "corelib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 20
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+"
#define MAX_PASSWORDS 1000

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif


int savePass(int cont, const char password[], int* retFlag) {
    *retFlag = 1;
    FILE* passfile = fopen("passlist.txt", "a");
    if (passfile == NULL) {
        printf(RED "\nError al abrir/crear archivo\n" CRST);
        return 1;
    }
    fprintf(passfile, "Contraseña[%d]: %s\n", cont, password);
    fclose(passfile);
    printf(GRN "\nContraseña guardada correctamente\n" CRST);
    *retFlag = 0;
    return 0;
}

int mainfunc(int* retFlag) {
    FILE *file = fopen("contador.txt", "r+");
    *retFlag = 1;
    char resp;
    char fresp;
    int cont = 0;
    bool repetir = true;
    char* passwords[MAX_PASSWORDS] = { 0 };
    int total_passwords = 0;

    if (file == NULL) {
        file = fopen("contador.txt", "w+");
        if (file == NULL) {
            perror("Error al abrir el archivo");
            return 1;
        }
    } else {
        fscanf(file, "%d", &cont);
    }

    srand((unsigned int)time(NULL));

    do {
        char password[PASSWORD_LENGTH + 1] = { 0 };

        do {
            generate_password(password, PASSWORD_LENGTH);
        } while (!is_unique_password(password, passwords, total_passwords));

        passwords[total_passwords] = malloc(PASSWORD_LENGTH + 1);
        if (passwords[total_passwords] == NULL) {
            fprintf(stderr, HRED "Error: No se pudo asignar memoria.\n" CRST);
            return 1;
        }
        strcpy(passwords[total_passwords], password);
        total_passwords++;

        system(CLEAR_SCREEN);
        printf(BLU "Contraseña generada: %s\n" CRST, password);
        printf(YEL "¿Desea guardarla en un archivo? (S/n): " CRST);
        fresp = getchar();
        while (getchar() != '\n');
        fresp = tolower(fresp);
        if (fresp == 's') {
            int saveRet;
            int retVal = savePass(cont, password, &saveRet);
            if (saveRet == 1)
                return retVal;
            cont++;
            rewind(file);
            fprintf(file, "%d", cont);
            fflush(file);
        }
        
        printf(YEL "¿Desea repetir (S/n)? " CRST);
        resp = getchar();
        while (getchar() != '\n');
        resp = tolower(resp);
        repetir = (resp == 's');
    } while (repetir);

    for (int i = 0; i < total_passwords; i++) {
        free(passwords[i]);
    }
    fclose(file);
    *retFlag = 0;
    return 0;
}