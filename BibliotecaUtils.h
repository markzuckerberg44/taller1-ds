//
// Created by julih on 17-09-2024.
// Modified by Angel on 20-09-2024.
//

#pragma once
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
    void gestionMateriales();
    void gestionUsuarios();
    void guardarInformacionBiblioteca();
    void cargarArchivoBiblioteca();


};

