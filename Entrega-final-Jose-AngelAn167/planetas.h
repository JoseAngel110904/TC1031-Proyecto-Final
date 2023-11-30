#include <string>
#include<iostream>

class planeta{
public:
std::string nombre;
float distancia_UA;
float temperatura_C;
float masa_Tierras;


planeta();
planeta(std::string _n,float _d,float _t,float _m);

std::string getnombre();
float getdistancia();
float gettemperatura();
float getmasa();

void disp();

};
