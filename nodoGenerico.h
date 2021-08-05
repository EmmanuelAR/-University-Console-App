#pragma once
template<class T>
class nodo {
public:
	nodo( T*, nodo<T>*);
	 virtual ~nodo();
	 //
	void setSiguiente(nodo<T>*);
	void setObjt(T*);
	//
	nodo<T>* getSiguiente() ;
	T* getDato() ; //devuelve el obje del nodo
private:
	T* dato; //puntero a un objeto dinamico
	nodo<T>* siguiente; //enlace hacia el otro posible nodo

};
//DEFINCION DE LOS METODOS DE LA CLASE NODO

template <class T>
nodo<T>::nodo( T* d, nodo<T>* sig) : dato((T*)d), siguiente(sig) {
}

template <class T>
nodo<T>::~nodo(){
	delete dato;
}

template <class T>
T* nodo<T>::getDato()  {
	return dato;
}

template <class T>
nodo<T>* nodo<T>::getSiguiente()  {
	return siguiente;
}

template <class T>
void nodo<T>::setSiguiente(nodo<T>* s) {
	siguiente = s;
}

template <class T>
void nodo<T>::setObjt(T* a) {
	dato = a;
}