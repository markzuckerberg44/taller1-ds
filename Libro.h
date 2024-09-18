//
// Created by julih on 16-09-2024.
//

#ifndef LIBRO_H
#define LIBRO_H
#include "MaterialBibliografico.h"



class Libro : public MaterialBibliografico {

private:
    string fechaPublicacion;
    string resumen;

public:

    // constructor

    Libro(string &nombre, string &isbn, string &autor, bool estado, const string &fecha_publicacion,
        const string &resumen)
        : MaterialBibliografico(nombre, isbn, autor, estado),
          fechaPublicacion(fecha_publicacion),
          resumen(resumen) {
    }

    // mostrar informacion

    void mostrarInformacion() const override;

    // getters y setters
    string & get_fechapublicacion();
    void set_fecha_publicacion(const string &fecha_publicacion);
    string & get_resumen();
    void set_resumen(const string &resumen);



};



#endif //LIBRO_H
