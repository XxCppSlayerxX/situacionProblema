/*
Leer el archivo de texto en c++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <cctype>
#include "Episodio.h"
#include "Pelicula.h"
#include "FuncionesExtras.h"

using namespace std;

// Declaración de funciones
vector<string> separar(string linea);
vector<Video*> LeerArchivo();
void menu();
double verificar();
string generos();

// Función para leer el archivo de datos y crear objetos de Video
vector<Video*> LeerArchivo() {
    vector<Video*> videos;

    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    bool primera = true;

    while (getline(entrada, linea)){

        vector<string> datos = separar(linea);

        if (primera){primera = false; continue;}

        if(datos.size() == 6){
            videos.push_back(new Pelicula(datos));
        }else{
            videos.push_back(new Episodio(datos));
        }
    }
    entrada.close();
    
    return videos;
}

// Función para separar una línea en tokens utilizando una coma como delimitador
vector<string> separar(string linea){
    vector<string> tokens;       // componentes de una línea
    stringstream entrada(linea); // flujo de datos a partir de una cadena
    string dato;
    int numeroTokens = 0;
    while (getline(entrada, dato, ',')){
        if (dato != "" && dato != "\n" && dato != "\r"){
            tokens.push_back(dato); // guarda en el vector
        }
    }
    return tokens;
}

// Función para mostrar el menú principal
void menu(){
    cout << "Menu principal, por favor tecleé el número de alguna opción: \n" << endl;
    cout << "NO OLVIDE CARGAR EL ARCHIVO DE DATOS,PRESIONANDO 1" << endl << endl;;

    cout << "1.- Cargar el archivo de datos." << endl;
    cout << "2.- Filtrar películas o series por calificación o género."<< endl;
    cout << "3.- Ver lista de episodios de una serie." << endl;    
    cout << "4.- Filtrar películas por calificación." << endl;
    cout << "5.- Calificar película o serie." << endl;
    cout << "6.- Promedio de calificación de serie." << endl;
    cout << "7.- Salir." << endl << endl;
}

// Función para verificar la entrada de calificación del usuario
double verificar(){
    double calif = -1;
    while (true) {
        cout << "Ingrese una calificación (entre 0 y 10): ";
        cin >> calif;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor inválido " << endl;
        } else if (calif >= 0.0 && calif <= 10.0) {
            break;
        } else {
            cout << "El valor debe estar entre 0 y 10. Intente nuevamente." << endl << endl;
        }
    }
    return calif;
}

// Función para mostrar y seleccionar un género de una lista
string generos(){
    int genero = 0;

    vector<string> generos{"1.Accion", "2.Aventura", "3.Drama", "4.Fantasy", "5.Romance", "6.Sci-Fi", "7.Suspenso",
    "8.Familiar", "9.Musical","10.Guerra", "11.Misterio", "12.Comedia", "13.Western", "14.Biografia","15.Crimen"};

    for(int i = 0; i < generos.size(); i++){
        cout << generos[i] << " - ";
    }
    cout << endl;

    while (true) {
        cout << "Tecleé el número del género que desee ver:" << endl;
        cin >> (genero);

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor inválido " << endl;
        } else if (genero >= 1  && genero <= generos.size()) {
            break;
        } else {
            cout << "El valor debe estar entre 1 y " << generos.size() << ". Intente nuevamente." << endl;
        }
        cout << endl << endl;
    }

    string nuevaPalabra;
    for (int i = 0; i < generos[genero-1].length(); i++) {
        if (isalpha(generos[genero-1][i])) {
            nuevaPalabra.push_back(generos[genero-1][i]);
        }
    }

    if(generos[genero-1] != generos[5]){
        generos[genero-1] = nuevaPalabra;
    } else {
        return "Sci-Fi";
    }

    return generos[genero-1];
}


string convertirAMinusculas(const string& palabra) {
    string resultado = palabra;

    for (size_t i = 0; i < resultado.length(); ++i) {
        resultado[i] = tolower(resultado[i]);
    }

    return resultado;
}

string convertirPrimeraLetraMayuscula(const string& cadena) {
    string resultado = cadena;
    bool nuevaPalabra = true;

    for (size_t i = 0; i < resultado.length(); ++i) {
        if (nuevaPalabra && isalpha(resultado[i])) {
            resultado[i] = toupper(resultado[i]);
            nuevaPalabra = false;
        } else if (isspace(resultado[i])) {
            nuevaPalabra = true;
        }
    }

    return resultado;
}

string verificarP(vector<string> pelisYseries) {
    string serieOPelicula;
    int n;

    while (true) {
        cout << "Teclee el nombre por favor: ";
        cin.ignore();
        getline(cin, serieOPelicula);
        serieOPelicula = convertirAMinusculas(serieOPelicula);

        bool serieEncontrada = false;

        for (int i = 0; i < pelisYseries.size(); i++) {
            if (serieOPelicula == pelisYseries[i]) {
                serieEncontrada = true;
                break;
            }
        }

        if (serieEncontrada) {
            break;
        } else {
            cout << "La serie no está en la base de datos, verifique cómo la escribió e inténtelo nuevamente." << endl;
            cout << "Presione 0 para continuar o cualquier otro número para salir." << endl;

            while (!(cin >> n) || cin.fail()) {
                cout << "Input inválido. Por favor, ingrese un número." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (n == 0) {
                continue;
            } else {
                break;
            }
        }

        cout << endl;
    }

    return convertirPrimeraLetraMayuscula(serieOPelicula);
}