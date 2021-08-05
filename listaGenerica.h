#pragma once
#include <iostream>
#include<sstream>
using namespace std;
#include"nodoGenerico.h"


template<class T>
class lista {
public:
	lista();
	virtual ~lista();
	//
	bool agregarObj(T*); //INGRESA DE PRIMERO
	void ingresarDeUltimo(T*); //INGRESA DE ULTIMO
	//
	string toStringLista();
	//
	T* recuperarElementoPorLugar(int lugar);
	T* buscarPorString(string);
	T* getDato();
	//
	void iniciarlizarActual();
	void siguienteNodo();
	int getCant();
	//
	

private:
	nodo<T>* primero;
	nodo<T>* actual;
	int cant;


};

//definicion de los metodos de la lista generica 

template<class T>
lista<T>::lista() :primero(NULL), actual(NULL),cant(0)  {

}

template<class T>
bool lista<T>::agregarObj(T* obj) {
	primero = new nodo<T>(obj, primero); //ingresa de primero
	cant++;
	return true;
}

template<class T>
void lista<T>::ingresarDeUltimo(T* a) {
	 actual = primero;
	if (actual == NULL) {
		agregarObj(a);
	}
	else {
		nodo<T>* nuevo = new nodo(a, NULL);
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}





template<class T>

lista<T>::~lista() {
	nodo<T>* p = primero;
	nodo<T>* aux;
	while (p != NULL) {
		aux = p->getSiguiente();
		delete p;
		p = aux;
	}
	primero = NULL;
}


template <class T>
string lista<T>::toStringLista() {

	actual = primero;
	int contador = 1;
	
	stringstream s;
	if (actual == NULL) {
		s << "NO HAY ELEMENTOS EN LA LISTA..." << endl;
	}
	else {
		while (actual != NULL) {
			s <<"NO. "<<contador<<'\t'<<(*actual->getDato()) << endl; //se tiene que sobrecargar el <<
			actual = actual->getSiguiente();
			contador++;
		}
	}
	return s.str();

}


template <class T>
T* lista<T>::recuperarElementoPorLugar(int lugar) {
	int contador = 1;
	 actual = primero;
	while (actual != NULL && contador < lugar) {
		actual = actual->getSiguiente();
		contador++;
	}
	if (contador == lugar) {
		return actual->getDato();
	}
	return NULL; // si no lo encontro 
}



template<class T>
T* lista<T>::buscarPorString(string a) {
	T* dato = NULL;
	actual = primero;
	while (actual != NULL) {
		dato = actual->getDato();
		if (*dato == a) {
			return dato;
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}




template <class T>
void lista<T>::iniciarlizarActual() {
	actual = primero;
}


template <class T>
void lista<T>::siguienteNodo() {
	actual = actual->getSiguiente();
}


template <class T>
int lista<T>::getCant() { return cant; }


template <class T>
T* lista<T>::getDato() {
	 T* a = actual->getDato();
	 return a;
}