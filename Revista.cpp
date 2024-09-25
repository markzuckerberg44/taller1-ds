//
// Created by julih on 16-09-2024.
//

#include "Revista.h"
#include <iostream>

Revista::Revista(string nombre, string isbn, string autor, bool estado, int numEdicion, int mesPublicacion) : MaterialBibliografico(nombre,isbn,autor,estado) {
    this -> numEdicion = numEdicion;
    this -> mesPublicacion = mesPublicacion;
    this -> tipo = "revista";
}

void Revista::mostrarInformacion() const {
    MaterialBibliografico::mostrarInformacion();
    cout << "Numero de edicion:" << numEdicion << endl;
    cout << "Mes de publicacion:" << mesPublicacion << endl;
}

int Revista::get_numEdicion() {
    return numEdicion;
}

void Revista::set_numEdicion(int num_edicion) {
    this -> numEdicion = numEdicion;
}

int Revista::get_mesPublicacion() {
    return mesPublicacion;
}

void Revista::set_mesPublicacion(int mes_publicacion) {
    this -> mesPublicacion = mes_publicacion;
}

string Revista::get_tipo() {
    return tipo;
}

Revista::~Revista() {
    cout << "Destructor de revista ha sido llamado" << endl;
}