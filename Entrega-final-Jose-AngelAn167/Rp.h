#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> // Necesario para atof
#include <algorithm>

using namespace std;

class Pasajeros {
public:
    string nombre;
    string planetaDestino;
    int edad;
    int numPasajeros;

    Pasajeros(string _nombre, string _planetaDestino, int _edad, int _numPasajeros)
        : nombre(_nombre), planetaDestino(_planetaDestino), edad(_edad), numPasajeros(_numPasajeros) {}
};

class RegistroPasajeros {
private:
    vector<Pasajeros> registro;

public:
// complejidad O(1)
    void RegistroPasajero(string _nombre, string _planetaDestino, int _edad, int _numPasajeros) {
        Pasajeros nuevoPasajero(_nombre, _planetaDestino, _edad, _numPasajeros);
        registro.push_back(nuevoPasajero);
    }

    //Complejidad O(n)
    void MostrarRegistroPasajeros() const {
        for (const auto &pasajero : registro) {
            cout << "Nombre: " << pasajero.nombre << endl;
            cout << "Planeta Destino: " << pasajero.planetaDestino << endl;
            cout << "Edad: " << pasajero.edad << endl;
            cout << "Número de pasajeros: " << pasajero.numPasajeros << endl;
            cout << endl;
        }

        if (registro.empty()) {
            cout << "No hay registro de pasajeros." << endl;
        }
    }
// Complejidad O(n) por el ciclo
    void BuscarPasajero(string name) const {
        auto it = find_if(registro.begin(), registro.end(), [name](const Pasajeros &p) {
            return p.nombre == name;
        });

        if (it != registro.end()) {
            cout << "Pasajero encontrado:" << endl;
            cout << "Nombre: " << it->nombre << endl;
            cout << "Planeta Destino: " << it->planetaDestino << endl;
            cout << "Edad: " << it->edad << endl;
            cout << "Número de pasajeros: " << it->numPasajeros << endl;
            cout << endl;
        } else {
            cout << "| No se encontro pasajero " << name << "|" << endl;
        }
    }
// Complejidad O(n) por el ciclo
    void BorrarPasajero(string name) {
        auto it = remove_if(registro.begin(), registro.end(), [name](const Pasajeros &p) {
            return p.nombre == name;
        });

        if (it != registro.end()) {
            registro.erase(it, registro.end());
            cout << "Pasajero " << name << " eliminado correctamente." << endl;
        } else {
            cout << "| No se encontro pasajero " << name << "|" << endl;
        }
    }
//Complejidad O(n)
    void database() const {
        ofstream archivo("registro_pasajeros.txt", ios::trunc);

        if (archivo.is_open()) {
            for (const auto &pasajero : registro) {
                archivo << pasajero.nombre << endl;
                archivo << pasajero.planetaDestino << endl;
                archivo << pasajero.edad << endl;
                archivo << pasajero.numPasajeros << endl;
                archivo << endl;
            }

            archivo.close();
            cout << "La base de datos ha sido actualizada correctamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo para escribir." << endl;
        }
    }
};