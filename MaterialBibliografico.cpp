//
// Created by julih on 16-09-2024.
//

#include <string>
#include "MaterialBibliografico.h"

using namespace std;


MaterialBibliografico::MaterialBibliografico(string &nombre, string &isbn, string &autor, bool estado) {
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> estado = estado;
}

void MaterialBibliografico::mostrarInformacion() const {
    cout << nombre << endl;
    cout << isbn << endl;
    cout << autor << endl;

    // dejamos el estado del libro en un lenguaje mas amigable

    if (estado == true) {
        cout << "Disponible" << endl;
    } else if (estado == false) {
        cout << "Prestado" << endl;
    } else { // control de errores
        cout << "Error al buscar estado / Estado no encontrado" << endl;
    }

}

string & MaterialBibliografico::getNombre() {
    return nombre;
}

void MaterialBibliografico::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string & MaterialBibliografico::getIsbn() {
    return isbn;
}

void MaterialBibliografico::set_isbn(const string &isbn) {
    this->isbn = isbn;
}

string & MaterialBibliografico::getAutor() {
    return autor;
}

void MaterialBibliografico::set_autor(const string &autor) {
    this->autor = autor;
}

bool & MaterialBibliografico::getEstado() {
    return estado;
}

void MaterialBibliografico::set_estado(bool estado) {
    this -> estado = estado;
}

MaterialBibliografico::~MaterialBibliografico() {
    cout << "Destructor de material llamado" << endl;
}
