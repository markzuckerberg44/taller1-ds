//
// Created by julih on 16-09-2024.
//

#include "Libro.h"
#include <iostream>

Libro::Libro(string nombre, string isbn, string autor, bool estado, string fechaPublicacion, string resumen) : MaterialBibliografico(nombre,isbn,autor,estado){
    this -> fechaPublicacion = fechaPublicacion;
    this -> resumen = resumen;

}

string Libro::type() const {
    return "libro";
}

void Libro::mostrarInformacion() const {
    MaterialBibliografico::mostrarInformacion();
    cout << "Fecha de publicacion:" << fechaPublicacion << endl;
    cout << "Resumen:" << resumen << endl;
}

string Libro::get_fechapublicacion() {
    return fechaPublicacion;
}

void Libro::set_fecha_publicacion(string fecha_publicacion) {
    this -> fechaPublicacion = fecha_publicacion;
}

string Libro::get_resumen() {
    return resumen;
}

void Libro::set_resumen(string resumen) {
    this -> resumen = resumen;
}



Libro::~Libro() {
}
