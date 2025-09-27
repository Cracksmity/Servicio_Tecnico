#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

#include <iostream>
using namespace std;


template<typename T, size_t MAX_SIZE>
class ListaEstatica {
private:
    T arreglo[MAX_SIZE];
    size_t contador;

public:
    ListaEstatica() {
        contador = 0;
    }

    void agregar_final(T valor) {
        if (contador == MAX_SIZE) return;
        arreglo[contador] = valor;
        contador++;
    }

    void agrear_inicio(T valor) {
        if (contador == MAX_SIZE) return;
        // copiar los elementos a su siguiente posición, es decir, mover a la derecha
        for (size_t i = contador; i > 0; i--) {
            arreglo[i] = arreglo[i-1];
        }
        arreglo[0] = valor;
        contador++;
    }

    void agregar(T valor, size_t pos) {
        if (contador == MAX_SIZE) return;
        if (pos >= contador) {
            cout << "Posición invalida" << endl;
            return;
        }
        // copiar los elementos a su siguiente posición, es decir, mover a la derecha
        for (size_t i = contador; i > pos; i--) {
            arreglo[i] = arreglo[i-1];
        }
        arreglo[pos] = valor;
        contador++;
    }

    void eliminar_final() {
        if (contador == 0) return;
        contador--;
    }

    void eliminar_inicio() {
        if (contador == 0) return;
        // copiar de derecha a izquierda
        for (size_t i = 0; i < contador; i++) {
            arreglo[i] = arreglo[i+1];
        }
        contador--;
    }

    void eliminar(size_t pos) {
        if (contador == 0) return;
        if (pos >= contador) {
            cout << "Posición inválida" << endl;
            return;
        }

        for (size_t i = pos; i < contador; i++) {
            arreglo[i] = arreglo[i+1];
        }
        contador--;
    }

    void mostrar() {
        cout << "[";
        for (size_t i = 0; i < contador; i++) {
            cout << arreglo[i] << ",";
        }
        cout << "]" << endl;
    }

    bool vacia() {
        return contador == 0;
    }

    bool llena() {
        return contador == MAX_SIZE;
    }

    size_t getContador() {
        return contador;
    }
    // sobrecargar los []
    T& operator[](size_t posicion) {
        return arreglo[posicion];
    }


};

#endif // LISTA_ESTATICA_H_INCLUDED
