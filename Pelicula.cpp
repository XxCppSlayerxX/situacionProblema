#include "Pelicula.h"
#include <iostream>
using namespace std;

Pelicula::Pelicula() : Video() {
    datos[1] = "Nombre";
    datos[2] = "Duración";
    datos[5] = "Estreno";
    datos[3] = "Genero";
    datos[4] = "Calificacion";
}

Pelicula::Pelicula(vector<string> datosP) : Video(datosP), datosP(datosP) {}

void Pelicula::mostrarDatos() {
    cout << "Película: " << getNombre() << endl;
    cout << "Duración: " << getDuracion() << " min." <<  endl;
    cout << "Estreno: " << getEstreno() << " / Género: " << getGenero() << endl;
    cout << "Calificación: " << getCalif() << "/10" << endl;
    cout << endl;
}

ostream& operator<<(ostream& output, const Pelicula* pelicula) {
    output << "Película: " << pelicula->getNombre() << endl
           << "Duración: " << pelicula->getDuracion() << " min." <<  endl
           << "Estreno: " << pelicula->getEstreno() << " / Género: " << pelicula->getGenero() << endl
           << "Calificación: " << pelicula->getCalif() << "/10" << endl
           << endl;
    return output;
}

void Pelicula::imprimir(ostream& output) const {
    output << "";
}
