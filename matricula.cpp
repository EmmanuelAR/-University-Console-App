#include "matricula.h"

void matricula::matricularEstudiante(universidad* uni, estudiante* estudianteAux) {
	string periocidad,nrc;
	int año;
	bool flag1 = true;
	bool flag2 = true;
	ciclo* cicloAux = NULL;
	system("cls");
	cout << "------------------BIENVENIDO AL SISTEMA DE MATRICULA---------------------------" << endl<<endl;
	carrera* carreraAux = estudianteAux->getProfesion();
	cout<<'\t'<< "Usted se encuentra empadronado en la carrera " << carreraAux->getNombreCarrera() << endl;

	do {
		
		cout << uni->mostrarCiclos();
		cout << endl << endl;
		cout << '\t' << "ESCOJA EN CUAL CICLO " << endl;
		cout << '\t' << "INGRESE LA EL PERIODO (I,II,III)...."; cin >> periocidad;
		cout << '\t' << "INGRESE EL ANNIO DEL CICLO... "; cin >> año;
		 cicloAux = uni->buscarCicloEspecifico(periocidad, año);
		 if (cicloAux) {
			 flag1 = false;
			 do {
				 system("cls");
				 cout << carreraAux->retornarGruposEspecificos(año, periocidad);

				 cout << "Ingrese el nrc del grupo "; cin >> nrc;

				 grupo* grupoAux = carreraAux->getTodosgrupo()->buscarPorString(nrc);

				 if (grupoAux) {
					 flag2 = false;

					 curso* cursoAux = grupoAux->getCursoAsociado();

					 if (cursoAux->getTodosRequisitos()->getCant() == 0) {
						 if (estudianteAux->getHistorial()->verificarMatriculado(grupoAux->getCursoAsociado()->getNombreCurso()) == false) {




							 if (estudianteAux->verificarGrupoYaMatriculado(nrc) == false) {
								 system("cls");
								 grupoAux->matricularEstuadinte(estudianteAux);
								 estudianteAux->agregarGrupoAlBloque(grupoAux);
								 //creo copia del curso para el estudiante
								 curso* cursoNuevo = new curso(grupoAux->getCursoAsociado()->getNombreCurso(), grupoAux->getCursoAsociado()->getTipo(), grupoAux->getCursoAsociado()->getCreditos(), grupoAux->getCursoAsociado()->getHoras(), grupoAux->getCursoAsociado()->getEstado(), grupoAux->getCursoAsociado()->getCicloAsociado(), grupoAux->getCursoAsociado()->getCarreraAsociada());
								 cursoNuevo->setCodigoCopia(grupoAux->getCursoCodigo());
								 estudianteAux->agregarCursoMatricula(cursoNuevo);
								 //
								 cout << "-----------------------------------------------------------------------------" << endl;
								 cout << '\t' << '\t' << "ESTUDIANTE MATRICULADO CON EXITO!!" << endl << endl;

								 cout << grupoAux->mostrarListadoEstudiantes();

								 system("pause");
							 }
							 else {
								 cout << "CURSO YA MATICULADO" << endl;
								 Sleep(1000);
								 flag2 = true;
							 }
						 }
						 else {
							 cout << "CURSO YA APROBADO" << endl;
							 Sleep(1000);
							 flag2 = true;
						 }



					 }
					 else {

						 lista<curso>* requisitos = cursoAux->getTodosRequisitos();
						 if (estudianteAux->getHistorial()->verificarRequisitos(requisitos) == true) {

							 if (estudianteAux->getHistorial()->verificarMatriculado(grupoAux->getCursoAsociado()->getNombreCurso()) == false) {




								 if (estudianteAux->verificarGrupoYaMatriculado(nrc) == false) {
									 system("cls");
									 grupoAux->matricularEstuadinte(estudianteAux);
									 estudianteAux->agregarGrupoAlBloque(grupoAux);
									 //creo copia del curso para el estudiante
									 curso* cursoNuevo = new curso(grupoAux->getCursoAsociado()->getNombreCurso(), grupoAux->getCursoAsociado()->getTipo(), grupoAux->getCursoAsociado()->getCreditos(), grupoAux->getCursoAsociado()->getHoras(), grupoAux->getCursoAsociado()->getEstado(), grupoAux->getCursoAsociado()->getCicloAsociado(), grupoAux->getCursoAsociado()->getCarreraAsociada());
									 cursoNuevo->setCodigoCopia(grupoAux->getCursoCodigo());
									 estudianteAux->agregarCursoMatricula(cursoNuevo);
									 //
									 cout << "-----------------------------------------------------------------------------" << endl;
									 cout << '\t' << '\t' << "ESTUDIANTE MATRICULADO CON EXITO!!" << endl << endl;

									 cout << grupoAux->mostrarListadoEstudiantes();

									 system("pause");
								 }
								 else {
									 cout << "GRUPO YA MATICULADO" << endl;
									 Sleep(1000);
									 flag2 = false;
								 }
							 }
							 else {
								 cout << "CURSO YA APROBADO" << endl;
								 Sleep(1000);
								 flag2 = false;
							 }




						 }
						 else {
							 cout << "ERROR: REQUISITOS" << endl;
							 Sleep(1000);
							 flag2 = false;
						 }

					 }

				 }
				 else {
					 cout << "ERROR: NRC INCORRECTO" << endl;
					 Sleep(1000);
				 }
			 } while (flag2 == true);
		 }
		 else
		 {
			 cout << "ERROR: CICLO INCORECTO" << endl;
			 Sleep(1000);
		 }
	} while (flag1 == true);

}

void matricula::consultaGeneralMatricula(universidad* uni,estudiante* estudianteAux)
{

	system("cls");
	string periocidad;
	int año;
	ciclo* cicloAux = NULL;
	bool bandera1 = true;

	do {
		cout << uni->mostrarCiclos();
		cout << endl << endl;
		cout << '\t' << "ESCOJA EN CUAL CICLO " << endl;
		cout << '\t' << "INGRESE LA EL PERIODO (I,II,III)...."; cin >> periocidad;
		cout << '\t' << "INGRESE EL ANNIO DEL CICLO... "; cin >> año;
		cicloAux = uni->buscarCicloEspecifico(periocidad, año);

		if (cicloAux) {
			bandera1 = false;
			system("cls");
			cout<< estudianteAux->retornarGruposEspecificos(año, periocidad);
			system("pause");
		}
		else {
			cout << "ERROR: CICLO INCORRECTO" << endl;
			Sleep(2000);
			bandera1 = true;
		}
	} while (bandera1 == true);


}

void matricula::historialAcademicoEstudiante( estudiante* estudianteAux)
{
	cout << estudianteAux->getHistorial()->hitorialEspecial();
}
		 
