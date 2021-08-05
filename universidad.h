#pragma once
#include<iostream>
#include<sstream>
using namespace std;

#include"listaGenerica.h"
#include"usuarios.h"
#include "estudiante.h"
#include "escuela.h"
#include "ciclo.h"
#include "curso.h"
class curso;
class usuario;
class estudiante;
class escuela;
class ciclo;

class universidad{
public:
	universidad();
	~universidad();
	//metodos de las listas
	//agregar
	void agregarUsuariosPro(usuario*);
	void agregarEscuelaPro(escuela*);
	void agregarEstudiantesGeneral(estudiante*);
	void agregarProfesorGeneral(profesor*);
	void agregarCursoMalla(curso*);
	void agregarCiclo(ciclo*);
	//recuperar
	usuario* recuperarUsuarioPosicion(int);
	escuela* recuperarEscuelaPosicion(int);
	estudiante* recuperarEstudiantePosicion(int);
	profesor* recuperarProfesorPosicion(int);
	ciclo* recuperarCicloPosicion(int);
	curso* recuperarCursoDeMallaPosicion(int);

	//mostrar
	string mostrarUsuarios();
	string mostarEscuelas();
	string mostarEstudiantesGeneral();
	string mostarProfesoresGeneral();
	string mostarMalla();
	string mostrarCiclos();
	//cant
	int getCantUsuario();
	int getCantEscuelas();
	int getCantCiclos();
	//retorno lista
	lista<usuario>* getTodosUsuarios();
	lista<escuela>* getTodasEscuelas();
	// buscar
	usuario* buscarUsuarioEspecifico(string, string);
	ciclo* buscarCicloEspecifico(string, int);
	

private:

	lista<usuario>*  TodosUsuarios;
	lista<escuela>* escuelasGeneral;

	lista<estudiante>* estudiantesGeneral;
	lista<profesor>* profesorGeneral;
	lista<curso>* mallaCurricular;


	lista<ciclo>* ciclosUniversidad;


};
