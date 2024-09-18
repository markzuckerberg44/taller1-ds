//
// Created by julih on 16-09-2024.
//

#ifndef USER_H
#define USER_H
#include "MaterialBibliografico.h"
#include <string>
using namespace std;



class User {
private:
    string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5] = {nullptr};

public:
    // metodos
    void prestarMaterial();
    void devolverMaterial();
    void mostrarMaterialesPrestados();

    // getters  y setters
    string &get_nombre();
    void set_nombre(const string &nombre);
    int &get_id();
    void set_id(int id);

};



#endif //USER_H
