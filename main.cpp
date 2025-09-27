/*#include <iostream>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "tipo.h"
#include "servicio_tecnico.h"
using namespace std;

void pruebas();

int main() {

    _setmode(_fileno(stdout), _O_U16TEXT);
    // pruebas();
    /*wcout << L"🛠️ Sistema de servicio técnico\n";
    wcout << L"🗂️ LISTA: Registro de equipo\n";
    wcout << L"📦 PILA: Almacén (LIFO — Last In First Out)\n";
    wcout << L"🔧 COLA: Mantenimiento (FIFO — First In First Out)\n";

    ServicioTecnico<10> st;
    st.ejecutarMenu();
    return 0;
}

void pruebas() {
    Equipo e1(1, "Michel Davalos", "Laptop", "HP", "Omen 16", "No enciende");
    e1.setFecha("2025/09/27");

    Equipo e2(2, "Johan Suarez", "Desktop", "Gigabyte", "Aorus", "Disco Corrupto");
    e2.setFecha("2025/09/27");

    cout << e1 << "\n";
    cout << e2;
}*/


// main.cpp
#include <iostream>
#ifdef _WIN32
  #include <windows.h>
#endif
using namespace std;

#include "tipo.h"
#include "servicio_tecnico.h"

int main() {
#ifdef _WIN32
    // Para que se vean tildes/emojis en la consola de Windows (opcional)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // Instancia con capacidad para 10 equipos
    ServicioTecnico<10> st;

    // Lanza el menú interactivo
    st.ejecutarMenu();

    return 0;
}
