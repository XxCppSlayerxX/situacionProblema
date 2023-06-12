#include "Video.h"
#include <iostream>

Video::Video(){
}

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
