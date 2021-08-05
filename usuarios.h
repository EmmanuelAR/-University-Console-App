#pragma once
#include<iostream>
#include<sstream>
using namespace std;

class usuario { //clase padre
protected:
	string idUsu;
	string nombreUsu;
	string claveUsu;
	string rolUsu;
	string estadoUsu;
	int identificador;
public:
	usuario(string, string, string, string);
	~usuario();
	virtual string toStringGeneral();
	string  getidUsu();
	string getnombreUsu();
	string getclaveUsu();
	string getrolUsu();
	string getestadoUsu();
	int getIndentificador();
	//
	friend ostream& operator <<(ostream& out, const usuario&); //sobrecarga para el metodo imprimir
	bool operator == (string&);

};
