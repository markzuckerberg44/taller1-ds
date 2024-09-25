//
// Created by julih on 16-09-2024.
//

#include <string>
#include "MaterialBibliografico.h"
#include <iostream>
using namespace std;


MaterialBibliografico::MaterialBibliografico(string nombre, string isbn, string autor, bool estado) {
    this -> nombre = nombre;
    this -> isbn = isbn;
    this -> autor = autor;
    this -> estado = estado;
}

string MaterialBibliografico::type() const {

}


void MaterialBibliografico::mostrarInformacion() const {
    cout << "Nombre: " << nombre << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Autor: " << autor << endl;
    cout << "Estado: " << (estado ? "Disponible" : "Prestado") << endl;
}

string MaterialBibliografico::get_nombre() {
    return nombre;
}

void MaterialBibliografico::set_nombre(string nombre) {
    this -> nombre = nombre;
}

string MaterialBibliografico::get_isbn() {
    return isbn;
}

void MaterialBibliografico::set_isbn(string isbn) {
    this -> isbn = isbn;
}

string MaterialBibliografico::get_autor() {
    return autor;
}

void MaterialBibliografico::set_autor(string autor) {
    this -> autor = autor;
}

bool MaterialBibliografico::get_estado() {
    return estado;
}

void MaterialBibliografico::set_estado(bool estado) {
    this -> estado = estado;
}

MaterialBibliografico::~MaterialBibliografico() {
    cout << "Destructor de material llamado" << endl;
}
