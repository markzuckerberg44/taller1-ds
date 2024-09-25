//
// Created by julih on 16-09-2024.
// Modified by Angel on 19-09-2024
//
#include "User.h"
#include <iostream>
//contructor
User::User(string nombre, int id) {
    this->nombre = nombre;
    this->id = id;
    for(int i = 0; i < 5; i++) {
        materialesPrestados[i] = nullptr;
    }
}

// implementacion metodos

void User::prestarMaterial(MaterialBibliografico* material) {

    for(int i=0;i<5;i++){
        if(materialesPrestados[i]==nullptr){
            material->set_estado(false);
            materialesPrestados[i]=material;
            return;
        }
    }
    cout<<"El usuario no tiene espacios disponibles para aceptar material"<<endl;
}

void User::devolverMaterial(string isbn) {
    int c=0;//contador para comprobar que si existen materiles a disposicion
    for(int i=0;i<5;i++) {
        if(materialesPrestados[i]!=nullptr) {
            if(materialesPrestados[i]->get_isbn()==isbn) {
                materialesPrestados[i]->set_estado(true);
                materialesPrestados[i]=nullptr;
                cout<<"Material devuelto"<<endl;
                break;
            }
            c++;
        }
    }
    if(c>0) {
        cout<<"Isbn "+isbn+" no coincide con ninguno dentro de los materiales prestados"<<endl;
    }else {
        cout<<"El usuario no tiene materiales"<<endl;
    }

}

void User::devolverTodosLosMateriales() {
    for(int i=0;i<5;i++) {
        if(materialesPrestados[i]!=nullptr) {
            materialesPrestados[i]->set_estado(true);
            materialesPrestados[i]=nullptr;
        }
    }
}


void User::mostrarMaterialesPrestados() {

    int cont = 0; // este contador lo usamos para ver cuantos materiales posee el usuario

    for (int i = 0 ; i < 5; i++) {
        if (materialesPrestados[i]!=nullptr) {
            cout<<"------------------------"<<endl;
            materialesPrestados[i] -> mostrarInformacion();
            cout<<"------------------------"<<endl;
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

MaterialBibliografico** User::get_materialePrestados() {
    return materialesPrestados;
}

User::~User() {
}

