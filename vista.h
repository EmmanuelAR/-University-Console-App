#pragma once
#include<iostream>
#include<sstream>
using namespace std;
#include"exepcionGeneral.h"
#include"usuarios.h"
#include"administrativos.h"
#include"profesor.h"
#include"estudiante.h"
#include"registro.h"
#include"listaGenerica.h"


#include <Windows.h>

class vista
{
public:
	static  int menuPrincipal();
	static int subMenu1();
	static int subMenu2();
	//
	static usuario* crearAdminInicial();
	static usuario* logearse(lista<usuario>* a);
	//
	static usuario* crearUsuario();


	
};

