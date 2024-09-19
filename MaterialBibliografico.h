//
// Created by terry davis on 16-09-2024.
//
#pragma once
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <string>
using namespace std;


class MaterialBibliografico {
private:
    string nombre;
    string isbn;
    string autor;
    bool estado;
public:

    MaterialBibliografico(string nombre, string isbn, string autor, bool estado);
    virtual void mostrarInformacion() const;

    // getters y setters
    string get_nombre();
    void set_nombre(string nombre);
    string get_isbn();
    void set_isbn(string isbn);
    string get_autor();
    void set_autor(string autor);
    bool get_estado();
    void set_estado(bool estado);

    // destructor
    virtual ~MaterialBibliografico();

};



#endif //MATERIALBIBLIOGRAFICO_H
