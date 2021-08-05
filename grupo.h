#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include"profesor.h"
#include"listaGenerica.h"
#include"estudiante.h"
#include"curso.h"
class profesor;
class curso;
class estudiante;

class grupo {
private:
	string  ncr;
	int numeroGrupo;
	//
	profesor* profe;
	curso* cursoAsociado;
	//
	int cupoDisponible;
	string dias;
	string horaIncio;
	string horaFinal;
	string horario;
	// no se recibe
	int cupoOcupado;
	//listas asociadas
	lista<estudiante>* estudiantesMatriculados;
public:
	grupo(  int, string, string, string,curso*);
	~grupo();
	string toString();
	friend ostream& operator <<(ostream& out, const grupo&); //sobrecarga para el metodo imprimir
	bool operator == (string&);
	//
	void setCurso(curso*);
	string getCursoCodigo();
	string getNombreCurso();
	curso* getCursoAsociado();
	//
	void setProfesor(profesor*);
	string getNombreProfesor();
	profesor* getProfesor();
	//metodos de la lista
	void matricularEstuadinte(estudiante* a);
	string mostrarListadoEstudiantes();
	estudiante* recuperarEstudiantePro(int);
	//
	void setHorario(string);
	string getHorario();
	//
	void setNRC();
	string getNrc();
	//
	void setNumeroGrupo();
	//retorna listas
	lista<estudiante>* todosEstudiantes();
	//
	int getNumeroGrupo();
	int getCupo();
	int getCantidad();



};

