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
        cout << "🛠️  ==== Servicio Técnico ====\n";
        cout << "⚙️  Sistema inicializado con capacidad para " << MAX_SIZE << " equipos\n";
    }

    void ejecutarMenu() {
        cout << "📋 ==== Menu Principal ====" << '\n';
        cout << "🛎️  RECEPCION" << '\n';
        cout << "📦  ALMACEN (Fila)" << '\n';
        cout << "🔧  Mantenimiento (Cola)" << '\n';
        cout << "🧩  Otros" << '\n';
    }

};

#endif //SERVICIO_TECNICO_SERVICIO_TECNICO_H