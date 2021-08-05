#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include"fecha.h"

class ciclo{
private:
	int año;
	string cicloNombre;
	string periocidad;
	fecha* fechaInicio;
	fecha* fechaFinal;
public:
	ciclo(int, string, fecha*, fecha*);
	~ciclo();
	string toString();
	friend ostream& operator <<(ostream& out, const ciclo&);
	int getAnio();
	string getPeriocidad();
};

