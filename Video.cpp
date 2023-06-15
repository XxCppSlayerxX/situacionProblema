#include "Video.h"
#include <iostream>

Video::Video(){}

Video::Video(vector<string> datos) : datos(datos){}

bool Video::filtrarCalif(double calif){
    if(stod(datos[4]) >= calif){
        return true;
    }else{
        return false;
    }
}

bool Video::filtrarGen(string genero){
    vector<string> generos;
    string palabra = "";
    for(int i = 0; i < datos[3].length(); i++){
        if(datos[3][i] != '&'){
            palabra.push_back(datos[3][i]);
        }else{
            generos.push_back(palabra);
            palabra = "";
        }
    }
    generos.push_back(palabra);

    for(int i = 0; i < generos.size(); i++){
        if(genero == generos[i]){
            return true;
        }
    }
    return false;
}

void Video::setCalif(const string& calif){
    datos[4] = calif;
}

string Video::getNombre() const{
    return datos[1];
}

string Video::getDuracion() const{
    return datos[2];
}

string Video::getEstreno() const{
    return datos[5];
}

string Video::getGenero() const{
    return datos[3];
}

string Video::getCalif() const{
    return datos[4];
}

ostream &operator<<(ostream &output, const Video& video){
    video.imprimir(output);
    return output;
}
