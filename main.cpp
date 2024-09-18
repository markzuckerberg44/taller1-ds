#include <iostream>
#include <string>
#include "MaterialBibliografico.h"
#include "BibliotecaUtils.h"
using namespace std;


// menu interactivo
void menu () {
    BibliotecaUtils biblioteca_utils;
    cout << "---- Gestor de biblioteca ----" << endl;
    cout << "(1) Agregar Material\n(2) Mostrar Informacion\n(3) Buscar Material\n(4) Prestar y Devolver Material\n(5) Gestion de Usuarios\n(0) Salir\n";
    cout << "Elige una opcion:";

    int option;
    cin >> option;

    switch (option) {
        case 1:
            // agregar material

            biblioteca_utils.agregarMaterial();
            break;
        case 2:
            // mostrar info
            cout << "nigger" << endl;

            break;
        case 3:
            // buscar material
            cout << "nigger" << endl;
            break;
        case 4:
            // gestionar material (prestar y devolver)

            cout << "nigger" << endl;
            break;
        case 5:
            // gestion de usuarios

            cout << "nigger" << endl;
            break;
        case 0:
            // salir
            cout << "programada cerrado exitosamente" << endl;
            exit(0);

        default:
            cout << "Elija una opcion valida" << endl;
            break;
    }

}

int main() {
    menu();
    return 0;
}


