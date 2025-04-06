# Home work 2

## ¿De que tratan los ejercicios?

- ejercicio 1: Usar clases con sus dichos constructores e implementaciones extras para crear un reloj. (Permite: crear reloj con constructores, set individual, get individdual, reloj 12hs a.m. / p.m., reloj 24hs). Tambien tiene una terminal para poder interactuar con el usuario, permitiendole elegir que hacer.

- ejercicio 2: se crea una clase estudiante y otra curso, permite agregar y sacar alumnos a un curso y poner su nota, tambien ver si un alumno pertenece a ese curso, imprimir la lista de los alumnos de clase en orden alfabetico y copiar la clase con un shallow copy. (extra. podria haber agregado para pedir el promedio individual dado un alumno, pero si se imprime el curso aparece el promedio de cada alumno.)

    relacion entre curso y estudiante: La relación entre las clases Curso y Estudiante es una asociación debil (podria decirce unidireccional). Esto representa una relación de agregación, ya que los estudiantes pueden existir independientemente de los cursos y pueden estar compartidos por múltiples cursos. Curso no es dueño exclusivo de los objetos Estudiante.

    conclucion ej2: En principio habia decidido hacer un deep copy, porque es mas intuitivo y me parecia mejor por si se borra alguna clase, despues me di cuenta que si uso shared_ptr en conjunto con el shallow copy podria ser mejor, mas rapido y sin tener que preocuparme por liberar mal memoria. Tambien me di cuenta que si cambiaba algo en la clase que fue copiada, iba a tener que modificar tambien a la copia.

- ejercicio 3: usar clases virtuales (abstractas puras), se hacen cuentas como (+, -, *) en 3 tipos de numeros (enteros, reales, imaginarios).

- ejercicio 4: se utiliza una clase virtual que es el banco, y de esa derivan 2 clases hijas (cuenta corriente, caja de ahorro). Tiene un main que permite al usuario crear la cuenta de banco con tu nombre y monto inicial, luego seleccionas que tipo de cuenta queres usar, corriente o de ahorro. Dentro de estas 2 opciones podes elegir si queres retirar, depositar, y la opcion info que te dice que tipo de cuenta es, el nombre del usuario, y la cantidad de dinero que hay en esa cuenta.

    conclucion ej4: Eleji en la clase padre usar protected para que las clases hijas puedan utilizar y acceder al balance y al nombre del titular de la cuenta. (extra. en la clase caja de ahorro, se define a cuenta corriente como friend class. Esto tambien se podria haber hecho una funcion en el public de la caja de ahorro para no tener que acceder directamente, haciendolo mas seguro.)

## Cómo compilar los ejercicos:

- se utiliza el comando "make" en terminal, esto compila los 4 ejercicios de cada carpeta y los guarda en la carpeta bin.

## Como ejecutarlos:
- ./bin/ejN (siendo N el numero de ejercicio) N ∈ {1,2,3,4}