#include <iostream>
#include <windows.h>
#include "tipo.h"
using namespace std;

void pruebas();

int main() {
    SetConsoleOutputCP(CP_UTF8); // Imprime acentos
    SetConsoleCP(CP_UTF8); // lee con acentos
    pruebas();
    return 0;
}

void pruebas() {
    Equipo e1(1, "Michel Davalos", "Laptop", "HP", "Omen 16", "No enciende", "Recibido", "2025/09/27" );
    Equipo e2(2, "Victor Rafael", "Desktop", "Gigabyte", "Aourus", "Disco Corrupto", "Recibido", "2025/09/27" );
    cout << e1 << "\n";
    cout << e2;
}