//
// Created by terry davis on 16-09-2024.
//
#pragma once
#include <string>
using namespace std;


class MaterialBibliografico {
private:
    string nombre;
    string isbn;
    string autor;
    string idUsuario;
    bool estado;
public:

    MaterialBibliografico(string nombre, string isbn, string autor, bool estado);
    virtual void mostrarInformacion() const;
    virtual string type() const=0;

    // getters y setters
    string get_nombre();
    void set_nombre(string nombre);
    string get_isbn();
    void set_isbn(string isbn);
    string get_autor();
    void set_autor(string autor);
    bool get_estado();
    void set_estado(bool estado);
    string get_id();
    void set_id(string idUsuario);
    // destructor
    virtual ~MaterialBibliografico();

};


