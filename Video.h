/**
* Autor: Jesus Guzman Ortega
*Definir Clase video
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>
using namespace std;

class Video{
    protected:
    vector<string> datos; 

    public:
        Video();
        Video(vector<string> datos);
        bool filtrarCalif(double calif);
        bool filtrarGen(string genero);
        virtual void mostrarDatos() = 0;

};
#endif