#pragma once
#include"universidad.h"
#include"vista.h"


class controladora
{
private:
	universidad* uni;
public:
	controladora();
	~controladora();
	void control1();
	//
	void controlAdminInicial();
	void verificarListaUsuario();
	void controLogearse();
	//
	void agregarCualquierUsuario();
	void mostrarTodosUsuarios();
	//
	int control2();
	int control3();
	int control4();
};

