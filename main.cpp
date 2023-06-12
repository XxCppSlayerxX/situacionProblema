/**
* Autor: Jesus Guzman Ortega
*archivo main
*/

#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "FuncionesExtras.h"
#include <iostream>

using namespace std;

int main(){
    string opc = "0";
    string subopc = "0";
    string genero; 
    double calif = 0;
    vector<Video*> videos;

    while(opc != "7"){
        menu();
        cin >> opc;
        if (opc == "1"){
            videos = LeerArchivo();

        }else if(opc == "2"){
            cout << "Tecleé la opción que desee." << endl;
            cout << "1.- Calificación." << endl;
            cout << "2.- Género." << endl;
            cout << "3.- Calificación y género" << endl;

            while (true) {
                cin >> subopc;
                if(subopc == "1"){
                    calif = verificar();
                    for(int i = 0; i < videos.size();i++){
                        if(videos[i]->filtrarCalif(calif)){
                            videos[i]->mostrarDatos();
                        }
                    }
                    break;
                }else if(subopc == "2"){
                    genero = generos();
    
                    for(int i = 0; i < videos.size(); i++){
                        if(videos[i]->filtrarGen(genero)){
                            videos[i]->mostrarDatos();
                        }
                    }
                    break;
                }else if(subopc == "3"){
                    calif = verificar();
                    genero = generos();

                    for(int i = 0; i < videos.size(); i++){
                        if(videos[i]->filtrarGen(genero) && videos[i]->filtrarCalif(calif)){
                            videos[i]->mostrarDatos();
                        }
                    }
                    break;
                }else{
                    cout << "Introduzca opción válida" << endl;
                    continue;
                }
    }

        }else if (opc == "3"){
            string serie;
            cout << "Tecleé el nombre de su serie (cada palabra empezando con mayuscula, por ejemplo 'Game Of Thrones'): ";
            cin.ignore();
            getline (cin, serie);

             for(int i = 0; i < videos.size(); i++){
                Video* video = dynamic_cast<Video*>(videos[i]);
                if(Episodio* episodio = dynamic_cast<Episodio*>(video)){
                    if(episodio->esSerie(serie)){
                        episodio->mostrarDatos();
                    }
                }
            }

        }else if (opc == "4"){
            calif = verificar();
            for(int i = 0; i < videos.size(); i++){
                Video* video = dynamic_cast<Video*>(videos[i]);
                if(Pelicula* peli = dynamic_cast<Pelicula*>(video)){
                    if(peli->filtrarCalif(calif)){
                        peli->mostrarDatos();
                    }
                }
            }

        }else if (opc == "5"){  
            
        }else if (opc == "6"){

        }else if (opc == "7"){
            cout << "Gracias." << endl;
        }    
    }
    return 0;
}