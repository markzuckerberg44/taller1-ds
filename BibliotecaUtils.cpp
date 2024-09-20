//
// Created by julih on 17-09-2024.
// Modified by Angel on 20-09-2024.
//

#include "BibliotecaUtils.h"
#include <iostream>
#include <string>
#include <limits>

//retorna puntero de libro si lo encuentra por el isbn
MaterialBibliografico* busquedaPorIsbn(string isbn,MaterialBibliografico* biblioteca[]){
    int c=0;
    for(int i = 0; i < 100; i++) {
        if(biblioteca[i] != nullptr) {
            c++;
            if(biblioteca[i]->get_isbn()==isbn) {
                return biblioteca[i];
            }
        }
    }
    if(c>0) {
        cout<<"Isbn inexistente"<<endl;
    }else {
        cout<<"No hay materiales por el momento"<<endl;
    }

    return nullptr;
}

//busca si hay un usuario por su id
int busquedaPorId(int id,vector<User>& users) {

    for(int i=0;i<users.size();i++) {
        if(users[i].get_id()==id) {
            return i;
        }
    }
    return -1;
}

// verifica que entre un entero, en caso de que sea un string muestra el mensaje de valor invalido
int BibliotecaUtils::validarNumero() {
    int numero=0;
    while (!(cin>>numero)) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"valor ingresado invalido, favor de ingresar un numero entero: "<<endl;
    }
    cin.ignore();//limpiar buffer
    return numero;

}

void BibliotecaUtils::agregarMaterial() {
    string name, isbn, author, published, resumen;
    int numEdicion, mesPublicacion;

    cout <<"(1) Libro\n(2) Revista" << endl;
    cout << "Elige una opcion: ";
    int tipo;
    tipo = validarNumero();

    switch (tipo) {
        case 1:
            cout << "Nombre: ";
            getline(cin, name);
            cout << "ISBN: ";
            getline(cin, isbn);
            cout << "Autor: ";
            getline(cin, author);
            cout << "Fecha de publicacion: ";
            getline(cin, published);
            cout << "Resumen: ";
            getline(cin, resumen);

            for (int i = 0 ; i < 100 ; i++) {
                if (biblioteca[i] == nullptr) {
                    Libro* lib = new Libro(name,isbn,author,true,published,resumen);
                    biblioteca[i] = lib;
                    cout << "Material agregado en la posicion:" << i << endl;
                    break;
                }
            }
            break;
        case 2:
            cout << "Nombre: ";
            getline(cin, name);
            cout << "ISBN: ";
            getline(cin, isbn);
            cout << "Autor: ";
            getline(cin, author);
            cout << "Numero de edicion: ";
            cin >> numEdicion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
            cout << "Mes de publicacion: ";
            cin >> mesPublicacion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

            for (int j = 0 ; j < 100 ; j++) {
                if (biblioteca[j] == nullptr) {
                    Revista* rev = new Revista(name,isbn,author,true,numEdicion,mesPublicacion);
                    biblioteca[j] = rev;
                    cout << "Material agregado en la posicion:" << j << endl;
                    break;
                    }
                }
            break;
        default:
            break;
    }

}

void BibliotecaUtils::mostrarInfoMateriales() {
    for(int l = 0; l < 100 ; l++) {
        if (biblioteca[l] != nullptr) {
            biblioteca[l]->mostrarInformacion();
            cout << "--------------------" << endl;
        }
    }
}

void BibliotecaUtils::buscarObj() {

    string titulo, autor;
    int opcion;
    cout << "En base a que deseas buscar?:\n(1) Titulo\n(2) Autor\n";
    cout << ">";
    opcion = validarNumero();

    if (opcion == 1) {
        // titulo
        cout << "Ingrese titulo:";
        getline(cin, titulo);

        for (int i = 0 ; i < 100 ; i++) {
            if (biblioteca[i] != nullptr) {
                if (biblioteca[i]->get_nombre() == titulo) {
                    biblioteca[i]->mostrarInformacion();
                    cout << "-------------------" << endl;
                    //break;
                }
            }
        }

    } else if (opcion == 2) {

        cout << "Ingrese autor:";
        getline(cin, autor);

        for (int j = 0 ; j < 100 ; j++) {
            if (biblioteca[j] != nullptr) {
                if (biblioteca[j]->get_autor() == autor) {
                    biblioteca[j]->mostrarInformacion();
                    cout << "-------------------" << endl;
                    //break;
                }
            }
        }

    } else {
        cout << "Ingrese una opcion valida" << endl;
    }

}


