#include "Pelicula.h"
#include <iostream>
using namespace std;

Pelicula::Pelicula() : Video() {
    datos[1] = "Nombre";           // Asigna un valor predeterminado al campo "Nombre"
    datos[2] = "Duración";         // Asigna un valor predeterminado al campo "Duración"
    datos[5] = "Estreno";          // Asigna un valor predeterminado al campo "Estreno"
    datos[3] = "Genero";           // Asigna un valor predeterminado al campo "Género"
    datos[4] = "Calificacion";     // Asigna un valor predeterminado al campo "Calificación"
}

Pelicula::Pelicula(vector<string> datosP) : Video(datosP), datosP(datosP) {}

void Pelicula::mostrarDatos() {
    cout << "Película: " << getNombre() << endl;               // Imprime el nombre de la película
    cout << "Duración: " << getDuracion() << " min." <<  endl; // Imprime la duración de la película
    cout << "Estreno: " << getEstreno() << " / Género: " << getGenero() << endl;  // Imprime el año de estreno y el género de la película
    cout << "Calificación: " << getCalif() << "/10" << endl;   // Imprime la calificación de la película
    cout << endl;
}

ostream& operator<<(ostream& output, const Pelicula* pelicula) {
    output << "Película: " << pelicula->getNombre() << endl             // Imprime el nombre de la película
           << "Duración: " << pelicula->getDuracion() << " min." <<  endl   // Imprime la duración de la película
           << "Estreno: " << pelicula->getEstreno() << " / Género: " << pelicula->getGenero() << endl  // Imprime el año de estreno y el género de la película
           << "Calificación: " << pelicula->getCalif() << "/10" << endl   // Imprime la calificación de la película
           << endl;
    return output;
}

