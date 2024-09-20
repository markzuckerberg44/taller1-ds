#include <iostream>
#include <string>
#include "MaterialBibliografico.h"
#include "BibliotecaUtils.h"
#include <limits>

using namespace std;

void menu() {
    BibliotecaUtils* biblioteca_utils = new BibliotecaUtils();

    while (true) {
        cout << "---- Gestor de biblioteca ----" << endl;
        cout << "(1) Agregar Material\n(2) Mostrar Informacion\n(3) Buscar Material\n(4) Prestar y Devolver Material\n(5) Gestion de Usuarios\n(0) Salir\n";
        cout << "Elige una opcion: ";

        int option;
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer

        if (option == 1) {
            // agregar material
            biblioteca_utils -> agregarMaterial();

        } else if (option == 2) {
            // mostrar materiales
            biblioteca_utils -> mostrarInfoMateriales();

        } else if (option == 3){
            biblioteca_utils->buscarObj();

        } else if (option == 4) {

        } else if (option == 5) {

        } else if (option == 0) {

        }

    }
}

int main() {
    menu();
    return 0;
}


