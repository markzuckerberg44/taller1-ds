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
}

// implementacion metodos

/*
 *se evalua si se puede prestar el material al usuario
 *@MaterialBibliografico *material elemento a prestar
 */
void User::prestarMaterial(MaterialBibliografico *material) {
    if (!material->get_estado()) {
        cout << "Material no disponible" << endl;
        return;
    }
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] == nullptr) {
            material->set_estado(false);
            material->set_id(to_string(id));
            materialesPrestados[i] = material;
            return;
        }
    }
    cout << "El usuario no tiene espacios disponibles para aceptar material" << endl;
}

/*
 *se devuelve el material seleccionado dentro del metodo si es que hay en existencia
 */
void User::devolverMaterial() {

    int c = 0;//con esto se comprueba si hay elementos en el array materialesPrestados

    for (int i = 0; i < 5; i++) {
        //si el elemento no es nullptr lo muestra
        if (materialesPrestados[i] != nullptr) {

            if (c == 0) {
                //cuando aparece por primera ves un elemento se muestra este mensaje
                cout << "A continuacion se mostraran los materiales disponibles del usuario" << endl;
                c=1;
            }
            //se muestran los datos por consola
            cout << i << ") nombre: " << materialesPrestados[i]->get_nombre() << " autor: " << materialesPrestados[i]->get_autor() <<
                    " isbn: " << materialesPrestados[i]->get_isbn() << endl;
        }
    }
    if(c==0) {
        //en caso de que no se entrara al
        cout<<"el usuario no tiene materiales disponibles"<<endl;
    }else {
        string isbn ="";
        cout<<"escriba el isbn del material a devolver:\n";
        while(c!=0){
            if(c>1) {
                cout <<"ISBN mal escrito \n>"<< endl;
            }
            c++;
            string dato="";//se usara para eliminar los espacios vacios
            getline(cin, isbn);
            for(char letra :isbn) {
                if(letra!=' ') {
                    dato+=letra;
                }
            }
            isbn = dato;

            for(int i=0;i<5;i++) {
                if(materialesPrestados[i]!=nullptr) {
                    string isbnMaterial="";
                    for(char letra:materialesPrestados[i]->get_isbn()) {
                        if(letra!=' ') {
                            isbnMaterial+=letra;
                        }
                    }
                    if(isbnMaterial==isbn) {
                        materialesPrestados[i]->set_id("");
                        materialesPrestados[i]->set_estado(true);
                        materialesPrestados[i]=nullptr;
                        c=0;
                        break;
                    }

                }
            }
        }
    }
}
/*
 *
 */
void User::devolverTodosLosMateriales() {
    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] != nullptr) {
            materialesPrestados[i]->set_estado(true);
            materialesPrestados[i]->set_id("");
            materialesPrestados[i] = nullptr;
        }
    }
}

//se mostrara la materiales prestados si es que hay en existencia
void User::mostrarMaterialesPrestados() {
    int cont = 0; // este contador lo usamos para ver cuantos materiales posee el usuario

    for (int i = 0; i < 5; i++) {
        if (materialesPrestados[i] != nullptr) {
            cout << "------------------------" << endl;
            materialesPrestados[i]->mostrarInformacion();
            cout << "------------------------" << endl;
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
    this->nombre = nombre;
}

int User::get_id() {
    return id;
}

void User::set_id(int id) {
    this->id = id;
}

MaterialBibliografico **User::get_materialePrestados() {
    return materialesPrestados;
}

User::~User() {
}
