//
// Created by julih on 17-09-2024.
// Modified by Angel on 20-09-2024.
//

#include "BibliotecaUtils.h"
#include <fstream>
#include <iostream>
#include <string>
#include <limits>


// ver si se repite o no un isbn
bool checkIsbn(string isbn, MaterialBibliografico* biblioteca[]) {
    if(isbn == "") {
        cout <<"isbn invalido debe contener al menos un dato"<<endl;
        return true;
    }

    for(int i = 0; i < 100; i++) {
        if(biblioteca[i]!=nullptr&&biblioteca[i]->get_isbn()==isbn) {
            cout << "ISBN no disponible, por favor ingrese otro" << endl;
            cout << ">";
            //retorna true si es que esta ocupado
            return true;
        }
    }

    return false;
}

//retorna puntero de libro o revista si lo encuentra por el nombre
MaterialBibliografico* buscarPorNombre(string nombre,MaterialBibliografico* biblioteca[]){
    int c=0;
    for(int i = 0; i < 100; i++) {
        if(biblioteca[i] != nullptr) {
            c++;
            if(biblioteca[i]->get_nombre()==nombre) {
                if(biblioteca[i]->get_estado()) {
                    return biblioteca[i];
                }
                c=-1;
            }
        }
    }
    switch (c) {
        case -1:
            cout<<"No hay unidades disponibles"<<endl;
        break;
        case 0:
            cout<<"No hay materiales por el momento"<<endl;
        break;
        default:
            cout<<"Material inexistente"<<endl;
        break;
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
                if(biblioteca[i]->get_estado()){return biblioteca[i];}
                c=-1;
            }
        }
    }
    switch (c) {
        case -1:
            cout<<"No hay unidades del autor disponibles"<<endl;
            break;
        case 0:
            cout<<"No hay materiales por el momento"<<endl;
            break;
        default:
            cout<<"Autor inexistente"<<endl;
            break;
    }
    return nullptr;
}

