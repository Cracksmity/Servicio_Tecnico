//
// Created by guero on 27/09/2025.
//

#ifndef SERVICIO_TECNICO_SERVICIO_TECNICO_H
#define SERVICIO_TECNICO_SERVICIO_TECNICO_H
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

#include "lista_estatica.h"
#include "pila_estatica.h"
#include "cola_estatica.h"
#include "tipo.h"

template <size_t MAX_SIZE>
class ServicioTecnico {
private:
    ListaEstatica<Equipo, MAX_SIZE> registros;     // LISTA: registro de equipos
    PilaEstatica<Equipo, MAX_SIZE>  almacen;       // PILA: almacén (LIFO)
    ColaEstatica<Equipo, MAX_SIZE>  mantenimiento; // COLA: mantenimiento (FIFO)
public:
    ServicioTecnico() {
        cout << "🛠️  ==== Servicio Técnico ====\n";
        cout << "⚙️  Sistema inicializado con capacidad para " << MAX_SIZE << " equipos\n";
    }

    void ejecutarMenu() {
        int op;
        do {
            cout << "📋 ==== Menu Principal ====\n";
            cout << "🛎️  RECEPCION\n";
            cout << "1. Recibir equipo\n";
            cout << "2. Ver registro\n";
            cout << "📦  ALMACEN (Fila)\n";
            cout << "🔧  Mantenimiento (Cola)\n";
            cout << "🧩  Otros\n";
            cout << "10. Cargar datos de ejemplo\n";
            cout << "11. Exportar datos en CSV\n";
            cin >> op;

            switch (op) {
                case 1:
                    // (Tu lógica de recepción va aquí si la agregas en otro lado)
                    break;
                case 2:
                    verRegistro();
                    break;
                case 10:
                    cargarDatosEjemplo();
                    break;
                case 11:
                    exportarCSV();
                    break;
                case 0:
                    cout << "Bye" << endl;
                    break;
                default:
                    break;
            }
        } while (op != 0);
    }

    void recibirEquipo(Equipo equipo) {
        registros.agregar_final(equipo);
    }

    void verRegistro() {
        cout << left
             << setw(6)  << "ID"
             << setw(16) << "Cliente"
             << setw(14) << "Equipo"
             << setw(14) << "Marca"
             << setw(16) << "Modelo"
             << setw(22) << "Problema"
             << setw(14) << "Estado"
             << setw(12) << "Fecha"
             << right << '\n';

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

    void exportarCSV() {
        ofstream archivo("registro.csv");
        if (!archivo.is_open()) {
            cout << "✘ Error al crear el archivo\n";
            return;
        }

        for (size_t i = 0; i < registros.getContador(); i++) {
            archivo << registros[i].getId() << ','
                    << registros[i].getCliente() << ','
                    << registros[i].getTipoEquipo() << ','
                    << registros[i].getMarca() << ','
                    << registros[i].getModelo() << ','
                    << registros[i].getProblema() << ','
                    << registros[i].getEstado() << ','
                    << registros[i].getFecha() << '\n';
        }
        archivo.close();
        cout << "✔ Exportado a registro.csv\n";
    }
};

#endif // SERVICIO_TECNICO_SERVICIO_TECNICO_H
