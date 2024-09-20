//
// Created by julih on 17-09-2024.
//

#ifndef BIBLIOTECAUTILS_H
#define BIBLIOTECAUTILS_H
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"
#include "User.h"
#include <vector>
#include "Libro.h"
#include "Revista.h"
using namespace std;



class BibliotecaUtils {
private:
    vector<User> users;
    MaterialBibliografico *biblioteca[100]; // array de punteros predefinido
    int numMateriales = 0;

public:

    void agregarMaterial();
    void mostrarInfoMateriales();
    void buscarObj();
    void buscarMaterial();
    void gestionMateriales();
    void gestionUsuarios();


};



#endif //BIBLIOTECAUTILS_H
