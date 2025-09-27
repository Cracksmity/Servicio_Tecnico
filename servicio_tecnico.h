//
// Created by guero on 27/09/2025.
//

#ifndef SERVICIO_TECNICO_SERVICIO_TECNICO_H
#define SERVICIO_TECNICO_SERVICIO_TECNICO_H

#include "lista_estatica.h"
#include "pila_estatica.h"
#include "cola_estatica.h"


template <size_t MAX_SIZE>
class ServicioTecnico {
private:
    ListaEstatica<Equipo, MAX_SIZE> registros;     // LISTA: registro de equipos
    PilaEstatica<Equipo, MAX_SIZE>  almacen;       // PILA: almacén (LIFO)
    ColaEstatica<Equipo, MAX_SIZE>  mantenimiento; // COLA: mantenimiento (FIFO)
public:
    ServicioTecnico() {
        wcout << L"🛠️  ==== Servicio Técnico ====\n";
        wcout << L"⚙️  Sistema inicializado con capacidad para " << MAX_SIZE << " equipos\n";
    }

    void ejecutarMenu() {
        int op;

        do {
            wcout << L"📋 ==== Menu Principal ====" << '\n';
            wcout << L"🛎️  RECEPCION" << '\n';
            wcout << "1. Recibir equipo" << '\n';
            wcout << "2. Ver registro" << '\n';
            wcout << L"📦  ALMACEN (Fila)" << '\n';
            wcout << L"🔧  Mantenimiento (Cola)" << '\n';
            wcout << L"🧩  Otros" << '\n';
            wcout << "10. Cargar datos de ejemplo" << '\n';
            wcin >> op;

            switch (op) {
                case 1:
                    break;
                case 2:
                    verRegistro();
                    break;
                case 10:
                    cargarDatosEjemplo();
                    break;
                case 0:
                    wcout << "Bye" << endl;
            }
        } while (op != 0);
    }

    void recibirEquipo(Equipo equipo) {
        registros.agregar_final(equipo);
    }
    void verRegistro() {
        wcout << left
        << setw(6)  << "ID"
            << setw(16) << "Cliente"
            << setw(14) << "Equipo"
            << setw(14) << "Marca"
            << setw(16) << "Modelo"
            << setw(22) << "Problema"
            << setw(14) << "Estado"
            << setw(12) << "Fecha"
        << right << endl;
        for (size_t i = 0; i < registros.getContador(); i++) {
            cout << registros[i] << '\n';
        }
    }
    void cargarDatosEjemplo() {
        Equipo e1(1, "Michel Davalos", "Laptop", "HP", "Omen 16", "No enciende");
        e1.setFecha("2025/09/27");

        Equipo e2(2, "Johan Suarez", "Desktop", "Gigabyte", "Aorus", "Disco Corrupto");
        e2.setFecha("2025/09/27");

        Equipo e3(3, "Karen López", "Laptop", "Lenovo", "ThinkPad T14", "Pantalla parpadea");
        e3.setFecha("2025/09/27");

        Equipo e4(4, "Sergio Ramírez", "Consola", "Sony", "PlayStation 5", "No lee discos");
        e4.setFecha("2025/09/27");

        Equipo e5(5, "Paola Torres", "Impresora", "Epson", "L3150", "Líneas en la impresión");
        e5.setFecha("2025/09/27");

        recibirEquipo(e1); recibirEquipo(e2); recibirEquipo(e3); recibirEquipo(e4); recibirEquipo(e5);
    }
};

#endif //SERVICIO_TECNICO_SERVICIO_TECNICO_H