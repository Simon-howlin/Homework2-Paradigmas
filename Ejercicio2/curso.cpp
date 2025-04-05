#include "curso.hpp"
#include "estudiante.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

// CREAR CURSO Y VER SU NOMBRE:
Curso::Curso(string nombreCurso): nombreCurso(nombreCurso){}

string Curso::getNombreCurso() {
    return nombreCurso;
}

// VER SI EL ALUMNO PERTENECE A ESE CURSO (-1 si no pertenece):
int Curso::alumnoPertenece(int legajo) {
    for (size_t i = 0; i < estudiantes.size(); i++) {
        if (estudiantes[i]->getLegajo() == legajo) {
            return i;
        }
    }

    return -1;
}

// AGREGAR / SACAR ESTUDIANTE DE UN CURSO:
void Curso::agregarEstudiante(Estudiante* e) {
    estudiantes.push_back(e);
}

void Curso::sacarEstudiante(int legajo) {
    int posEstudiante = alumnoPertenece(legajo);
    if (posEstudiante != -1) {
        delete estudiantes[posEstudiante];
        estudiantes.erase(estudiantes.begin() + posEstudiante);
        cout << "Estudiante eliminado del curso.\n";
        return;
    } else {
        cout << "Estudiante no encontrado.\n";
    }
}

// CAPACIDAD MAXIMA DE ESTUDIANTES DEL CURSO ALCANZADA:
bool Curso::cursoCompleto() {
    return estudiantes.size() == 20;
}

// PARA LA IMPRECION DE LA LISTA DE ALUMNOS ORDENADA ALFABETICAMENTE:
void Curso::ordenarEstudiantes() {
    sort(estudiantes.begin(), estudiantes.end(), [](Estudiante* a, Estudiante* b) {
        return a->getNombre() < b->getNombre();
    });
}

void Curso::listarEstudiantes() const {
    for (const auto& e : estudiantes) {
        cout << "Nombre: " << e->getNombre() << " | Legajo: " << e->getLegajo() << " | Promedio: " << e->getPromedio() << endl;
    }
}

// DEEPCOPY DE UN CURSO X, Y SU DESTRUCTOR PARA EVITAR MEMORY LEAK
Curso::Curso(const Curso& otro) {
    nombreCurso = otro.nombreCurso;

    // deep copy:
    // Por cada estudiante del curso original, creo un nuevo estudiante
    // con los mismos datos. Así el nuevo curso no comparte punteros,
    // y se puede modificar sin afectar al original.
    for (Estudiante* e : otro.estudiantes) {
        estudiantes.push_back(new Estudiante(*e));  // usa el vector del anterior curso para llenar el nuevo curso con los datos 
    }
}

Curso::~Curso() {
    // Libera todos los punteros a estudiantes
    for (Estudiante* e : estudiantes) {
        delete e;
    }
    estudiantes.clear();
}