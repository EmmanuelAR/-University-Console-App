#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include"listaGenerica.h"
#include"grupo.h"
#include"carrera.h"
#include"ciclo.h"
class carrera;
class grupo;
class curso{
private:
	string codigoCurso;
	string nombreCurso;
	string tipoCurso;
	int creditos;
	int horasLectivas;
	string estado;
	int notaFinal;
	bool resuladoFinal;
	//
	carrera* carreraAsociada;
	ciclo* cicloElectivo;
	lista<curso>* requisitos;
	lista<grupo>* grupos;

public:
	curso( string, string, int, int, string, ciclo*,carrera*);
	string getCodigoCurso();
	string getNombreCurso();
	string getTipo();
	int getCreditos();
	int getHoras();
	string getEstado();
	void setCarreraAsociada(carrera*);
	void setCodigo();
	carrera* getCarreraAsociada();
	ciclo* getCicloAsociado();
	~curso();
	string toString();
	friend ostream& operator <<(ostream& out, const curso&); //sobrecarga para el metodo imprimir
	//Metodos de las lista
	void agregarRequistosPro(curso* a);
	string mostrarRequisitosAsignados();
	curso* recuperarRequisitoPro(int);
	//
	void agregaGrupoPro(grupo* a);
	string mostrarGruposAsignados();
	grupo* recuperarGrupoPro(int);
	//tostring especiales
	string mostarRequisitos();
	string cursoConRequisitos();
	// retornar listas
	lista<grupo>* todosGrupos();
	//
	bool operator == (string&);
	//
	int getCantGrupos();
	//
	void setResultadoFinal(bool);
	bool getResultadoFinal();
	void setNotaFinal(int nota);

	//
	lista<curso>* getTodosRequisitos();
	int getNota();

	void setCodigoCopia(string codigo);
	

};

