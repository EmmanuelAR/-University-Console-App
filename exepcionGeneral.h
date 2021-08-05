#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include"usuarios.h"
#include"estudiante.h"
#include"profesor.h"

class exepcionRango { //clase padre 
private:
	int minimo;
	int maximo;
protected:
	exepcionRango(int, int);
	virtual void setValor(int) = 0; //metodo virtual puro 
public:
	virtual string toString() const;
};

class exepcionRangoInferior : public exepcionRango { //clase hija
private:
	int valor;
public:
	exepcionRangoInferior(int, int, int);
	virtual string toString() const;
	void setValor(int);
};

class exepcionRangoSuperior : public exepcionRango { //clase hija 
private:
	int valor;
public:
	exepcionRangoSuperior(int, int, int);
	virtual string toString() const;
	void setValor(int);
};

class exepcionValor {
public:
	virtual string toString() const;
	int validar(int, int);
	int obtenerValor(int,int);
	string validarContra1();
	string validarTamContra();
	bool Mayusculas(string);
};

class exepcionCambioTipo {
public:
	static estudiante* cambiarEstudiante(usuario*);
	static profesor* cambiarProfesor(usuario*);
};



