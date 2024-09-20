#include <iostream>
#include <string>
#include "MaterialBibliografico.h"
#include "BibliotecaUtils.h"
#include <limits>

using namespace std;

// verifica que entre un entero, en caso de que sea un string muestra el mensaje de valor invalido


void menu() {
    BibliotecaUtils* biblioteca_utils = new BibliotecaUtils();
    int option=6;
    while (option!=0) {

        cout << "---- Gestor de biblioteca ----" << endl;
        cout << "(1) Agregar Material\n(2) Mostrar Informacion\n(3) Buscar Material\n(4) Prestar y Devolver Material\n(5) Gestion de Usuarios\n(0) Salir"<<endl;
        cout << "Elige una opcion: ";

        option = biblioteca_utils->validarNumero();


        switch (option) {
            case 1:
                // agregar material
                biblioteca_utils -> agregarMaterial();
                break;
            case 2:
                // mostrar materiales
                biblioteca_utils -> mostrarInfoMateriales();
                break;
            case 3:
                // buscar material
                biblioteca_utils->buscarObj();
                break;
            case 4:
                // Gestion de prestamos y devoluciones
                biblioteca_utils->gestionMateriales();
                break;
            case 5:
                //Gestion de usuarios, agrega,elimina o busca uno
                biblioteca_utils->gestionUsuarios();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }

    }


}

int main() {
    menu();
    return 0;
}


