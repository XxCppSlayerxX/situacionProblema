/*
Leer el archivo de texto en c++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> separar(string linea);

int main(){
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int cont = 1;

    while (getline(entrada, linea)){
        vector<string> datos = separar(linea);
    if(datos.size() == 6){
        cout << "pelicula";
        new pelicula(datos);
    }else{
        cout << "episodio";
    }
    cout << endl;
    }
    entrada.close();
    return 0;
}

vector<string> separar(string linea){
    vector<string> tokens;       // componentes 1 linea
    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;
    int numeroTokens = 0;
    while (getline(entrada, dato, ',')){
        if (dato != "" && dato != "\n" && dato != "\r"){
            tokens.push_back(dato); //guarda en el vector 
        }
    }
    return tokens;
}