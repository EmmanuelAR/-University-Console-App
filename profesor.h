#pragma once
#include"usuarios.h"
#include"listaGenerica.h"
#include"curso.h"
#include "grupo.h"

class grupo;
class profesor : public usuario {
private:
	int telefono;
	string gradoAcademico;
	lista<grupo>* gruposAsiginados;


public:
	profesor(string, string, string, string,int,string);
	~profesor();
	int getCelular();
	string getGradoAcademico();


	//virtual string toStringPersonal();
	friend ostream& operator <<(ostream& out, const profesor&); //sobrecarga para el metodo imprimir
	//metodos de la lista
	void agregarGruposPro(grupo* a);
	string mostrarGruposAsignados();
	grupo* recuperarGrupoPosicion(int);
	//
	bool validarCreacionGrupo(string);

	string mostrarGruposEspecificos(int año, string periocidad);

	lista<grupo>* getTodosGruposAsigandos();

};