//busca si hay un usuario por su id
int busquedaPorId(int id,vector<User>& users) {

    for(int i=0;i<users.size();i++) {
        if(users[i].get_id()==id) {
            //retorna el indice en el que esta
            return i;
        }
    }
    //en caso de no haber un usuario retorna -1 para dar a entender que no hay
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
    int numEdicion, mesPublicacion, cont;

    cont = 0;
    int tipo=0;
    cout<<"Escoga el tipo de material a ingresar:\n(1) Libro\n(2) Revista"<<endl;
    tipo = validarNumeroBiblioteca();
    cin.ignore(1000,'\n');
    switch (tipo) {
        case 1:
            cout << "Nombre: ";
            getline(cin, name);
            cout << "ISBN: ";
            // verificamos si existe o es invalido el isbn
            do {
                string dato = ""; //con esto se eliminara los espacios
                getline(cin, isbn);
                for(char i:isbn) {
                    if(i!=' ') {
                        dato+=i;
                    }
                }
                isbn = dato;
            } while (checkIsbn(isbn,biblioteca));


            cout << "Autor: ";
            getline(cin, author);
            cout << "Fecha de publicacion: ";
            getline(cin, published);
            cout << "Resumen: ";
            getline(cin, resumen);

            // agregamos el material a la biblioteca
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
            // verificamos si existe o es invalido el isbn
            do {
                string dato = ""; //con esto se eliminara los espacios
                getline(cin, isbn);
                for(char i:isbn) {
                    if(i!=' ') {
                        dato+=i;
                    }
                }
                isbn = dato;
            } while (checkIsbn(isbn,biblioteca));


            cout << "Autor: ";
            getline(cin, author);
            cout << "Numero de edicion: ";
            cin >> numEdicion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
            cout << "Mes de publicacion: ";
            mesPublicacion = validarNumeroBiblioteca();
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
            cout<<"Opción invalida haga el favor de ingresar 1 o 2"<<endl;
            tipo = validarNumeroBiblioteca();
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
            if (obj != nullptr) {
                obj->mostrarInformacion();
            }
            break;
        case 2:
            //autor
            cout << "Ingrese autor:";
            getline(cin, autor);
            obj = buscarPorAutor(autor, biblioteca);
            if (obj != nullptr) {
                obj->mostrarInformacion();
            }
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
        if(users.empty()) {
            cout<<"Usuario agregado"<<endl;
            users.emplace_back(nombre,id);
        } else {
            n=busquedaPorId(id,users);
            if(n==-1) {
                cout<<"Usuario agregado"<<endl;
                users.emplace_back(nombre,id);
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
                return;
            }
            cout<<"Ingrese la ID del usuario: "<<endl;
            id=validarNumeroBiblioteca();
            cin.ignore(1000,'\n');
            n=busquedaPorId(id,users);

            if(n>=0) {
                cout<<"Nombre: "<<users[n].get_nombre()<<endl;
                cout<<"ID: "<<users[n].get_id()<<endl;
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

    if(users.empty()) {
        cout<<"No hay usuarios por el momento, por lo que no se pueden hacer los cambios"<<endl; // aqui es la wea
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
            }else {
                users[indice].devolverMaterial();
            }

            break;
        default:
            break;
    }
}

void BibliotecaUtils::guardarInformacionBiblioteca() {
    /*ofstream limpiar("EstadoBiblioteca.txt", std::ios::trunc);
    limpiar.close();*/

    ofstream archivo("EstadoBiblioteca.txt",ios::out);
    if(!archivo) {
        cerr<<"No se puede encontrar el archivo en EstadoBiblioteca.txt"<<endl;
        return;
    }
    for(MaterialBibliografico* material : biblioteca) {
        if (material != nullptr) {
            archivo << material->type()<<",";
            archivo << material->get_nombre() << ",";
            archivo << material->get_isbn() << ",";
            archivo << material->get_autor() << ",";
            archivo << (material->get_estado() ? "Disponible" : "No disponible") << ",";

            if(Libro* libro=dynamic_cast<Libro*>(material)){
                archivo << libro->get_fechapublicacion() << ",";
                archivo << libro->get_resumen() << ",";
            }else{
                Revista* revista=dynamic_cast<Revista*>(material);
                archivo<<revista->get_numEdicion()<<",";
                archivo<<revista->get_mesPublicacion()<<",";
            }
            archivo << material->get_id() << "\n";
        }
    }
    archivo.close();
    ofstream archivo2("Usuarios.txt",ios::out);
    if(!archivo2) {
        cerr<<"No se puede encontrar el archivo en Usuarios.txt"<<endl;
        return;
    }
    for(User usuario : users) {
        archivo2<<usuario.get_nombre()<<",";
        archivo2<<usuario.get_id()<<",";
        MaterialBibliografico** array = usuario.get_materialePrestados();
        int cont = 0;
        string dato = "";
        for(int i=0;i<5;i++) {
            if(array[i] != nullptr) {
                cont++;
                dato += array[i]->get_isbn()+";";
            }
        }
        archivo2<<cont<<","<<dato<<"\n";

    }
    archivo2.close();
    cout << "Estado de la biblioteca guardado en EstadoBiblioteca.txt y Usuarios.txt" << endl;
}

/* -----------------------------------------------------------------
 * METODO PARA SPLITEAR UN STRING Y RETORNAR SUS SECCIONES EN UN VECTOR
 * -----------------------------------------------------------------
 */

vector<string> BibliotecaUtils::split(string str, char delim) {

    vector<string> result;
    string temp = ""; // variable temporal para crear string nuevos

    for (char i : str) {
        if(i==delim) {
            result.push_back(temp);
            temp = ""; // se resetea cada vez que el char == al delimitador que recibe el metodo
        } else {
            temp+=i; // si es que no es lo mismo que el delimitador entonces agregamos el char a la variable temporal
        }
    }

    if (!temp.empty()) {
        result.push_back(temp); // aca lo hacemos en caso de que salga del loop y la variable temporal siga conteniendo material
    }

    return result;
}

/* -----------------------------------------------------------------
 * METODO PARA CARGAR OBJETOS LEYENDO UN ARCHIVO .TXT
 * -----------------------------------------------------------------
 */

void BibliotecaUtils::cargarArchivoBiblioteca() {

    string myText;
    ifstream MyReadFile("EstadoBiblioteca.txt");

    // verificamos si el archivo se abrio correctamente
    if (!MyReadFile.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (getline(MyReadFile,myText)) {
        vector<string> partes = split(myText,',');

        if (partes.size() < 7) {
            cout << "Línea mal formateada o con menos columnas de las esperadas." << endl;
            continue;  // Saltar a la siguiente línea si no hay suficientes datos
        }

        string tipo = partes.at(0);
        bool dispo;

        // tranformamos el valor de un string a un booleano para poder cargar la biblioteca
        if (partes.at(4) == "Disponible") {
            dispo = true;
        } else {
            dispo = false;
        }

        //obtenemos el indice de la posición nullptr
        int indice = -1;
        for(int i = 0; i < 100; i++) {
            if (biblioteca[i] == nullptr) {
                indice = i;
            }
        }
        if(indice == -1) {
            cout<<"Limite excedido "<<endl;
            break;
        }

        if (tipo=="libro") {

            Libro* lib = new Libro(partes.at(1),partes.at(2), partes.at(3), dispo, partes.at(5), partes.at(6));

            biblioteca[indice] = lib;
        } else if (tipo=="revista") {

            Revista* rev = new Revista(partes.at(1),partes.at(2),partes.at(3),dispo,stoi(partes.at(5)),stoi(partes.at(6)));

            biblioteca[indice] = rev;

        } else {
            cout << "Tipo de material no identificado" << endl;
        }
        if(partes.size() > 7) {
            biblioteca[indice]->set_id(partes.at(7));
        }

    }

    // cerramos el archivo
    MyReadFile.close();

}

/* -----------------------------------------------------------------
 * METODO QUE CARGA USUARIOS A PARTIR DE UN .TXT
 * -----------------------------------------------------------------
 */
void BibliotecaUtils::cargarArchivoUsuarios() {

    string myText;
    ifstream MyReadFile("Usuarios.txt");
    string material[5];
    // verificamos si el archivo se abrio correctamente
    if (!MyReadFile.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    int contUser = -1;
    while (getline(MyReadFile,myText)) {
        contUser++;
        vector<string> partes = split(myText,',');
        if (partes.size() < 3) {
            cout<< "Linea mal formateada o con menos datos de los esperados"<<endl;
            continue;
        }
        string nombre = partes.at(0);
        int id = stoi (partes.at(1));
        users.emplace_back(nombre,id);
        int cont=0;
        int tamaño = stoi(partes.at(2));//esto es la cantidad de materiles prestados

        if(partes.size()==3){continue;}//esto es por si no hay materiales prestados

        vector<string> materiales = split(partes.at(3),';');

        for(int j=0;j<5;j++) {
            if(j<tamaño) {
                material[j] = materiales[j];
            }else {
                material[j]=" ";
            }
        }

        string idUser = to_string(users[contUser].get_id() );
        for(MaterialBibliografico* mat : biblioteca) {
            if(mat != nullptr) {
                string isbn = mat->get_isbn();
                string idUserInMat = mat->get_id();
                if(isbn==material[0]&&idUser==idUserInMat) {
                    mat->set_estado(true);
                    users[contUser].prestarMaterial(mat);
                    cont++;
                }else if(isbn==material[1]&&idUser==idUserInMat) {
                    mat->set_estado(true);
                    users[contUser].prestarMaterial(mat);
                    cont++;
                }else if(isbn==material[2]&&idUser==idUserInMat) {
                    mat->set_estado(true);
                    users[contUser].prestarMaterial(mat);
                    cont++;
                }else if(isbn==material[3]&&idUser==idUserInMat) {
                    mat->set_estado(true);
                    users[contUser].prestarMaterial(mat);
                    cont++;
                }else if(isbn==material[4]&&idUser==idUserInMat) {
                    mat->set_estado(true);
                    users[contUser].prestarMaterial(mat);
                    cont++;
                }
            }
        }
    }
    // cerramos el archivo
    MyReadFile.close();
}
