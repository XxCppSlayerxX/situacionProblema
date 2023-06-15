#include "Episodio.h"
#include <iostream> 

using namespace std; 

Episodio::Episodio(): Video(){
    datos[1] = "Nombre";
    datos[2] = "Duración";
    datos[5] = "Estreno";
    datos[3] = "Genero";
    datos[4] = "Calificacion";
    datos[6] = ("NombreEpisodio"); // Agrega "NombreEpisodio" al vector de datos en la posición 6
    datos[7] = ("Temporada"); // Agrega "Temporada" al vector de datos en la posición 7
    datos[8] = ("NumEpisodio"); // Agrega "NumEpisodio" al vector de datos en la posición 8
}

Episodio::Episodio(vector<string> datosE) : Video(datosE), datosE(datosE) {}

bool Episodio::esSerie(string serie){
    if((datosE[1]) == serie){ // Compara el nombre de la serie con el valor en la posición 1 de datosE
        return true;
    }
    return false;
}

void Episodio::mostrarDatos(){
    cout << "Serie: " << getNombre() << " / Capítulo: " << getNombreE() << endl;
    cout << "Temporada: " << getTemporada() << " / Episodio: " << getNEpisodio() << endl;
    cout << "Duración: " << getDuracion() << " min." << endl;
    cout << "Estreno: " << getEstreno() << " / Genéro: " << getGenero() << endl;
    cout << "Calificación: " << getCalif() << "/10" << endl;

    cout << endl;
}

string Episodio::getNombreE() const{
    return datosE[7]; // Devuelve el valor en la posición 7 de datosE (NombreEpisodio)
}

string Episodio::getTemporada() const{
    return datosE[8]; // Devuelve el valor en la posición 8 de datosE (Temporada)
}

string Episodio::getNEpisodio() const{
    return datosE[9]; // Devuelve el valor en la posición 9 de datosE (NumEpisodio)
}

//sobrecarga al operador << para poder hacer cout con objeto Episodio
ostream& operator<<(ostream& output, const Episodio* episodio) {
    output << "Serie: " << episodio->getNombre() << " / Capítulo: " << episodio->getNombreE() << endl
        << "Temporada: " << episodio->getTemporada() << " / Episodio: " << episodio->getNEpisodio() << endl
        << "Duración: " << episodio->getDuracion() << " min." << endl
        << "Estreno: " << episodio->getEstreno() << " / Género: " << episodio->getGenero() << endl
        << "Calificación: " << episodio->getCalif() << "/10" << endl
        << endl;
    return output;
}
