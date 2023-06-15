/**
* Autor: Jesus Guzman Ortega
* Definir Clase Pelicula
*/

#include "Video.h"
#include <iostream>
using namespace std;

#ifndef PELICULA_H
#define PELICULA_H

class Pelicula: public Video{    
    private:
    vector<string> datosP;

    public:
    Pelicula(); // Constructor por defecto
    Pelicula(vector<string> datosP); // Constructor con parámetros
    void mostrarDatos(); // Método para mostrar los datos de la película   
    friend ostream& operator<<(ostream& output, const Pelicula* pelicula); // Sobrecarga del operador de inserción <<
};

#endif
