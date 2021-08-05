#include "controladora.h"
controladora::controladora() {
	uni = new universidad();
	verificarListaUsuario();
}
controladora::~controladora() {

}

void controladora::control1() {
	int opcionPricipal;

	do {
		opcionPricipal = control2();

		switch (opcionPricipal) {
		case 1: {

			int opcion2;
			do {
				opcion2 = control3();
				switch (opcion2) {
			case 1: {

				agregarCualquierUsuario();

			}
				  break;
			case 2: {
				mostrarTodosUsuarios();
			}
				  break;
			};
		} while (opcion2 != 3);

		}
			  break;
		case 2: {
			int opcion3;
			do {
				opcion3 = control4();
				switch (opcion3) {
				case 1: {

				}
					  break;
				case 2: {

				}
					  break;
				case 3: {

				}
					  break;
				};
			} while (opcion3 != 4);
		}
			  break;
		case 3: {


		}
			  break;
		case 4: {

		}
			  break;
		case 5: {

		}
			  break;
		case 6: {
		

		}
			  break;

		};


	} while (opcionPricipal != 6);






}

int controladora::control2() {
	int opcion;
	opcion = vista::menuPrincipal();
	return opcion;
}



int controladora::control3() {
	int opcion;
	opcion = vista::subMenu1();
	return opcion;
}

int controladora::control4() {
	int opcion;
	opcion = vista::subMenu2();
	return opcion;
}

void controladora::controlAdminInicial() {
	usuario* a;
	a = vista::crearAdminInicial();
	uni->agregarUsuariosPro(a);
	control1();
}

void controladora::verificarListaUsuario() {
	int n;
	n = uni->getCantUsuario();
	if (n == 0) {
		controlAdminInicial();
	}
	else {
		controLogearse();
	}
}

void controladora::controLogearse()
{
	usuario* a;
	a = vista::logearse(uni->getTodosUsuarios());
	if (a) {
		control1();
	}
	else {
		exit(0);
	}
}

void controladora::agregarCualquierUsuario() {
	usuario* a;
	a = vista::crearUsuario();
	if (a) {
		uni->agregarUsuariosPro(a);
	}
}

void controladora::mostrarTodosUsuarios() {
	cout<<uni->mostrarUsuarios();
	Sleep(1000);
}