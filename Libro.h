//
// Created by julih on 16-09-2024.
//

#pragma once
#include "MaterialBibliografico.h"



class Libro : public MaterialBibliografico {

private:
    string fechaPublicacion;
    string resumen;
    string tipo;

public:

    // constructor

    Libro(string nombre, string isbn, string autor, bool estado, string fechaPublicacion, string resumen);

    // mostrar informacion

    void mostrarInformacion() const override;

    // getters y setters
    string get_fechapublicacion();
    void set_fecha_publicacion(string fecha_publicacion);
    string get_resumen();
    void set_resumen(string resumen);
    string get_tipo();

    ~Libro();



};


