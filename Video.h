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
        void setCalif(const string& calif);
        virtual void mostrarDatos() = 0;
        string getNombre() const;
        string getDuracion() const;
        string getEstreno() const;
        string getGenero() const;
        string getCalif() const;
        friend ostream& operator<<(ostream& output, const Video& video);
        virtual void imprimir(ostream& output) const = 0;

};
#endif