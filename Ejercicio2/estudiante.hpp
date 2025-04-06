#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP

#include <string>
#include <iostream>
#include <vector>
#include <utility> // para pair

using namespace std;

class Curso;
class Estudiante {
private:
    string nombreCompleto;
    int legajo;
    vector<pair<string, float>> cursosYNotas;

public:
    Estudiante(string nombre, int legajo);

    string getNombre() const;
    int getLegajo() const;
    void agregarNota(string curso, float nota);
    float getPromedio() const;
};

#endif