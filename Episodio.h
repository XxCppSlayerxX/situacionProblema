/**
* Autor: Jesus Guzman Ortega
*Definir Clase episodio
*/

#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"
#include <vector>

class Episodio: public Video{
    private:
    vector<string> datosE;

    public:
    Episodio();
    Episodio(vector<string> datosE);
    bool esSerie(string serie);
    void mostrarDatos();
    string getNombreE() const;
    string getTemporada() const;
    string getNEpisodio() const;
    friend ostream& operator<<(ostream& output, const Episodio* pelicula);
    void imprimir(ostream& output) const override;
};

#endif