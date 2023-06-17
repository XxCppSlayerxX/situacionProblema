/**
 * Autor: Jesus Guzman Ortega
 * Archivo main
 */

#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "FuncionesExtras.h"
#include <iostream>

using namespace std;

int main(){
    string opc = "0"; // Opción del menú principal
    string subopc = "0"; // Opción del submenú
    string genero, serieOPelicula; // Variables auxiliares
    double calif = 0; // Variable para almacenar la calificación
    int cont = 0; // Contador para verificar la carga del archivo
    
    // Vector de apuntadores a objetos de tipo "Video"
    vector<Video*> videos;

    while(opc != "7"){
        menu(); // Mostrar el menú principal
        cin >> opc;
        if(opc == "1"){
            cont++;
        } 

        if(cont == 0 && cont != 7){
            cout << endl << "ERROR DE CARGA" << endl << "NO HA CARGADO NINGUNA BASE DE DATOS" << endl << endl;
            videos = LeerArchivo();
            cont++;
            continue;
        }  

        if (opc == "1"){
            videos = LeerArchivo();
            cont++;
            if(videos.size() == 0){
                cout << "error, no puedo leer el archivo..." << endl;
                return -1;
            }else{
                cout << "Archivo cargado" << endl;
            } // Leer los datos de archivo y almacenarlos en el vector

        } else if(opc == "2"){
            cout << "Teclee la opción que desee." << endl;
            cout << "1.- Calificación." << endl;
            cout << "2.- Género." << endl;
            cout << "3.- Calificación y género" << endl;

            while (true) {
                cin >> subopc;
                if(subopc == "1"){
                    calif = verificar();
                    for(int i = 0; i < videos.size(); i++){
                        if(videos[i]->filtrarCalif(calif)){
                            videos[i]->mostrarDatos(); // Mostrar datos que cumplan con la calificación especificada
                        }
                    }
                    break;
                } else if(subopc == "2"){
                    genero = generos();
                    for(int i = 0; i < videos.size(); i++){
                        if(videos[i]->filtrarGen(genero)){
                            videos[i]->mostrarDatos(); // Mostrar datos que cumplan con el género especificado
                        }
                    }
                    break;
                } else if(subopc == "3"){
                    calif = verificar();
                    genero = generos();
                    for(int i = 0; i < videos.size(); i++){
                        if(videos[i]->filtrarGen(genero) && videos[i]->filtrarCalif(calif)){
                            videos[i]->mostrarDatos(); // Mostrar datos que cumplan con la calificación y género especificados
                        }
                    }
                    break;
                } else {
                    cout << "Introduzca una opción válida" << endl;
                    continue;
                }
            }

        } else if (opc == "3"){
            vector<string> pelisYseries;

            for(int i = 0; i < videos.size(); i++){
                Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
                Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);

                if (episodio) {
                    pelisYseries.push_back(convertirAMinusculas(episodio->getNombre()));   
                }
            }  

            serieOPelicula = verificarP(pelisYseries);

            for(int i = 0; i < videos.size(); i++){
                Video* video = dynamic_cast<Video*>(videos[i]);
                if(Episodio* episodio = dynamic_cast<Episodio*>(video)){
                    if(episodio->esSerie(serieOPelicula)){
                        cout << episodio; // Mostrar datos de episodios pertenecientes a la serie especificada
                    }
                }
            }

        } else if (opc == "4"){
            calif = verificar();
            for(int i = 0; i < videos.size(); i++){
                Video* video = dynamic_cast<Video*>(videos[i]);
                if(Pelicula* peli = dynamic_cast<Pelicula*>(video)){
                    if(peli->filtrarCalif(calif)){
                        cout << peli; // Mostrar datos de películas que cumplan con la calificación especificada
                    }
                }
            }

        } else if (opc == "5"){
            vector<string> pelisYseries;

            for(int i = 0; i < videos.size(); i++){
                Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
                Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);

                if (episodio) {
                    pelisYseries.push_back(convertirAMinusculas(episodio->getNombreE()));
                } else if (pelicula) {
                    pelisYseries.push_back(convertirAMinusculas(pelicula->getNombre()));   
                }
            }  

            serieOPelicula = verificarP(pelisYseries);
            calif = verificar();
            double& ref = calif;

            for (size_t i = 0; i < videos.size(); i++){
                Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
                Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);

                if (episodio && episodio->getNombreE() == serieOPelicula) {
                    episodio->setCalif(to_string(ref)); // Actualizar la calificación del episodio
                    videos[i] = episodio;    
                    break;
                } else if (pelicula && pelicula->getNombre() == serieOPelicula) {
                    pelicula->setCalif(to_string(ref)); // Actualizar la calificación de la película
                    videos[i] = pelicula;    
                    break;
                }
            }
            
        } else if (opc == "6"){
            vector<string> pelisYseries;

            for(int i = 0; i < videos.size(); i++){
                Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
                Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);

                if (episodio) {
                    pelisYseries.push_back(convertirAMinusculas(episodio->getNombre()));   
                }
            }  

            serieOPelicula = verificarP(pelisYseries);
            double acumulador, numeroE, res;
            for (size_t i = 0; i < videos.size(); i++){
                Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);

                if (episodio && episodio->getNombre() == serieOPelicula){
                    acumulador = acumulador + stod(episodio->getCalif());
                    numeroE++;
                }
            }
            res = acumulador/numeroE; //Dividimos el total de la  suma de cantidad de episodios / el numero de episodios.
            cout << "El promedio es: " << res << "/10 " << endl << endl;

        } else if (opc == "7"){
            for (Video* video : videos) {
                delete video;
            }
            videos.clear();
            cout << "Gracias." << endl; //Salimos del Programa
        }

        if(cont == 0){
            cout << endl << "ERROR DE CARGA" << endl << "NO HA CARGADO NINGUNA BASE DE DATOS" << endl << endl;
            videos = LeerArchivo();
            cont++;
        }    
    }
    return 0;
}
