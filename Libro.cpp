//
// Created by julih on 16-09-2024.
//

#include "Libro.h"


void Libro::mostrarInformacion() const {
    MaterialBibliografico::mostrarInformacion();
    cout << fechaPublicacion << endl;
    cout << resumen << endl;
}

string & Libro::get_fechapublicacion() {
    return fechaPublicacion;
}

void Libro::set_fecha_publicacion(const string &fecha_publicacion) {
    this->fechaPublicacion = fecha_publicacion;
}

string & Libro::get_resumen() {
    return resumen;
}

void Libro::set_resumen(const string &resumen) {
    this->resumen = resumen;
}



