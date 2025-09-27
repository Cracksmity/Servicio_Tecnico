#ifndef PILA_ESTATICA_H_INCLUDED
#define PILA_ESTATICA_H_INCLUDED

#include "lista_estatica.h"
#include <stdexcept>

// Stack
template<typename T, size_t MAX_SIZE>
class PilaEstatica {
private:
    ListaEstatica<T, MAX_SIZE> lista;
public:
    PilaEstatica() {}
    // push
    void apilar(T valor) {
        if (lista.llena()) {
            cout << "Pila llena" << endl;
            return;
        }
        lista.agregar_final(valor);
    }
    // pop
    void desapilar() {
        if (lista.vacia()) {
            cout << "Pila vacia" << endl;
            return;
        }
        lista.eliminar_final();
    }

    // top
    T& tope() {
        if (lista.vacia()) {
            throw underflow_error("Pila vacia");
        }
        return lista[lista.getContador()-1];
    }

    bool vacia() {
        return lista.vacia();
    }

    bool llena() {
        return lista.llena();
    }


};

#endif // PILA_ESTATICA_H_INCLUDED
