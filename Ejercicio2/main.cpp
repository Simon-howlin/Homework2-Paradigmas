#include <iostream>
#include <memory>
#include <limits>
#include "curso.hpp"
#include "estudiante.hpp"

using namespace std;

// Función para pedir entero validado
int pedirEntero(const string& mensaje, int min, int max) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < min || valor > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor inválido. Intente de nuevo.\n";
        } else {
            return valor;
        }
    }
}

// Pausa visual
void pausa() {
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

int main() {
    Curso curso("Programación");
    int opcion;

    do {
        cout << "\n===== MENÚ CURSO: " << curso.getNombreCurso() << " =====\n";
        cout << "1. Inscribir estudiante\n";
        cout << "2. Desinscribir estudiante\n";
        cout << "3. Ver si estudiante está inscripto\n";
        cout << "4. Ver si el curso está completo\n";
        cout << "5. Listar estudiantes (ordenados alfabéticamente)\n";
        cout << "6. Copiar curso (shallow copy)\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();  // limpia ENTER

        switch (opcion) {
            case 1: {
                string nombre;
                int legajo;

                cout << "Nombre completo: ";
                getline(cin, nombre);
                legajo = pedirEntero("Legajo (único): ", 1, 99999);

                auto estudiante = make_shared<Estudiante>(nombre, legajo);
                int cantidadCursos = pedirEntero("Cantidad de cursos con nota: ", 0, 10);
                cin.ignore(); 
                for (int i = 0; i < cantidadCursos; ++i) {
                    cin.ignore();
                    string nombreCurso;
                    double nota;

                    cout << "Curso " << i+1 << ": ";
                    getline(cin, nombreCurso);
                    while (nombreCurso.empty()) {
                        cout << "El nombre del curso no puede estar vacío. Intente de nuevo: ";
                        getline(cin, nombreCurso);
                    }

                    nota = pedirEntero("Nota final (0 a 10): ", 0, 10);
                    estudiante->agregarNota(nombreCurso, nota);
                }

                bool inscripto = curso.agregarEstudiante(estudiante);
                if (inscripto) cout << "Estudiante inscripto.\n";
                pausa();
                break;
            }

            case 2: {
                int legajo = pedirEntero("Ingrese legajo del estudiante a eliminar: ", 1, 99999);
                curso.sacarEstudiante(legajo);
                pausa();
                break;
            }

            case 3: {
                int legajo = pedirEntero("Ingrese legajo: ", 1, 99999);
                if (curso.alumnoPertenece(legajo) != -1)
                    cout << "El estudiante está inscripto.\n";
                else
                    cout << "El estudiante NO está inscripto.\n";
                pausa();
                break;
            }

            case 4:
                cout << (curso.cursoCompleto() ? "El curso está completo.\n" : "Aún hay cupo.\n");
                pausa();
                break;

            case 5:
                cout << "\nLista de estudiantes:\n";
                curso.ordenarEstudiantes();
                pausa();
                break;

            case 6: {
                Curso copia = curso;  // shallow copy con shared_ptr
                cout << "Curso copiado. Listando estudiantes de la copia:\n";
                copia.listarEstudiantes(copia.getEstudiantes());
                pausa();
                break;
            }

            case 7:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción inválida.\n";
                pausa();
                break;
        }

    } while (opcion != 7);

    return 0;
}