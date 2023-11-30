#include <iostream>
using namespace std;
class nodo{
private:
  string Mision_name;
  string Destino;
  string Fecha;
  string Capitan;
  float Distancia;

public:
nodo * anterior;
nodo * siguiente;

nodo(string M_N,string _Dest, string _Date,string _Cap, float _Dist){
  Mision_name = M_N;
  Destino = _Dest;
  Fecha = _Date;
  Capitan = _Cap;
  Distancia = _Dist;
}
//Complejidad O(1)
  void disp(){
    cout<<" "<<endl;
    cout<<"~~~~~~"<<Mision_name<<"~~~~~~"<<endl;
    cout<<"Destino : "<<Destino<<endl;
    cout<<"Fecha en la que se realizo: "<<Fecha<<endl;
    cout<<"Capitan : "<<Mision_name<<endl;
    cout<<"Distancia recorrida en U.A : "<<Distancia<<endl;
  }
};

class DoubleLinkList{
private:
  nodo * head;
  nodo * tail;

public:

  DoubleLinkList(): head(NULL),tail(NULL) {}
//Complejidad O(1)
  void add(string M_N,string _Dest, string _Date,string _Cap, float _Dist) {
    nodo * Nnodo = new nodo (M_N, _Dest,  _Date, _Cap, _Dist);
    if (tail == NULL){
      head = Nnodo;
      tail = Nnodo;
    } else {
      Nnodo->anterior = tail;
      tail->siguiente = Nnodo;
      tail = Nnodo;
    }
  }

#define SALIR 3
  void muestra() {
    //complejidad O(n)
    nodo * nodoActual = head;
    int opcion = -1;
    while(opcion != SALIR){
        nodoActual->disp();
        cout << "Escoje una opcion: " << endl;
        cout << "Siguiente(1) / Anterior(2) / Salir(3)" << endl;
        cin >> opcion;
       if(opcion == 1) {
         nodoActual = nodoActual->siguiente;
       } else if(opcion == 2) {
         nodoActual = nodoActual->anterior;
       } else {
         opcion = SALIR;
       }
    }
  }
};

