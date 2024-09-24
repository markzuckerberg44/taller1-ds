//
// Created by julih on 17-09-2024.
// Modified by Angel on 20-09-2024.
//

#include "BibliotecaUtils.h"
#include <iostream>
#include <string>
#include <limits>

//retorna puntero de libro o revista si lo encuentra por el nombre
MaterialBibliografico* buscarPorNombre(string nombre,MaterialBibliografico* biblioteca[]){
    int c=0;
    for(int i = 0; i < 100; i++) {
        if(biblioteca[i] != nullptr) {
            c++;
            if(biblioteca[i]->get_nombre()==nombre) {
                return biblioteca[i];
            }
        }
    }
    if(c>0) {
        cout<<"Libro inexistente"<<endl;
    }else {
        cout<<"No hay materiales por el momento"<<endl;
    }

    return nullptr;
}
//retorna puntero de libro o revista si lo encuntra por autor
MaterialBibliografico* buscarPorAutor(string autor,MaterialBibliografico* biblioteca[]) {
    int c=0;
    for(int i = 0; i < 100; i++) {
        if(biblioteca[i] != nullptr) {
            c++;
            if(biblioteca[i]->get_autor()==autor) {
                return biblioteca[i];
            }
        }
    }
    if(c>0) {
        cout<<"Autor inexistente"<<endl;
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
int validarNumeroBiblioteca() {
    int numero=0;
    while (!(cin>>numero)) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"valor ingresado invalido, favor de ingresar un numero entero: "<<endl;
    }
    return numero;
}

// funcion complementaria para prestamos o devolucion de materiales
int opcionDeBusqueda() {
    int opcion=0;
    cout <<"(1) Titulo\n(2) Autor\n";
    cout << ">";
    opcion = validarNumeroBiblioteca();
    int cont =0;
    do {
        if(cont>0) {
            cout<<"Valor ingresado invalido, por favor ingrese un valor entero entre 1 o 2"<<endl;
            opcion = validarNumeroBiblioteca();
        }
        cont++;
    }while (opcion<1||opcion>2);
    return opcion;
}


void BibliotecaUtils::agregarMaterial() {
    string name, isbn, author, published, resumen;
    int numEdicion, mesPublicacion;


    int tipo=0;
    cout<<"Escoga el tipo de material a ingresar: "<<endl;
    tipo = opcionDeBusqueda();
    cin.ignore(1000,'\n');
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

    MaterialBibliografico* obj;
    string titulo, autor;
    int opcion=0;
    cout<<"En base a que desea buscar?"<<endl;
    opcion = opcionDeBusqueda();
    cin.ignore(1000,'\n');

    switch (opcion) {
        case 1:
            // titulo
            cout << "Ingrese titulo:";
            getline(cin, titulo);
            obj = buscarPorNombre(titulo, biblioteca);
            obj->mostrarInformacion();
            break;
        case 2:
            //autor
            cout << "Ingrese autor:";
            getline(cin, autor);
            obj = buscarPorAutor(autor, biblioteca);
            obj->mostrarInformacion();
            break;
        default:
        break;
    }

}


void BibliotecaUtils::gestionUsuarios() {
    int option=0;
    string nombre;
    int id=0;
    int n = 1;
    cout<<"(1) Crear un usuario"<<endl;
    cout<<"(2) Eliminar un usuario"<<endl;
    cout<<"(3) Buscar un usuario"<<endl;
    cout<<"Elige una opcion: "<<endl;
    option = validarNumeroBiblioteca();
    cin.ignore(1000,'\n');
    switch (option) {
        case 1:
        cout<<"Nombre: ";
        getline(cin, nombre);

        cout<<"\nID: ";
        id=validarNumeroBiblioteca();
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
            id=validarNumeroBiblioteca();
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
            id=validarNumeroBiblioteca();
            cin.ignore(1000,'\n');
            n=busquedaPorId(id,users);

            if(n>=0) {
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
    int opcion=0;
    string dato;
    int id=0;
    int indice=-1;
    int n;
    MaterialBibliografico* material;
    if(users.size()==0) {
        cout<<"No hay usuarios por el momento, por lo que no se pueden hacer los cambios"<<endl;
        return;
    }
    cout<<"(1) Prestamo de material"<<endl;
    cout<<"(2) Devolucion de materiales prestados"<<endl;
    opcion = validarNumeroBiblioteca();
    switch (opcion) {
        case 1:
            cout<<"En base a que deseas buscar?"<<endl;
            n=opcionDeBusqueda();
            cin.ignore(1000,'\n');
            if(n==1) {
                cout<<"Nombre del material: "<<endl;
                getline(cin, dato);
                material=buscarPorNombre(dato,biblioteca);
            }else {
                cout<<"Nombre del autor: "<<endl;
                getline(cin, dato);
                material=buscarPorAutor(dato,biblioteca);
            }
            if(material!=nullptr&&material->get_estado()) {

                cout<<"Ingrese la id del usuario al que se va hacer el prestamo: ";
                id=validarNumeroBiblioteca();
                indice=busquedaPorId(id,users);
                cin.ignore(1000,'\n');
                if(indice>-1) {
                    users[indice].prestarMaterial(material);
                }else {
                    cout<<"Id no existente"<<endl;
                }
            }
            break;
        case 2:
            cout<<"Ingrese la id del usuario al que se va hacer la devolucion: ";
            id=validarNumeroBiblioteca();
            indice=busquedaPorId(id,users);
            cin.ignore(1000,'\n');
            if(indice==-1) {
                return;
            }
            cout<<"En base a que deseas buscar?"<<endl;
            n=opcionDeBusqueda();
            cin.ignore(1000,'\n');
            if(n==1) {
                cout<<"Nombre del material: "<<endl;
                getline(cin, dato);
                material=buscarPorNombre(dato,biblioteca);
            }else {
                cout<<"Nombre del autor: "<<endl;
                getline(cin, dato);
                material=buscarPorAutor(dato,biblioteca);
            }
            if(material!=nullptr) {
                users[indice].devolverMaterial(material->get_isbn());
            }
            break;
        default:
            break;
    }
}

