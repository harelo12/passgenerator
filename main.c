#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <tchar.h>

#define PASSWORD_LENGTH 20
#define CHARSET _T("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+")

// IDs de controles
#define IDC_STATIC_LABEL 101
#define IDC_EDIT_PASSWORD 102
#define IDC_BUTTON_GENERATE 103
#define IDC_BUTTON_SAVE 104
#define IDC_BUTTON_EXIT 105

// Variables globales
TCHAR currentPassword[PASSWORD_LENGTH + 1] = _T("");
int saveCounter = 0;

// Función para generar contraseña
void generate_password(TCHAR* password, int length) {
    size_t charset_len = _tcslen(CHARSET);
    for (int i = 0; i < length; i++) {
        password[i] = CHARSET[rand() % charset_len];
    }
    password[length] = _T('\0');
}

// Función para guardar la contraseña en un archivo
bool save_password(const TCHAR* password, int count) {
    FILE* f = _tfopen(_T("passlist.txt"), _T("a"));
    if (!f) {
        MessageBox(NULL, _T("Error al abrir/crear archivo"), _T("Error"), MB_OK | MB_ICONERROR);
        return false;
    }
    _ftprintf(f, _T("Contraseña[%d]: %s\n"), count, password);
    fclose(f);
    MessageBox(NULL, _T("Contraseña guardada correctamente"), _T("Información"), MB_OK | MB_ICONINFORMATION);
    return true;
}

// Procedimiento de la ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE: {
        CreateWindowEx(0, _T("STATIC"), _T("Contraseña generada:"), WS_CHILD | WS_VISIBLE,
            20, 20, 200, 20, hwnd, (HMENU)IDC_STATIC_LABEL, NULL, NULL);
        CreateWindowEx(WS_EX_CLIENTEDGE, _T("EDIT"), _T(""), WS_CHILD | WS_VISIBLE | ES_READONLY,
            20, 50, 350, 25, hwnd, (HMENU)IDC_EDIT_PASSWORD, NULL, NULL);
        CreateWindowEx(0, _T("BUTTON"), _T("Generar"), WS_CHILD | WS_VISIBLE,
            20, 90, 100, 30, hwnd, (HMENU)IDC_BUTTON_GENERATE, NULL, NULL);
        CreateWindowEx(0, _T("BUTTON"), _T("Guardar"), WS_CHILD | WS_VISIBLE,
            130, 90, 100, 30, hwnd, (HMENU)IDC_BUTTON_SAVE, NULL, NULL);
        CreateWindowEx(0, _T("BUTTON"), _T("Salir"), WS_CHILD | WS_VISIBLE,
            240, 90, 100, 30, hwnd, (HMENU)IDC_BUTTON_EXIT, NULL, NULL);
    }
                  break;
    case WM_COMMAND: {
        switch (LOWORD(wParam)) {
        case IDC_BUTTON_GENERATE: {
            generate_password(currentPassword, PASSWORD_LENGTH);
            SetWindowText(GetDlgItem(hwnd, IDC_EDIT_PASSWORD), currentPassword);
        }
                                break;
        case IDC_BUTTON_SAVE: {
            if (_tcslen(currentPassword) == 0) {
                MessageBox(hwnd, _T("Genera una contraseña primero."), _T("Aviso"), MB_OK | MB_ICONWARNING);
            }
            else {
                if (save_password(currentPassword, saveCounter)) {
                    saveCounter++;
                }
            }
        }
                            break;
        case IDC_BUTTON_EXIT: {
            PostQuitMessage(0);
        }
                            break;
        }
    }
                   break;
    case WM_DESTROY: {
        PostQuitMessage(0);
    }
                   break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Función principal: WinMain
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand((unsigned int)time(NULL));

    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = _T("PassGenWindowClass");

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, _T("Error al registrar la clase de ventana"), _T("Error"), MB_OK | MB_ICONERROR);
        return 1;
    }

    HWND hwnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        _T("PASSGENERATOR - Generador de Contraseñas"),
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 180,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) {
        MessageBox(NULL, _T("Error al crear la ventana"), _T("Error"), MB_OK | MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}
