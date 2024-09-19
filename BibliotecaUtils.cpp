//
// Created by julih on 17-09-2024.
//

#include "BibliotecaUtils.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

void BibliotecaUtils::agregarMaterial() {

    string name, isbn, author, published, resumen;
    int numEdicion, mesPublicacion;

    cout << "(1) Libro\n(2) Revista" << endl;
    cout << "Elige una opcion: ";
    int tipo;
    cin >> tipo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

    if (tipo == 1) {

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

    } else if (tipo == 2) {

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

    }





}

void BibliotecaUtils::mostrarInfoMateriales() {
    for (int l = 0; l<100 ; l++) {
        if (biblioteca[l] != nullptr) {
            biblioteca[l]->mostrarInformacion();
            cout << "--------------------" << endl;
        }
    }
}

MaterialBibliografico * BibliotecaUtils::buscarObj() {


}
