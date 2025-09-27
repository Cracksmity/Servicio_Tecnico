#include <iostream>
#include <windows.h>
#include "tipo.h"
#include "servicio_tecnico.h"
using namespace std;

void pruebas();

int main() {
    SetConsoleOutputCP(CP_UTF8); // Imprime acentos
    SetConsoleCP(CP_UTF8); // lee con acentos
    // pruebas();
    cout << "🛠️ Sistema de servicio técnico" << endl;
    cout << "🗂️ LISTA: Registro de equipo" << endl;
    cout << "📦 PILA: Almacén (LIFO — Last In First Out)" << endl;
    cout << "🔧 COLA: Mantenimiento (FIFO — First In First Out)" << endl;

    ServicioTecnico<10> st;
    st.ejecutarMenu();
    return 0;
}

void pruebas() {
    Equipo e1(1, "Michel Davalos", "Laptop", "HP", "Omen 16", "No enciende");
    e1.setFecha("2025/09/27");
    Equipo e2(2, "Victor Rafael", "Desktop", "Gigabyte", "Aourus", "Disco Corrupto");
    e2.setFecha("2025/09/27");
    cout << e1 << "\n";
    cout << e2;
}