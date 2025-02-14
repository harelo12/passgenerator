/* main.h */
#pragma once
#include "corelib.h"
#define PASSWORD_LENGTH 20
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+"
#define MAX_PASSWORDS 1000

int savePass(int cont, const char password[], int* retFlag);
int mainfunc(int* retFlag);

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
    *retFlag = 1;
    char resp;
    char fresp;
    int cont = 0;
    bool repetir = true;
    char* passwords[MAX_PASSWORDS] = { 0 };
    int total_passwords = 0;

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

        system("cls");
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
    *retFlag = 0;
    return 0;
}