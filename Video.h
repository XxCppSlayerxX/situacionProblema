#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <vector>

using namespace std;

class Video {
    protected:
        vector<string> datos; // Vector que almacena los datos del video

    public:
        Video();// Constructor por defecto
        Video(vector<string> datos);        // Constructor que recibe los datos del video
        bool filtrarCalif(double calif); // Función para filtrar por calificación
        bool filtrarGen(string genero); // Función para filtrar por género
        void setCalif(const string& calif); // Establece la calificación del video
        virtual void mostrarDatos() = 0; // Función virtual pura para mostrar los datos del video
        string getNombre() const;// Obtiene el nombre del video
        string getDuracion() const; // Obtiene la duración del video
        string getEstreno() const; // Obtiene el año de estreno del video
        string getGenero() const; // Obtiene el género del video
        string getCalif() const; // Obtiene la calificación del video
        friend ostream& operator<<(ostream& output, const Video& video); // Sobrecarga del operador de inserción para imprimir el video
        void imprimir(ostream& output) const; // Función virtual pura para imprimir el video en un flujo de salida

};

#endif
