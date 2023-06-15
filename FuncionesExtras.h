#ifndef FUNCIONESEXTRAS_H
#define FUNCIONESEXTRAS_H

#include <vector>
#include <string>
#include "Video.h"


vector<string> separar(string linea);
vector<Video*> LeerArchivo(); //Utiliza a separar
void menu(); //imprime menu
double verificar(); //checa que el input de calificaciones sea correcto de valores entre 0 y 10
string generos(); // checa que el input de géneros sea correcto de valores entre 0 y 10
string verificarP(vector<string> pelisYseries); //verifica si la serie existe 
string convertirAMinusculas(const string& palabra); // convierte palabras a minusculas
string convertirPrimeraLetraMayuscula(const string& cadena); // convierte Primera Letra a Mayuscula

#endif