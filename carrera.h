#pragma once
#include<iostream>
#include<sstream>
using namespace std;
//
#include"listaGenerica.h"
#include"estudiante.h"
#include"profesor.h"
#include"curso.h"
#include"grupo.h"

class grupo;
class estudiante;
class profesor;
class curso;

class carrera{
private:
	string codigoCarre;
	string nombreCarre;
	string grado;
	string facultad;
	string estado;
	//
	lista<estudiante>* listaEstudiantesDeCarrera; //estudiantes empadronados 
	lista<profesor>*listaProfesoresDeCarrera;	//profesores de la carrera
	lista<curso>* planDeEstudios;
	lista<grupo>* listaGruposMatricula;
	//
public:
	carrera(string, string, string, string);
	~carrera();
	string toString();
	string getCodigoCarrera();
	string getNombreCarrera();
	//
	bool operator == (string&);
	friend ostream& operator <<(ostream& out, const carrera&);
	// Metodos de las listas asociadas
	// estudiantes empadronados
	void agregarEstudinatesPro(estudiante* a);
	string mostrarEstudiantesEmpadronados();
	estudiante* recuperarEstuadintePro(int);
	// profesores de la carrera
	void agregarProfesorPro(profesor*);
	string mostrarProfesores();
	profesor* recuperarProfesorPro(int);
	// plan de estudios 
	void agregarCursoPlan(curso*);
	string mostrarPlanEstudios();
	curso* recuperarCursoPro(int);
	string mostrarPlanEstudiosEspecial();
	// lista grupos matricula
	void agregarGrupoMatricula(grupo*);
	string mostrarGruposMatricula();
	grupo* recuperarGrupoPro(int);





	//retornar listas
	lista<curso>* getTodosCursos();
	lista<profesor>* getTodosProfesores();
	lista<grupo>* getTodosgrupo();
	lista<estudiante>* getTodosEstudiantes();
	//
	string retornarCursoEspecificos(int año,string periocidad);

	string retornarGruposEspecificos(int año, string periocidad);
	
};

