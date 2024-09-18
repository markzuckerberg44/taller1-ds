//
// Created by julih on 16-09-2024.
//
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "User.h"

// implementacion metodos

void User::prestarMaterial() {

}

void User::devolverMaterial() {

}

void User::mostrarMaterialesPrestados() {

    int cont = 0; // este contador lo usamos para ver cuantos materiales posee el usuario

    for (int i = 0 ; i < 5; i++) {
        if (materialesPrestados[i]!=nullptr) {
            materialesPrestados[i] -> mostrarInformacion();
            cont++;
        }
    }

    // si el usuario no posee ningun material entonces printeamos lo siguiente
    if (cont == 0) {
        cout << "Este usuario no posee materiales" << endl;
    }
}

// implementacion getters & setters


string &User::get_nombre() {
    return nombre;
}

void User::set_nombre(const string &nombre) {
    this -> nombre = nombre;
}

int &User::get_id() {
    return id;
}

void User::set_id(int id) {
    this -> id = id;
}
