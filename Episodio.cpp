#include "Episodio.h"
#include <iostream>

using namespace std;

Episodio::Episodio(){
}

Episodio::Episodio(vector<string> datosE) : Video(datosE), datosE(datosE) {}

bool Episodio::esSerie(string serie){
    if((datosE[1]) == serie){
        return true;
    }
    return false;
}

void Episodio::mostrarDatos(){
    cout << "Serie: " << datosE[1] << " / Capítulo: " << datosE[7] << endl;
    cout << "Temporada: " << datosE[8] << " / Episodio: " << datos[9] << endl;
    cout << "Duración: " << datosE[2] << " min." << endl;
    cout << "Estreno: " << datosE[5] << " / Genéro: " << datos[3] << endl;
    cout << "Calificación: " << datosE[4] << "/10" << endl; 

    cout << endl;
}
