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

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_menu() {
    printf(GRN);
    printf("=====================================\n");
    printf("=          %s          =\n", PROJECT_NAME);
    printf("=====================================\n");
    printf(CRST);
    printf("1. Ejecutar\n");
    printf("0. Salir\n");
    printf("Seleccione una opción: ");
}

void execute_option() {
    printf(YEL "Ejecutando la opción seleccionada...\n" CRST);
    // Aquí puedes llamar a la función principal de tu programa
    int retFlag;
    int retVal = mainfunc(&retFlag);
    if (retFlag == 1) {
        exit(retVal);
    }
}

void exit_program() {
    printf(RED "Saliendo del programa...\n" CRST);
    exit(0);
}

int main(void) {
    printf("\033]0;%s\007", PROJECT_NAME);

#ifdef _WIN32
    SetConsoleCP(1253);
    SetConsoleOutputCP(1252);
    system("color a");
#else
    printf(GRN);
#endif

    void (*menu_options[2])() = {exit_program, execute_option};

    int option;
    while (true) {
        clear_screen();
        print_menu();
        scanf("%d", &option);

        if (option >= 0 && option < 2) {
            menu_options[option]();
        } else {
            printf(RED "Opción no válida. Inténtelo de nuevo.\n" CRST);
            sleep(2);
        }
    }

    return 0;
}