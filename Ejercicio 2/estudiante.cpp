#include "estudiante.hpp"
#include <iostream>

using namespace std;

// CREAR ESTUDIANTE:
Estudiante::Estudiante(string nombre, int legajo): nombreCompleto(nombre), legajo(legajo) {}

// GET NOMBRE / LEGAJO DEL ESTUDIANTE:
string Estudiante::getNombre() const {
    return nombreCompleto;
}

int Estudiante::getLegajo() const {
    return legajo;
}

// MANEJO DE NOTAS Y PROMEDIOS DEL ESTUDIANTE
void Estudiante::agregarNota(string curso, float nota) {
    // Si el curso ya existe, actualizo la nota
    for (auto& par : cursosYNotas) {
        if (par.first == curso) {
            par.second = nota;
            return;
        }
    }
    // Si no existe, lo agrego
    cursosYNotas.push_back(make_pair(curso, nota));
}

float Estudiante::getPromedio() const {
    if (cursosYNotas.empty()) return 0.0f;

    float suma = 0;
    for (const auto& par : cursosYNotas) {
        suma += par.second;
    }
    return suma / cursosYNotas.size();
}