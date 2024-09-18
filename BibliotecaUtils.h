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
    Libro* cargarLibro(string nombre, string isbn, string autor, bool estado, string published, string resumen);
    Revista* cargarRevista(string nombre, string isbn, string autor, bool estado, int numEdicion, int mesPublicacion);
    void agregarMaterial();
    void mostrarInfoMateriales();
    MaterialBibliografico buscarObj();
    void buscarMaterial();
    void gestionMateriales();
    void gestionUsuarios();


};



#endif //BIBLIOTECAUTILS_H
