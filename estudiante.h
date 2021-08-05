#pragma once
#include"usuarios.h"
#include"carrera.h"
#include"grupo.h"
#include"listaGenerica.h"
#include"historialAcademico.h"
class carrera;
class historialAcademico;
class grupo;




class estudiante : public usuario {
public:
	estudiante(string, string, string, string,int);
	~estudiante();
	friend ostream& operator <<(ostream& out, const estudiante&); //sobrecarga para el metodo imprimir
	

	void setProfesion(carrera*);
	carrera* getProfesion();
	int getTelefono();
	//
	void agregarGrupoAlBloque(grupo* a);
	string retornarGruposEspecificos(int año, string periocidad);
	grupo* recuperarGrupoPro(int);
	//metodos cursoMatriculados
	void agregarCursoMatricula(curso* a);
	string mostrarListadoCursoMatriculados();

	historialAcademico* getHistorial();

	lista<curso>* getTodosCursosMatriculados();





	//metodos matricula
	bool verificarGrupoYaMatriculado(string _nrc);

private:
	carrera* profescion;
	int telefono;



	lista<grupo>* bloque; //grupos que esta llevando
	lista<curso>* cursosMatriculados;




	historialAcademico* historialNotas; //aprobados y reprobados

};

