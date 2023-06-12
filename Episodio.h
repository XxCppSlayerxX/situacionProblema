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
    
};

#endif