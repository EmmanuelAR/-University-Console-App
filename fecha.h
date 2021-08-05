#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class fecha
{
private:
	int annio;
	int mes;
	int dia;
public:
	fecha(int, int, int);
	~fecha();
	friend ostream& operator <<(ostream& out, const fecha&);
	static int comparaFecha(fecha*, fecha*);
	int getDia();
	int getMes();
	int getAnnio();
};