void BibliotecaUtils::gestionUsuarios() {
    int option;
    string nombre;
    int id;
    int n = 1;
    bool true_or_false = true;
    cout<<"(1) Crear un usuario"<<endl;
    cout<<"(2) Eliminar un usuario"<<endl;
    cout<<"(3) Buscar un usuario"<<endl;
    cout<<"Elige una opcion: "<<endl;
    option = validarNumero();
    switch (option) {
        case 1:
        cout<<"Nombre: ";
        getline(cin, nombre);

        cout<<"\nID: ";
        id=validarNumero();
        if(users.size()==0) {
            cout<<"Usuario agregado"<<endl;
            users.push_back(User(nombre,id));
        }else {
            n=busquedaPorId(id,users);
            if(n==-1) {
                cout<<"Usuario agregado"<<endl;
                users.push_back(User(nombre,id));
            }
        }
        break;
        case 2:
            if(users.size()==0) {
                cout<<"No hay usuarios por el momento"<<endl;
            }
            cout<<"Ingrese la ID del usuario: "<<endl;
            id=validarNumero();
            n=busquedaPorId(id,users);
            if(n>-1) {
                users[n].devolverTodosLosMateriales();
                users.erase(users.begin()+n);
                cout<<"Usuario eliminado y los materiales fueron devueltos"<<endl;

            }
        break;
        case 3:
            if(users.size()==0) {
                cout<<"No hay usuarios por el momento"<<endl;
            }
            cout<<"Ingrese la ID del usuario: "<<endl;
            id=validarNumero();
            n=busquedaPorId(id,users);
            if(n>-1) {
                cout<<"Nombre: "+users[n].get_nombre()<<endl;
                cout<<"ID: "+users[n].get_id()<<endl;
                cout<<"Materiales prestados: "<<endl;
                users[n].mostrarMaterialesPrestados();
            }
        break;
        default:
            cout<<"opcion ingresada invalida"<<endl;
        break;
    }
}

void BibliotecaUtils::gestionMateriales() {
    int opcion;
    string isbn;
    int id;
    int indice;
    MaterialBibliografico* material;
    if(users.size()==0) {
        cout<<"No hay usuarios por el momento, por lo que no se pueden hacer los cambios"<<endl;
        return;
    }
    cout<<"(1) Prestamo de material"<<endl;
    cout<<"(2) Devolucion de materiales prestados"<<endl;
    opcion = validarNumero();
    switch (opcion) {
        case 1:
            cout<<"Ingrese el isbn del material: ";
            getline(cin, isbn);
            material = busquedaPorIsbn(isbn,biblioteca);
            if(material!=nullptr&&material->get_estado()) {

                cout<<"Ingrese la id del usuario al que se va hacer el prestamo: ";
                id=validarNumero();
                indice=busquedaPorId(id,users);
                if(indice>-1) {
                    users[indice].prestarMaterial(material);
                }else {
                    cout<<"Id no existente"<<endl;
                }
            }
            break;
        case 2:
            cout<<"Ingrese la id del usuario al que se va hacer la devolucion: ";
            id=validarNumero();
            indice=busquedaPorId(id,users);
            if(indice>-1) {
                cout<<"Ingrese el isbn del material: ";
                getline(cin, isbn);
                material = busquedaPorIsbn(isbn,biblioteca);
                if(material!=nullptr) {
                    users[indice].devolverMaterial(isbn);
                    break;
                }else{
                    cout<<"Isbn no existente"<<endl;
                }
            }
            break;
        default:
            break;
    }
}

