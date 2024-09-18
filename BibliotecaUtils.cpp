//
// Created by julih on 17-09-2024.
//

#include "BibliotecaUtils.h"
#include <limits>
#include "Libro.h"

Libro* BibliotecaUtils::cargarLibro(string nombre, string isbn, string autor, bool estado, string published,
                                  string resumen) {
    Libro* lib = new Libro(nombre,isbn,autor,estado,published,resumen);
    return lib;

}

Revista* BibliotecaUtils::cargarRevista(string nombre, string isbn, string autor, bool estado, int numEdicion,
    int mesPublicacion) {
    Revista* rev = new Revista(nombre, isbn, autor, estado, numEdicion, mesPublicacion);
    return rev;
}

//punto 1 - agregar material
void BibliotecaUtils::agregarMaterial() {

    string name;
    string isbn;
    string author;
    string published; // libro
    string resumen; // libro
    int numEdicion; // revista
    int mesPublicacion; // revista

    cout << "(1) Libro\n(2) Revista" << endl;
    cout << "Elige una opcion:";
    int tipo;
    cin >> tipo;
    switch (tipo) {
        case 1: // libro
            /*
            cout << "Nombre: ";
            getline(cin, name);  // Capturar el nombre completo con espacios
            cout << "\n";
            cout << "ISBN: ";
            getline(cin, isbn);  // Capturar ISBN completo
            cout << "\n";
            cout << "Autor: ";
            getline(cin, author);  // Capturar autor con espacios
            cout << "\n";
            cout << "Fecha de publicacion: ";
            getline(cin, published);  // Capturar fecha de publicación
            cout << "\n";
            cout << "Resumen: ";
            getline(cin, resumen);  // Capturar el resumen completo
            */
            // aqui por default en estado asignaremos que el libro esta disponible para prestamos, si el usuario lo presta debera modificarlo desde el UI

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // estas las tuve que agregar porque no se me printeaban bien los saltos de linea

            cout << "Nombre:";
            getline(cin,name);

            cout << "isbn:";
            cin >> isbn;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Autor:";
            getline(cin,author);

            cout << "Fecha de publicacion:";
            getline(cin,published);

            cout << "Resumen:";
            getline(cin,resumen);


            for (int i = 0; i < 100; i++) {
                if (biblioteca[i] == nullptr) {
                    biblioteca[i] = cargarLibro(name, isbn, author, true, published, resumen);
                    numMateriales++;
                    break;
                }
            }

            break;

        case 2: // revista

            cout << "Nombre: ";
            getline(cin, name);  // Esto debería funcionar correctamente

            cout << "ISBN: ";
            getline(cin, isbn);  // Capturar toda la línea para ISBN

            cout << "Autor: ";
            getline(cin, author);  // Captura del autor completo

            cout << "Fecha de publicacion: ";
            getline(cin, published);  // Captura de la fecha de publicación

            cout << "Resumen: ";

            for (int j = 0; j < 100;j++) {
                if (biblioteca[j] == nullptr) {
                    biblioteca[j] = cargarRevista(name,isbn,author,true,numEdicion,mesPublicacion);
                    numMateriales++;
                    break;
                }
            }

            break;

        default:
            cout << "Escoger una opcion valida" << endl;
            break;
    }


}

void BibliotecaUtils::mostrarInfoMateriales() {

    for (int i = 0 ; i < 100 ; i++) {
        if (biblioteca[i] != nullptr) {
            biblioteca[i] -> mostrarInformacion();
        }
    }

}

//MaterialBibliografico BibliotecaUtils::buscarObj() {
//}

void BibliotecaUtils::buscarMaterial() {
}

void BibliotecaUtils::gestionMateriales() {
}

void BibliotecaUtils::gestionUsuarios() {
}
