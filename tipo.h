//
// Created by guero on 27/09/2025.
//

#ifndef SERVICIO_TECNICO_TIPO_H
#define SERVICIO_TECNICO_TIPO_H

#include <iostream>
using namespace std;

class Equipo {
private:
    int id;
    string cliente;
    string tipoEquipo;
    string marca;
    string modelo;
    string problema;
    string estado;
    string fecha;
public:
    Equipo(int id, string cliente, string tipoEquipo, string marca, string modelo, string estado, string fecha) {
        Equipo::id = id;
        Equipo::cliente = cliente;
        Equipo::tipoEquipo = tipoEquipo;
        Equipo::marca = marca;
        Equipo::modelo = modelo;
        Equipo::estado = estado;
        Equipo::fecha = fecha;
        Equipo::estado = "Recibido";
    }

    int getId() { return id; }
    string getCliente() { return cliente; }
    string getTipoEquipo() { return tipoEquipo; }
    string getMarca() { return marca; }
    string getModelo() { return modelo; }
    string getEstado() { return estado; }
    string getFecha() { return fecha; }
};
#endif //SERVICIO_TECNICO_TIPO_H