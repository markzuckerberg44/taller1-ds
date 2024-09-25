//
// Created by julih on 16-09-2024.
//

#pragma once
#include "MaterialBibliografico.h"


class Revista : public MaterialBibliografico {
private:
    string tipo;
    int numEdicion;
    int mesPublicacion;

public:


    Revista(string nombre, string isbn, string autor, bool estado, int numEdicion, int mesPublicacion);
    void mostrarInformacion() const override;


    // getters & setters
    int get_numEdicion();
    void set_numEdicion(int num_edicion);
    int get_mesPublicacion();
    void set_mesPublicacion(int mes_publicacion);
    string get_tipo();

    ~Revista();
};

