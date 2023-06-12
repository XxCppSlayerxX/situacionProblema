#include "Pelicula.h"
#include <iostream>
using namespace std;

Pelicula::Pelicula(){
}

Pelicula::Pelicula(vector<string> datosP): Video(datosP), datosP(datosP) {}

void Pelicula::mostrarDatos(){
    cout << "Película: " << datosP[1] << endl;
    cout << "Duración: " << datosP[2] << " min." <<  endl;
    cout << "Estreno: " << datosP[5] << " / Género: " << datosP[3] << endl;
    cout << "Calificación: " << datosP[4] << "/10" << endl;
    cout << endl;
}