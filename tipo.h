//
// Created by guero on 27/09/2025.
//

#ifndef SERVICIO_TECNICO_EQUIPO_H
#define SERVICIO_TECNICO_EQUIPO_H
#pragma once

#include <string>
#include <ostream>
#include <iomanip>
using namespace std;

class Equipo {
private:
    int         id_{};
    string      cliente_;
    string      tipoEquipo_;
    string      marca_;
    string      modelo_;
    string      problema_;
    string      estado_;   // "Recibido", "En revisión", "Reparado", "Entregado"
    string      fecha_;

public:
    // estado por defecto = "Recibido"
    Equipo() {}
    Equipo(int id,
           const string& cliente,
           const string& tipoEquipo,
           const string& marca,
           const string& modelo,
           const string& problema,
           const string& estado = "Recibido",
           const string& fecha = {})
        : id_{id},
          cliente_{cliente},
          tipoEquipo_{tipoEquipo},
          marca_{marca},
          modelo_{modelo},
          problema_{problema},
          estado_{estado},
          fecha_{fecha}
    {}

    // Getters (const-correctness y sin copias)
    int               getId()         const { return id_; }
    const string&     getCliente()    const { return cliente_; }
    const string&     getTipoEquipo() const { return tipoEquipo_; }
    const string&     getMarca()      const { return marca_; }
    const string&     getModelo()     const { return modelo_; }
    const string&     getProblema()   const { return problema_; }
    const string&     getEstado()     const { return estado_; }
    const string&     getFecha()      const { return fecha_; }

    // Setters mínimos
    void setEstado(const string& valor)   { estado_ = valor; }
    void setProblema(const string& valor) { problema_ = valor; }
    void setFecha(const string& valor)    { fecha_ = valor; }

    // Impresión tabular
    friend ostream& operator<<(ostream& out, const Equipo& e) {
        ios::fmtflags f = out.flags(); // guarda flags
        out << left
            << setw(6)  << e.id_
            << setw(16) << e.cliente_
            << setw(14) << e.tipoEquipo_
            << setw(14) << e.marca_
            << setw(16) << e.modelo_
            << setw(22) << e.problema_
            << setw(14) << e.estado_
            << setw(12) << e.fecha_;
        out.flags(f); // restaura flags
        return out;
    }
};

#endif // SERVICIO_TECNICO_EQUIPO_H
