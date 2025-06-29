#include <fstream>
#include <iostream>

using namespace std;

struct Estudiante { //Adonde declararemos las variables
  int id;

  string nombre;

  int edad;
};

const int MAX_EST = 10;

Estudiante estudiantes[MAX_EST];

int total = 0;

void agregar() {
  if (total >= MAX_EST) {
    cout << "¡Capacidad llena! (max. " << MAX_EST << " estudiantes)\n"; //en caso de llenarse con maximo, mandar mensaje de error

    return;
  }

  cout << "ID: ";

  cin >> estudiantes[total].id;

  cout << "Nombre: ";

  cin >> estudiantes[total].nombre;

  cout << "Edad: ";

  cin >> estudiantes[total].edad;

  ++total;

  cout << "Agregado \n";
}

void mostrar() {
  cout << "\nESTUDIANTES\n";

  if (total == 0) {
    cout << "No hay estudiantes registrados.\n";

    return;
  }

  for (int i = 0; i < total; ++i) {
    cout << estudiantes[i].id << " - "

         << estudiantes[i].nombre << " - "

         << estudiantes[i].edad << " años\n";
  }
}

void buscar() {
  if (total == 0) {
    cout << "No hay registros para buscar.\n";

    return;
  }

  int idBuscado;

  cout << "ID a buscar: ";

  cin >> idBuscado;

  for (int i = 0; i < total; ++i) {
    if (estudiantes[i].id == idBuscado) {
      cout << "Encontrado: "

           << estudiantes[i].nombre << " - "

           << estudiantes[i].edad << " años\n";

      return;
    }
  }

  cout << "ID no encontrado.\n";
}

void guardar() {
  ofstream archivo("estudiantes.txt");

  if (!archivo) {
    cerr << "Error al abrir estudiantes.txt para escritura\n";

    return;
  }

  archivo << total << '\n';

  for (int i = 0; i < total; ++i) {
    archivo << estudiantes[i].id << ' '

            << estudiantes[i].nombre << ' '

            << estudiantes[i].edad << '\n';
  }

  archivo.close();//siempre cerrarlo para evitar erroress

  cout << "Datos guardados\n";
}

void cargar() {
  ifstream archivo("estudiantes.txt");

  if (!archivo) return;

  archivo >> total;

  if (total > MAX_EST) total = MAX_EST;

  for (int i = 0; i < total; ++i) {
    archivo >> estudiantes[i].id

        >> estudiantes[i].nombre

        >> estudiantes[i].edad;
  }

  archivo.close();
}

int main() {
  cargar();
  int op;

  do {
    cout << "\n1. Agregar  2. Mostrar  3. Buscar  4. Guardar y salir\n ";

    cin >> op;

    switch (op) {
      case 1:
        agregar();
        break;

      case 2:
        mostrar();
        break;

      case 3:
        buscar();
        break;

      case 4:
        guardar();
        cout << "Saliendo...\n";
        break;

      default:
        cout << "Opción no válida\n";
    }

  } while (op != 4);

  return 0;
}