/**
* Autor: Jesus Guzman Ortega
*Definir Clase pelicula
*/

#include "Video.h"

#ifndef PELICULA_H
#define PELICULA_H

class Pelicula: public Video{    
    private:
    vector<string> datosP;

    public:
    Pelicula();
    Pelicula(vector<string> datosP);
    void mostrarDatos();
};

#endif