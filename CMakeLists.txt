cmake_minimum_required(VERSION 3.16)
project(taller1ds)

set(CMAKE_CXX_STANDARD 17)

# Agrega los archivos fuente
add_executable(taller1ds
        main.cpp
        MaterialBibliografico.cpp
        User.cpp
        Libro.cpp
        Revista.cpp
        BibliotecaUtils.cpp
)

