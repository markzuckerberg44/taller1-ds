//
// Created by terry davis on 16-09-2024.
//
#pragma once
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <iostream>
#include <string>
using namespace std;


class MaterialBibliografico {
private:
    string nombre, isbn, autor;
    bool estado;
public:
    MaterialBibliografico(string &nombre, string &isbn, string &autor, bool estado);

    // metodo para mostrar informacion de los objetos
    virtual void mostrarInformacion() const;

    // getters y setters
    string& getNombre();
    void set_nombre(const string &nombre);
    string& getIsbn();
    void set_isbn(const string &isbn);
    string& getAutor();
    void set_autor(const string &autor);
    bool& getEstado();
    void set_estado(bool estado);

    // destructor
    virtual ~MaterialBibliografico();

};



#endif //MATERIALBIBLIOGRAFICO_H
