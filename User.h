//
// Created by julih on 16-09-2024.
// Modific by Angel on 20-09-2024
//
#pragma once
#include "MaterialBibliografico.h"
#include <string>
using namespace std;



class User {
private:
    string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5];
public:
    //contructor de la clase
    User(string nombre, int id);

    // metodos
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(string isbn);
    void mostrarMaterialesPrestados();
    void devolverTodosLosMateriales();

    // getters  y setters
    string &get_nombre();
    void set_nombre(const string &nombre);
    int &get_id();
    void set_id(int id);

    ~User();
};