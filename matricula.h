#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include <Windows.h>
#include "universidad.h"
#include"estudiante.h"
#include"carrera.h"
#include"ciclo.h"
#include"curso.h"
class curso;
class ciclo;
class carrera;
class universidad;
class estudiante;

class matricula
{
public:

	static void matricularEstudiante(universidad * uni,estudiante * estudianteAux);
	static void consultaGeneralMatricula(universidad* uni,estudiante* estudianteAux);
	static void historialAcademicoEstudiante( estudiante* estudianteAux);
};

