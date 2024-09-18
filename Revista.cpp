//
// Created by julih on 16-09-2024.
//

#include "Revista.h"

void Revista::mostrarInformacion() const {
    MaterialBibliografico::mostrarInformacion();
    cout << numEdicion << endl;
    cout << mesPublicacion << endl;
}

//getters & setters
int & Revista::get_numEdicion() {
    return numEdicion;
}

void Revista::set_numEdicion(int num_edicion) {
    this -> numEdicion = num_edicion;
}

int & Revista::get_mesPublicacion() {
    return mesPublicacion;
}

void Revista::set_mesPublicacion(int mes_publicacion) {
    this -> mesPublicacion = mes_publicacion;
}
