
#include "planetas.h"

planeta::planeta(){
  nombre = "NA";
  distancia_UA = 0;
  temperatura_C = 0;
  masa_Tierras = 0;
}

planeta::planeta(std::string _n,float _d,float _t,float _m){
  nombre = _n;
  distancia_UA = _d;
  temperatura_C = _t;
  masa_Tierras = _m;
}
// complejidad O(1)
std::string planeta::getnombre(){ return nombre;}
float planeta::getdistancia(){ return distancia_UA;}
float planeta::gettemperatura(){ return temperatura_C;}
float planeta::getmasa(){return masa_Tierras;}

void planeta::disp(){
std::cout<<"========="<<nombre<<"=========="<<std::endl;
std::cout<<"Distancia en UA del planeta: "<<distancia_UA<<std::endl;
std::cout<<"Temperatura del planeta: "<<temperatura_C<<std::endl;
std::cout<<"Masa en Tierras del planeta: "<<masa_Tierras<<std::endl;
}