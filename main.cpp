/**
* Autor: Jesus Guzman Ortega
*archivo main
*/

#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "LeerArchivo.h"
#include <iostream>

using namespace std;

int main(){
    cout << "Bienvenido a su serivicio de streaming, por favor "
    "selecciona el número de alguna opción: \n" << endl;

    cout << "1.- Cargar el archivo de datos." << endl;
    cout << "2.- Filtrar películas o series por calificación o " 
    "género."<< endl;
    cout << "3.- Ver episodios lista de episodios de una serie." << endl;    
    cout << "4.- Filtrar películas por calificación." << endl;
    cout << "5.- Calificar película o serie." << endl;
    cout << "6.- Promedio de calificación de serie" << endl;
    cout << "7.- Salir" << endl;
    return 0;
}
