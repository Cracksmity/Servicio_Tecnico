#ifndef COLA_ESTATICA_H_INCLUDED
#define COLA_ESTATICA_H_INCLUDED

#include "lista_estatica.h"

// Cola = Queue
template<typename T, size_t MAX_SIZE>
class ColaEstatica {
private:
    ListaEstatica<T, MAX_SIZE> lista;

public:
    ColaEstatica() {}

    // enqueue
    void encolar(T valor) {
        if (lista.llena()) {
            cout << "Cola llena" << endl;
            return;
        }
        lista.agregar_final(valor);
    }

    // dequeue
    void desencolar() {
        if (lista.vacia()) {
            cout << "Cola vacía" << endl;
            return;
        }
        lista.eliminar_inicio();
    }

    T& inicio() {
        if (lista.vacia()) {
            throw underflow_error("Cola vacía");
        }
        return lista[0];
    }

    bool vacia() {
        return lista.vacia();
    }

    bool llena() {
        return lista.llena();
    }

};


#endif // COLA_ESTATICA_H_INCLUDED
