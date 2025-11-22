#include <vector>
#include <list>
#include <unordered_map>
#include <cstdlib> // Para rand() and srand()
#include <ctime> // Para time(); esas funciones se usarán para un generador aleatorio.

using namespace std;
srand(time(0));

struct Tarea{
    enum Estados = {PENDIENTE, EN_PROGRESO, COMPLETADO};
    string titulo;
    vector<string> etiquetas;
    unordered_map<string, string> propiedades;
    Estados estadoActual;
};

struct semiTarea{ // Estructura designada para entradas de usuario.
    string titulo;
    vector<string> etiquetas;
    unordered_map<string, string> propiedades;
};

class Registrador(){
private:
    unordered_map<int, Tarea> listaTareas;
    // Para facilitar la búsqueda de tareas (y el resto de sus propiedades) según su ID.

    int GeneradorID(){
        do{
            int nuevoID = rand() % 1000; // Para el ID, se necesita un número entre 0 y 999.
        }while(listaTareas.find(nuevoID) != listaTareas.end()); // Verificar que ninguna tarea registrada tenga el ID que se acaba de obtener.
        return nuevoID;
    }

    listaTareas(){
        listaTareas = {};
    }

    void setTarea(const int& ID, const string& title, const vector<string>& labels, const unordered_map<string, string>& props, Tarea::Estados state){
        // Esta función se usará para crear y actualizar tareas.
        // Se usa `&` para indicar que no se copien los parámetros, se apunta a ellos.
        // Y `const` se usa para que no se modifiquen.
        Tarea tareaSujeto = listaTareas[ID];
        tareaSujeto.titulo = title;
        tareaSujeto.etiquetas = labels;
        tareaSujeto.estadoActual = state;
    }

    struct entradaSet(){ // Designado para recibir entradas para crear y actualizar tareas (excepto su estado).
        semiTarea sTask;
        cin.ignore(100, '\n'); // En caso de que la última entrada recibida se haya hecho con `cin >>`
        cout << "Nombre de tarea: ";
        getline(cin >> ws, sTask.title); // Para deshacerse de espacios en blanco posteriores.

        cout << "=== Tareas ===\n+ Inserta las etiquetas que tendrá\n+ Deja la entrada en blanco para terminar." << endl;
        // TO DO: implementar funcionalidad de autocompletado.


        return sTask;
    }

public:
    void crearTarea(){
        cout << "=== Nueva Tarea ===" << endl;
    }

    void cambiarEstadoTarea(){
    }
};
