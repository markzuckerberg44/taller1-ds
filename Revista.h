//
// Created by julih on 16-09-2024.
//

#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"


class Revista : public MaterialBibliografico {
private:
    int numEdicion;
    int mesPublicacion;

public:

    Revista(string &nombre, string &isbn, string &autor, bool estado, int num_edicion, int mes_publicacion)
        : MaterialBibliografico(nombre, isbn, autor, estado),
          numEdicion(num_edicion),
          mesPublicacion(mes_publicacion) {
    }

    void mostrarInformacion() const override;

    // getters & setters
    int & get_numEdicion();
    void set_numEdicion(int num_edicion);
    int & get_mesPublicacion();
    void set_mesPublicacion(int mes_publicacion);
};



#endif //REVISTA_H
