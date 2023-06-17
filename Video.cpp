#include "Video.h"
#include <iostream>

Video::Video(){}

Video::Video(vector<string> datos) : datos(datos){}

bool Video::filtrarCalif(double calif){
    // Compara la calificación del video con la calificación filtrada
    if(stod(datos[4]) >= calif){
        return true;
    }else{
        return false;
    }
}

bool Video::filtrarGen(string genero){
    vector<string> generos;
    string palabra = "";
    // Divide la cadena de géneros en elementos individuales
    for(int i = 0; i < datos[3].length(); i++){
        if(datos[3][i] != '&'){
            palabra.push_back(datos[3][i]);
        }else{
            generos.push_back(palabra);
            palabra = "";
        }
    }
    generos.push_back(palabra);

    // Comprueba si el género filtrado coincide con alguno de los géneros del video
    for(int i = 0; i < generos.size(); i++){
        if(genero == generos[i]){
            return true;
        }
    }
    return false;
}

void Video::setCalif(const string& calif){
    // Establece la calificación del video
    datos[4] = calif;
    cout << "Calificación guardada exitosamente." << endl << endl;
}

string Video::getNombre() const{
    // Obtiene el nombre del video
    return datos[1];
}

string Video::getDuracion() const{
    // Obtiene la duración del video
    return datos[2];
}

string Video::getEstreno() const{
    // Obtiene el año de estreno del video
    return datos[5];
}

string Video::getGenero() const{
    // Obtiene el género del video
    return datos[3];
}

string Video::getCalif() const{
    // Obtiene la calificación del video
    return datos[4];
}

void Video::imprimir(ostream &output) const
{
}

ostream &operator<<(ostream &output, const Video& video){
    // Utiliza la función virtual pura "imprimir" para mostrar los datos del video
    video.imprimir(output);
    return output;
}
