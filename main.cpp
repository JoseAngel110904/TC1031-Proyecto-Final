#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "planetas.cpp"
#include "Lista2enlace.h"
#include "Rp.h"

using namespace std;

int main() {
string nombre,distancia,temperatura,masa; 
int opcion;
float dist,temp,mas;

ifstream p;
p.open("planetas.txt");
int i=0;
vector<planeta> v;
vector<planeta> original;
while(!p.eof()){

    getline(p,nombre);
    getline(p,distancia);
    dist =atof(distancia.c_str());
    getline(p,temperatura);
    temp =atof(temperatura.c_str());
    getline(p,masa);
    mas =atof(masa.c_str());
    v.push_back(planeta(nombre,dist,temp,mas));
    original.push_back(planeta(nombre,dist,temp,mas));

};
p.close();
// complejidad O(n) 
while(opcion!=5){
  cout<<"========MENU======="<<endl;
  cout<<"Seleccione una ocion: "<<endl;
  cout<<"1) Consultar planetas"<<endl; // Despliega la lista de los planetas
  cout<<"2) Ordenar planetas"<<endl;//Ordena por bubble sort
  cout<<"3) Consulta VIAJES ESPACIALES"<<endl; // Lista ligada
  cout<<"4) Pasajeros"<<endl; // Modificacion de base de datos
  cout<<"5) Salir"<<endl;
  cin>>opcion;
    switch (opcion){
      case 1:{
        //Complejidad O(n)
        cout<<" "<<endl;
        for(int x = 0 ; x <= v.size()-1; x++){
        original[x].disp();
        } 

        break;
    }
      //Complejidad O(n^2)
      case 2:{
        int a;
        cout<<" "<<endl;
        cout<<"Selecciona por que caracteristica los quieres ordenar"<<endl;
        cout<<"1) Por distancia en Unidades Astronomicas(UA)"<<endl;
        cout<<"2) Por temperatura promedio del planeta(°C)"<<endl;
        cout<<"3) Por masa del planeta en Tierras(1 Tierra = 5.972 × 10^24 kg)"<<endl;
        cin>>a;
        if(a==1){
            for (int i = v.size() - 1; i > 0; i--) {
              for (int j = 0; j < i; j++) {
                if (v[j].getdistancia() > v[j + 1].getdistancia()) {
                  planeta aux = v[j];
                  v[j] = v[j+1];
                  v[j+1] = aux;
                }
              }
            }
          }
        else if(a==2){
          for (int i = v.size() - 1; i > 0; i--) {
              for (int j = 0; j < i; j++) {
                if (v[j].gettemperatura() > v[j + 1].gettemperatura()) {
                  planeta aux = v[j];
                  v[j] = v[j+1];
                  v[j+1] = aux;
                }
              }
            } 
          }
        else if(a==3){
          for (int i = v.size() - 1; i > 0; i--) {
              for (int j = 0; j < i; j++) {
                if (v[j].getmasa() > v[j + 1].getmasa()) {
                  planeta aux = v[j];
                  v[j] = v[j+1];
                  v[j+1] = aux;
                }
              }
            } 
          }
        else cout<<"Opcion no valida intentelo otra vez"<< endl;
        for(int x = 0 ; x <= v.size()-1; x++){
        v[x].disp();
        } 
        break;
    }
      //Complejidad O(n)
      case 3:{
         string mision,destino,fecha,capitan,dist_mision;
         float d_m; // distancia de la mision
         DoubleLinkList Viajes;
         ifstream V_E;
         V_E.open("V_E.txt");
         while(!V_E.eof()){

           getline(V_E,mision);
           getline(V_E,destino);
           getline(V_E,fecha);
           getline(V_E,capitan);
           getline(V_E,dist_mision);
           d_m =atof(dist_mision.c_str());
           Viajes.add(mision,destino,fecha,capitan,d_m);
         };
         V_E.close();
         Viajes.muestra();
          break;
      } 

      case 4 :{
        // Complejidad 0(n)
        int caso = 0;
            string nombre, planetaDestino, ed, numPas;
            int edad, numPasajeros;
            vector<Pasajeros> registro;
            ifstream Rp;
            Rp.open("registro_pasajeros.txt");
            while (!Rp.eof()) {
                getline(Rp, nombre);
                getline(Rp, planetaDestino);
                getline(Rp, ed);
                edad = atoi(ed.c_str());
                getline(Rp, numPas);
                numPasajeros = atoi(numPas.c_str());
                registro.push_back(Pasajeros(nombre, planetaDestino, edad, numPasajeros));
            }

            Rp.close();
            RegistroPasajeros registroPasajeros;

            do {
                cout << "<==========>MENU<==========>" << endl;
                cout << "1) Registrar pasajero" << endl;
                cout << "2) Mostrar registro de pasajeros" << endl;
                cout << "3) Buscar pasajero por nombre" << endl;
                cout << "4) Eliminar pasajero por nombre" << endl;
                cout << "5) Guardar cambios" << endl;
                cout << "6) Salir" << endl;
                cout << "Elija una opción: ";
                cin >> caso;

                switch (caso) {
                    case 1: { // complejidad O(1)
                        cout << "Nombre del pasajero: ";
                        cin >> nombre;
                        cout << "Planeta destino: ";
                        cin >> planetaDestino;
                        cout << "Edad: ";
                        cin >> edad;
                        cout << "Número de pasajeros: ";
                        cin >> numPasajeros;
                        cout << " " << endl;
                        registroPasajeros.RegistroPasajero(nombre, planetaDestino, edad, numPasajeros);
                        break;
                    }

                    case 2: { // Complejidad O(n)
                        cout << " " << endl; 
                        registroPasajeros.MostrarRegistroPasajeros();
                        break;
                    }

                    case 3: {// Complejidad O(n) 
                        cout << " " << endl;
                        string name;
                        cout << "Ingrese el nombre del pasajero a buscar: ";
                        cin.ignore();
                        getline(cin, name);
                        registroPasajeros.BuscarPasajero(name);
                        break;
                    }

                    case 4: { // Complejidad O(n)
                        cout << " " << endl;
                        string victima;
                        cout << "Ingrese el nombre del pasajero a eliminar: ";
                        cin.ignore();
                        getline(cin, victima);
                        registroPasajeros.BorrarPasajero(victima);
                        break;
                    }

                    case 5: { // complejidad O(n)
                        cout << " " << endl;
                        registroPasajeros.database();
                        break;
                    }

                    case 6: {
                      //Complejidad O(1)
                        cout << " " << endl;
                        cout << "Saliendo del programa" << endl;
                        break;
                    }

                    default:
                        cout << " " << endl;
                        cout << "Opcion no valida intente nuevamente" << endl;
                        cin.clear();
                        cin.ignore();
                }
            } while (caso != 6);

          return 0;
    }
    case 5:{
      //Complejidad O(1)
      cout << "Saliendo del programa"<< endl;
      break;
    }

    default: {
      //Complejidad O(1)
      cout<<"Opcion no valida intente nuevamente"<<endl;
      cin.clear();
      cin.ignore();
  }

}
}
};