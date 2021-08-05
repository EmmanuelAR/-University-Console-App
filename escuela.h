#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include"listaGenerica.h"
#include"carrera.h"

class escuela{
private:
	string nombre;
	lista<carrera>* listaCarrerasDeEscuela;

public:
	escuela(string);
	~escuela();
	string toString();
	string getNombreEscuela();
	//
	friend ostream& operator <<(ostream& out, const escuela&);
	//
	void agregarCarrerasPro(carrera*);
	string mostrarCarreras();
	carrera* recuperarCarreraPro(int);
	//
	int getCantCarreras();
	//retorna listas
	lista<carrera>* getTodasCarrerasEscuela();
};

