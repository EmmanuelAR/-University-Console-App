#include "vista.h"

int vista::menuPrincipal() {
	int opcionPricipal;
	system("cls");
	cout << "--------Universidad Nacional De Costa Rica-----" << endl << endl;
	cout << "----------------Menu Pricipal------------------" << endl << endl;
	cout << "\t" << "1- Seguridad y admnistracion de roles" << endl;
	cout << "\t" << "2- Mantenimiento General a Nivel de Registro" << endl;
	cout << "\t" << "3- Mantenimiento por Escuelas " << endl;
	cout << "\t" << "4- Matricula e historiales " << endl;
	cout << "\t" << "5- Registro de actas" << endl;
	cout << "\t" << "6- Salir  " << endl << endl;
	exepcionValor e;
	opcionPricipal = e.validar(1,6);
	return opcionPricipal;
  }


int vista::subMenu1() {
	int opcion2;
	system("cls");
	cout << '\t' << "1- Crear Usuario " << endl;
	cout << '\t' << "2- Mostrar Usuarios " << endl;
	cout << '\t' << "3- Volver al menu principal " << endl << endl;
	exepcionValor e;
	opcion2 = e.validar(1, 3);
	return opcion2;
}

int vista::subMenu2(){
	int opcion3;
	system("cls");
	cout << '\t' << "1- Mantenimiento años y ciclos lectivos " << endl;
	cout << '\t' << "2- Mantenimiento de carreras y cursos " << endl;
	cout << '\t' << "3- Empadronamiento" << endl;
	cout << '\t' << "4- Volver al menu principal " << endl << endl;
	exepcionValor e;
	opcion3 = e.validar(1, 4);
	return opcion3;
}



usuario* vista::crearUsuario() {
	string nombre;
	string id;
	string clave;
	int opcion;
	cout << "-----CREANDO USUARIO--------" << endl;
	cout << "INGRESE EL ID " << endl;
	cin >> id;
	cout << "INGRESE EL NOMBRE..." << endl;
	cin >> nombre;
	exepcionValor e;
	clave = e.validarContra1();
	cout << "INGRESE NUMERO DE ROL" << endl;
	cout << "1- Usuario-Administrador " << endl;
	cout << "2- Usuario-Registo " << endl;
	cout << "3- Usuario-Estudiante " << endl;
	cout << "4- Usuario-Profesor " << endl;
	exepcionValor e2;
	opcion = e2.validar(1, 4);
	switch (opcion) {
	case 1: {
		usuario* a = new administrativos(id, nombre, clave, "USUARIO-ADMINISTRADOR");
		cout << '\t' << "USUARIO AGREGADO CON EXITO!!" << endl;
		Sleep(1000);
		return a;
	}
		  break;
	case 2: {
		usuario* a = new registro(id, nombre, clave, "USUARIO-REGISTRO");
		cout << '\t' << "USUARIO AGREGADO CON EXITO!!" << endl;
		Sleep(1000);
		return a;
	}
		  break;
	case 3: {
		int celu1;
		cout << "INGRESE EL NUMERO DE CELULAR " << endl;
		cin >> celu1;
		usuario* a = new estudiante(id, nombre, clave, "USUARIO-ESTUDIANTE",celu1);
		cout << '\t' << "USUARIO AGREGADO CON EXITO!!" << endl;
		Sleep(1000);
		return a;
	}
		  break;
	case 4: {
		int celu;
		string grado;
		cout << "INGRESE EL NUMERO DE CELULAR " << endl;
		cin >> celu;
		cout << "INGRESE EL GRADO ACADEMICO" << endl;
		cin >> grado;
		usuario* a = new profesor(id, nombre, clave, "USUARIO-ESTUDIANTE", celu, grado);
		cout << '\t' << "USUARIO AGREGADO CON EXITO!!" << endl;
		Sleep(1000);
		return a;
	}
		  break;

	}
	return NULL;
}

usuario* vista::logearse(lista<usuario>* a ){
	int contador = 0;
	int n;
	n = a->getCant();
	usuario* aux;
	string nombre, clave;
	a->iniciarlizarActual();
	cout << "INGRESE SU NOMBRE " << endl;
	cin >> nombre;
	cout << "INGRESE SU CONTRASEÑA " << endl;
	cin >> clave;
	while (contador < n) {
		contador++;
		aux = a->getDato();
		if (aux->getnombreUsu() == nombre && aux->getclaveUsu() == clave) {
			return aux;
		}
		a->siguienteNodo();
	}
	return NULL;
}



usuario* vista::crearAdminInicial() {
	string nombre;
	string id;
	string clave;
	cout << "-----CREANDO ADMINISTRADOR--------" << endl;
	cout << "INGRESE EL ID " << endl;
	cin >> id;
	cout << "INGRESE EL NOMBRE..." << endl;
	cin >> nombre;
	exepcionValor e;
	clave = e.validarContra1();
	usuario* admin1 = new administrativos(id, nombre, clave, "USUARIO-ADMINISTRADOR");
	return admin1;
}

