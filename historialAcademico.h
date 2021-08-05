#pragma once
#include"estudiante.h"
#include"curso.h"

class curso;
class estudiante;

class historialAcademico{
	public:
	historialAcademico(estudiante* e);
	~historialAcademico();
	//metodos de la lista
	void agregarCursoAprobado(curso*);
	//
	curso* recuperarCursoAprobado(int);
	//
	string mostrarCursosAprobados();
	//
	lista<curso>* getTodosCursoAprobados();
	//
	curso* buscarCursoEspecifico(string codigo);
	//
	bool verificarMatriculado(string nombreCurso);
	//
	bool verificarRequisitos(lista<curso>* requisitos);

	lista<curso>* cursosAprobados();
	//
	string hitorialEspecial();



	private:
	estudiante* e;
	lista<curso>* listaCursos;
	
};

