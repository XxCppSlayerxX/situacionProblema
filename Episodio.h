/**
* Autor: Jesus Guzman Ortega
* Definir Clase episodio
*/

#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"
#include <vector>

class Episodio: public Video{
    private:
    vector<string> datosE;

    public:
    Episodio(); // Constructor por defecto
    Episodio(vector<string> datosE); // Constructor que recibe los datos del episodio
    bool esSerie(string serie); // Verifica si el episodio pertenece a una serie dada
    void mostrarDatos(); // Muestra los datos del episodio
    string getNombreE() const; // Devuelve el nombre del episodio
    string getTemporada() const; // Devuelve el número de temporada del episodio
    string getNEpisodio() const; // Devuelve el número del episodio
    friend ostream& operator<<(ostream& output, const Episodio* pelicula); // Sobrecarga del operador de inserción para mostrar los datos del episodio
};

#endif
