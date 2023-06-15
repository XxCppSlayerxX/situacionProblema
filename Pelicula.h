/**
* Autor: Jesus Guzman Ortega
*Definir Clase pelicula
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
    Pelicula();
    Pelicula(vector<string> datosP);
    void mostrarDatos();   
    friend ostream& operator<<(ostream& output, const Pelicula* pelicula);
    void imprimir(ostream& output) const override;

};

#endif