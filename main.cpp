#include <Windows.h>
#include"usuarios.h"
#include"ciclo.h"
#include"carrera.h"
#include"escuela.h"
#include "grupo.h"
#include"administrativos.h"
#include"profesor.h"
#include"registro.h"
#include "estudiante.h"
#include"listaGenerica.h"
#include"universidad.h"
#include"controladora.h"
#include"vista.h"
#include"exepcionGeneral.h"
#include "fecha.h"
#include"matricula.h"





int main() {
	
	//controladora* controlPrincipal = new controladora();

	universidad* uni = new universidad();
	//usuario por defecto
	usuario* a1 = new administrativos("117790953","admin","admin","USUARIO- ADMIN");
	uni->agregarUsuariosPro(a1);
	//Escuelas de la U
	escuela* escuela1 = new escuela("ESCUELA-INFORMATICA");
	uni->agregarEscuelaPro(escuela1);
	//	




	usuario* usuario1 = new estudiante("0000001", "Emmanuel", "aa", "USUARIO-ESTUDIANTE", 84339541);
	usuario* usuario2 = new estudiante("0000002", "Carlos", "bb", "USUARIO-ESTUDIANTE", 0000001);
	usuario* usuario3 = new profesor("0000003", "Pedro", "cc", "USUARIO-PROFESOR", 0000002,"LICENCIADO");
	usuario* usuario4 = new profesor("0000004", "Isaac", "dd", "USUARIO-PROFESOR", 0000003, "LICENCIADO");
	usuario* usuario5 = new registro("0000003", "Pedro", "cc", "USUARIO-REGISTRO");
	uni->agregarUsuariosPro(usuario1);
	uni->agregarUsuariosPro(usuario2);
	uni->agregarUsuariosPro(usuario3);
	uni->agregarUsuariosPro(usuario4);
	uni->agregarUsuariosPro(usuario5);
	//ciclos
	fecha* fechaInicio = new fecha(01, 01, 2020);
	fecha* fechaFinal = new fecha(01, 02, 2020);
	ciclo* c1 = new ciclo(2020, "I", fechaInicio, fechaFinal);
	uni->agregarCiclo(c1);
	//carrera
	carrera* carrera1 = new carrera("EIF", "SISTEMAS", "BACHILLERATO", "CIENCIAS");
	escuela1->agregarCarrerasPro(carrera1);
	//
	curso* curso1 = new curso("Matematica General", "LAB", 4, 5, "ACTIVO", c1, carrera1);
	curso1->setCodigo();
	carrera1->agregarCursoPlan(curso1);

	curso* curso2 = new curso("Calculo", "LAB", 4, 5, "ACTIVO", c1, carrera1);
	curso2->setCodigo();
	carrera1->agregarCursoPlan(curso2);
	curso2->agregarRequistosPro(curso1);

	//
	estudiante* estudiante1 = exepcionCambioTipo::cambiarEstudiante(usuario1);
	carrera1->agregarEstudinatesPro(estudiante1);
	estudiante1->setProfesion(carrera1);
	estudiante* estudiante2 = exepcionCambioTipo::cambiarEstudiante(usuario2);
	carrera1->agregarEstudinatesPro(estudiante2);
	estudiante2->setProfesion(carrera1);
	//
	profesor* profesor1 = exepcionCambioTipo::cambiarProfesor(usuario3);
	carrera1->agregarProfesorPro(profesor1);
	profesor* profesor2 = exepcionCambioTipo::cambiarProfesor(usuario4);
	carrera1->agregarProfesorPro(profesor2);
	//
	grupo* grupo1 = new grupo(12, "L-J", "7:00", "9:00", curso2);
	grupo1->setNRC();
	grupo1->setNumeroGrupo();
	grupo1->setProfesor(profesor1);
	stringstream s;
	s << "L-J" << '\t' << "7:00" << "-" << "9:00";
	grupo1->setHorario(s.str());
	profesor1->agregarGruposPro(grupo1);
	curso2->agregaGrupoPro(grupo1);
	carrera1->agregarGrupoMatricula(grupo1);
	//
	estudiante1->getHistorial()->agregarCursoAprobado(curso1);
	curso1->setNotaFinal(9);




	













	
	int opcionMenuInicio;
	do {
		cout << "-----------------------------------------------------------------------" << endl;
		cout << '\t' << '\t' << "1- LOGEARSE" << endl;
		cout << '\t' << '\t' << "2- SALIR" << endl;
		cout << "-----------------------------------------------------------------------" << endl;


		exepcionValor e;
		opcionMenuInicio = e.validar(1, 2);
		 
		switch (opcionMenuInicio) {
		case 1: {

			usuario* aux = NULL;
			system("cls");
			string identificacion, clave;
			cout << "\n\n\n\n\n" << endl;
			cout << "                                 INICIO DE SESION" << endl;
			cout << "                                ------------------" << endl;
			cout << "\n\tIdentificacion: "; cin >> identificacion;

			cout << "\tClave: "; cin >> clave;


			aux = uni->buscarUsuarioEspecifico(identificacion, clave);
			if (aux) {
				cout << endl;
				cout << '\t' << " USUARIO VALIDO " << endl;
				Sleep(2000);
				
				


				int opcionPricipal;
				do {
					system("cls");

					cout << "--------Universidad Nacional De Costa Rica-----" << endl << endl;
					cout << "----------------Menu Pricipal------------------" << endl << endl;
					cout << "\t" << "1- Seguridad y admnistracion de roles" << endl;
					cout << "\t" << "2- Mantenimiento General a Nivel de Registro" << endl;
					cout << "\t" << "3- Mantenimiento por Escuelas " << endl;
					cout << "\t" << "4- Matricula e historiales " << endl;
					cout << "\t" << "5- Registro de actas" << endl;
					cout << "\t" << "6- CERRAR SESSION " << endl << endl;

					exepcionValor e;
					opcionPricipal = e.validar(1, 6);
					system("cls");
					switch (opcionPricipal) {
					case 1: {
						if (aux->getIndentificador() == 1) {
							int opcion2;
							do {
								system("cls");
								cout << "-----------------------------------------------------------------------" << endl;
								cout << '\t' << "1- Crear Usuario " << endl;
								cout << '\t' << "2- Mostrar Usuarios " << endl;
								cout << '\t' << "3- Volver al menu principal " << endl << endl;
								cout << "-----------------------------------------------------------------------" << endl;
								exepcionValor e;
								opcion2 = e.validar(1, 3);

								system("cls");

								switch (opcion2) {


								case 1: {

									string nombre;
									string id;
									string clave;
									int opcion;
									cout << "\t" << "-----CREANDO NUEVO USUARIO--------" << endl;
									cout << "\t" << "INGRESE EL ID ";
									cin >> id;
									cout << "\t" << "INGRESE EL NOMBRE...";
									cin >> nombre;
									exepcionValor e;
									clave = e.validarContra1();
									cout << "-----------------------------------------------------------------------" << endl;
									cout << "\t" << "INGRESE NUMERO DE ROL" << endl;
									cout << "\t" << "1- Usuario-Administrador " << endl;
									cout << "\t" << "2- Usuario-Registo " << endl;
									cout << "\t" << "3- Usuario-Estudiante " << endl;
									cout << "\t" << "4- Usuario-Profesor " << endl;
									cout << "-----------------------------------------------------------------------" << endl;
									exepcionValor e2;
									opcion = e2.validar(1, 4);

									switch (opcion) {
									case 1: {
										usuario* a = new administrativos(id, nombre, clave, "USUARIO-ADMINISTRADOR");
										cout << '\t' << "USUARIO AGREGADO CON EXITO!!" << endl;
										Sleep(1000);
										uni->agregarUsuariosPro(a);
									}
										  break;

									case 2: {
										usuario* a = new registro(id, nombre, clave, "USUARIO-REGISTRO");
										cout << '\t' << "USUARIO AGREGADO CON EXITO!!" << endl;
										Sleep(1000);
										uni->agregarUsuariosPro(a);
									}
										  break;
									case 3: {
										int celu1;
										cout << "INGRESE EL NUMERO DE CELULAR " << endl;
										cin >> celu1;
										usuario* a = new estudiante(id, nombre, clave, "USUARIO-ESTUDIANTE",celu1);
										cout << '\t' << "USUARIO AGREGADO CON EXITO!!" << endl;
										Sleep(1000);
										uni->agregarUsuariosPro(a);
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
										uni->agregarUsuariosPro(a);
									}
										  break;
									}
								}


									  break;

								case 2: {
									cout << uni->mostrarUsuarios();
									system("pause");
								}
									  break;
								};
							} while (opcion2 != 3);
						}
						else {
							cout << "PROHIBIDO EL INGRESO PARA  " << aux->getrolUsu() << endl;
							Sleep(1000);
						}
					}
						  break;
					case 2: {
						if (aux->getIndentificador() == 1 || aux->getIndentificador() == 2) {
							int opcion3;
							do {
								system("cls");
								cout << "-----------------------------------------------------------------------" << endl;
								cout << '\t' << "1- Mantenimiento anios y ciclos lectivos " << endl;
								cout << '\t' << "2- Mantenimiento de carreras y cursos " << endl;
								cout << '\t' << "3- Empadronamiento" << endl;
								cout << '\t' << "4- Volver al menu principal " << endl << endl;
								cout << "-----------------------------------------------------------------------" << endl;
								exepcionValor e;
								opcion3 = e.validar(1, 4);

								system("cls");
								switch (opcion3) {
								case 1: {
									int opcionSUB2_1;
									do {
										system("cls");
										cout << "-----------------------------------------------------------------------" << endl;
										cout << '\t' << "1- Ingresar ciclos lectivos " << endl;
										cout << '\t' << "2- Ver ciclos lectivos" << endl;
										cout << '\t' << "3- Volver al menu anterior" << endl << endl;
										cout << "-----------------------------------------------------------------------" << endl;
										exepcionValor e;
										opcionSUB2_1 = e.validar(1, 3);
										system("cls");
										switch (opcionSUB2_1) {
										case 1: {
											int annio, dia, mes, annioo, dia2, mes2, annioo2, val;
											string periocidad, fechaI, fechaF;
											bool f = true;
											//
											cout << '\t' << "------- CREANDO CICLOS ----------------" << endl;
											cout << '\t' << "Dijite el annio del ciclo... ";
											cin >> annio;
											cout << '\t' << "Dijite numeracion (I,II,III)...";
											cin >> periocidad;
											do {
												cout << '\t' << "Ingrese la fecha de inicio " << endl;
												cout << '\t' << "Dia de inicio: ";
												cin >> dia;
												cout << '\t' << "Mes de inicio: ";
												cin >> mes;
												cout << '\t' << "Annio de inicio ";
												cin >> annioo;
												fecha* fecha1 = new fecha(dia, mes, annioo);

												cout << '\t' << "Ingrese la fecha de Finalizacion " << endl;
												cout << '\t' << "Dia de finalizacion: ";
												cin >> dia2;
												cout << '\t' << "Mes de finalizacion: ";
												cin >> mes2;
												cout << '\t' << "Annio de finalizacion: ";
												cin >> annioo2;
												fecha* fecha2 = new fecha(dia2, mes2, annioo2);


												val = fecha::comparaFecha(fecha1, fecha2);
												if (val < 0) {
													ciclo* nuevoCiclo = new ciclo(annio, periocidad, fecha1, fecha2);
													f = false;
													cout << '\t' << "CICLO CREADO CON EXITO!!" << endl;
													uni->agregarCiclo(nuevoCiclo);
													Sleep(1000);

												}
												else {
													if (val == 0) {
														cout << '\t' << "ERROR: FECHAS IGUALES" << endl;
													}
													else {
														cout << '\t' << "ERROR: FECHA DE INICIO MAYOR A LA FECHA DEL FINAL" << endl;
													}
												}

											} while (f == true);

										}
											  break;
										case 2: {
											cout<<uni->mostrarCiclos();
											Sleep(4000);
										}
											  break;
										};




									} while (opcionSUB2_1 != 3);


								}
									  break;
								case 2: {
									int opcionSUB2_2;
									do {
										system("cls");
										cout << "-----------------------------------------------------------------------" << endl;
										cout << '\t' << "1- Ingresar de nuevas carreras " << endl;
										cout << '\t' << "2- Ingresar cursos " << endl;
										cout << '\t' << "3- Volver al menu anterior" << endl << endl;
										cout << "-----------------------------------------------------------------------" << endl;
										exepcionValor e;
										opcionSUB2_2 = e.validar(1, 3);
										system("cls");
										switch (opcionSUB2_2) {
										case 1: {
											string codigo, nombreCarrera, grado, facultad;
											int posicion;
											escuela* auxEscuela;
											cout << '\t' << "CREANDO NUEVAS CARRERAS " << endl;
											cout << '\t' << "Ingrese el codigo de la carrera... ";
											cin >> codigo;
											cout << '\t' << "Ingrese el nombre de la carrera... ";
											cin >> nombreCarrera;
											cout << '\t' << "INNGRESE EL GRADO DE LA CARRERA (DIPLOMADO-MAESTRIA-LICENCIATURA)... ";
											cin >> grado;
											cout << '\t' << "INGRESE LA FACULTAD DE LA ESCUELA... ";
											cin >> facultad;
											cout << endl << endl;
											cout << uni->mostarEscuelas();
											cout << endl;
											cout << '\t' << "A CUAL ESCUELA LE QUEIRE ASIGNAR LA CARRERA ?" << endl;
											cout << '\t' << "INGRESE LA POSICION " << endl;
											exepcionValor e;
											posicion = e.validar(1, uni->getTodasEscuelas()->getCant());
											auxEscuela = uni->recuperarEscuelaPosicion(posicion);
											carrera* c1 = new carrera(codigo, nombreCarrera, grado, facultad);
											auxEscuela->agregarCarrerasPro(c1);
											cout << '\t' << "INGRESO DE CARRRERA EXITOSO !!!" << endl;
											Sleep(2000);

										}
											  break;
										case 2: {

											string periocidad, nombreCurso, tipoCurso, estado, desicion;
											int año, pos1, pos2, creditos, requisitos, horas, pos3;
											int contador = 0;
											ciclo* cicloAux = NULL;
											escuela* escuelaAux = NULL;
											carrera* carreraAux = NULL;
											curso* cursoAux = NULL;
											bool f = true;

											do {
												system("cls");
												cout << '\t' << "-----------------CREANDO CURSOS----------------------" << endl;
												cout << uni->mostrarCiclos();
												//exepcion lista vacia
												cout << endl;
												cout << '\t' << "ESCOJA EN CUAL CICLO QUIERE MATRICULAR EL CURSO " << endl;
												cout << '\t' << "INGRESE LA EL PERIODO (I,II,III)...."; cin >> periocidad;
												cout << '\t' << "INGRESE EL ANNIO DEL CICLO... "; cin >> año;
												cicloAux = uni->buscarCicloEspecifico(periocidad, año);



												if (cicloAux) {
													f = false;

													system("cls");
													cout << uni->mostarEscuelas();
													cout << '\t' << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE MATRICULAR EL CURSO" << endl;
													exepcionValor a1;
													pos1 = a1.validar(1, uni->getCantEscuelas());
													escuelaAux = uni->recuperarEscuelaPosicion(pos1);
													system("cls");
													cout << escuelaAux->mostrarCarreras();
													//exepcion lista vacia
													cout << "\t" << " DIGITE EL NUMERO DE LA CARRERA DONDE QUIERE MATRICULAR EL CURSO " << endl;
													exepcionValor a2;
													pos2 = a2.validar(1, escuelaAux->getCantCarreras());

													carreraAux = escuelaAux->recuperarCarreraPro(pos2);
													system("cls");
													cout << '\t' << "DIGITE EL NOMBRE DEL CURSO... "; cin >> nombreCurso;
													cout << '\t' << "DIGITE EL TIPO DE CURSO (LAB,CUR,SEM,PRA,TES)..."; cin >> tipoCurso;
													cout << '\t' << "DIJITE EL NUMERO DE CREDITOS... " << endl;
													exepcionValor e;
													creditos = e.validar(1, 4);
													cout << '\t' << "DIGITE EL LAS HORAS SEMANALES... " << endl;
													exepcionValor a;
													horas = a.validar(1, 10);
													cout << '\t' << "DIGITE EL ESTADO DEL CURSO (ACTIVO - INACTIVO) ..."; cin >> estado;

													curso* cursoPrueba = new curso(nombreCurso, tipoCurso, creditos, horas, estado, cicloAux, carreraAux);
													cursoPrueba->setCodigo();
													system("cls");
													cout << '\t' << "QUIERE AGREGARLE REQUISITOS AL CURSO ( si / no )... "; cin >> desicion;


													if (desicion == "si" || desicion == "SI" || desicion == "sI") {
														cout << '\t' << "CUANTOS CURSOS PRE-REQUISITOS..."; cin >> requisitos;
														do {
															system("cls");
															cout << carreraAux->mostrarPlanEstudios();
															//exepcion lista vacia
															cout << '\t' << "DIGITE EL NUMERO DE CURSO PARA AGREGARLO AL LOS REQUISITOS... "; cin >> pos3;
															cursoAux = carreraAux->recuperarCursoPro(pos3);
															cursoPrueba->agregarRequistosPro(cursoAux);
															contador++;
															cout << '\t' << "REQUISITO AGREGADOS CON EXITO!!" << endl;
															Sleep(1000);
														} while (contador < requisitos);
													}
													system("cls");
													cout << '\t' << "CURSO AGREGADO CON EXITO!!!!" << endl;
													carreraAux->agregarCursoPlan(cursoPrueba);
													Sleep(2000);
												}
											} while (f == true);


										}
											  break;
										};

									} while (opcionSUB2_2!= 3);



								}
									  break;
								case 3: {
									int opcionSUB2_3;
									
									do {
										system("cls");
										cout << "-----------------------------------------------------------------------" << endl;
										cout << '\t' << "1- Empadronamiento de estudiantes " << endl;
										cout << '\t' << "2- Mostrar estudiantes empadronados en la carrera " << endl;
										cout << '\t' << "3- Volver al menu principal " << endl << endl;
										cout << "-----------------------------------------------------------------------" << endl;
										exepcionValor e;
										opcionSUB2_3 = e.validar(1, 3);

										system("cls");
										switch (opcionSUB2_3) {
										case 1: {
											string cedula, codigo;
											int pos1;
											bool puerta = true;
											bool puerta2 = true;

											cout << '\t' << "EMPADRONAMIENTO DE ESTUDIANTES" << endl;
											do {


												cout << '\t' << "INGRESE LA CEDULA DEL ESTUDIANTE..."; cin >> cedula;
												usuario* a = uni->getTodosUsuarios()->buscarPorString(cedula);
												if (a) {
													puerta = false;
													estudiante* estudianteAux = exepcionCambioTipo::cambiarEstudiante(a);
													cout << "SE RECUPERO A USUARIO DE LA BASE DATOS " << endl << endl;

													cout << '\t' << "Identificacion ->" << estudianteAux->getidUsu() << endl;
													cout << '\t' << "Nombre ->" << estudianteAux->getnombreUsu() << endl;
													cout << '\t' << "Telefono ->" << estudianteAux->getTelefono() << endl << endl;
													Sleep(4000);
													system("cls");
													cout << uni->mostarEscuelas();
													cout << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE EMPADRONAR AL ESTUDIANTE  " << endl;
													exepcionValor exe1;
													pos1 = exe1.validar(1, uni->getCantEscuelas());

													escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos1);
													do {

														system("cls");
														cout << escuelaAux->mostrarCarreras();
														cout << "INGRESE EL CODIGO DE LA CARRERA "; cin >> codigo;
														carrera* carreraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigo);
														if (carreraAux) {
															puerta2 = false;
															carreraAux->agregarEstudinatesPro(estudianteAux);
															estudianteAux->setProfesion(carreraAux);
															cout << endl << endl;
															cout << '\t' << "EL estudiante " << estudianteAux->getnombreUsu() << " fue empadronado en :" << endl;
															cout << '\t' << carreraAux->getNombreCarrera() << endl;
															cout << '\t' << escuelaAux->getNombreEscuela() << endl;
															Sleep(4000);


														}
														else {
															cout << '\t' << "ERROR: Codigo Incorrecto " << endl;
															Sleep(2000);
														}
													} while (puerta2 == true);
												}
												else
												{
													cout << "ERROR: Usuario no registrado en la base de datos" << endl;
												}
											} while (puerta == true);

										}
											  break;
										case 2: {
											int pos;
											string codigo;
											bool bandera = true;
											cout << "------------------------------------------------------------" << endl << endl;
											cout << uni->mostarEscuelas();
											cout << "Ingrese la posicion de la escuela... " << endl;
											exepcionValor a;
											pos = a.validar(1, uni->getCantEscuelas());
											escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos);
											do {


												system("cls");
												cout << "------------------------------------------------------------" << endl << endl;
												cout << escuelaAux->mostrarCarreras();
												cout << "Ingrese el codigo de la carrera... "; cin >> codigo;
												carrera* carrerraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigo);
												if (carrerraAux) {
													bandera = false;
													system("cls");
													cout << carrerraAux->mostrarEstudiantesEmpadronados();
													Sleep(4000);

												}
												else {
													cout << '\t' << "ERROR: Codigo Incorrecto " << endl;
													
												}
											} while (bandera == true);




											




										}
											  break;
										};
									} while (opcionSUB2_3 != 3);
								}
									  break;
								};
							} while (opcion3 != 4);
						}
						else {
							cout << "PROHIBIDO EL INGRESO PARA  " << aux->getrolUsu() << endl;
							Sleep(1000);
						}
					}
						  break;
					case 3: {
						if (aux->getIndentificador() == 1 || aux->getIndentificador() == 2) {
							int opcion4;
							do {
								system("cls");
								cout << "-----------------------------------------------------------------------" << endl;
								cout << '\t' << "1- Consulta del plan de estudios vigente por carrera" << endl;
								cout << '\t' << "2- Crear grupos " << endl;
								cout << '\t' << "3- Consulta general de matricula" << endl;
								cout << '\t' << "4- Ingreso de profesores" << endl;
								cout << '\t' << "5- Volver al menu principal " << endl << endl;
								cout << "-----------------------------------------------------------------------" << endl;
								exepcionValor e;
								opcion4 = e.validar(1, 5);

								system("cls");
								switch (opcion4) {
								case 1: {
									int pos1, pos2;
									string enter;
									carrera* carreraAux = NULL;
									escuela* escuelaAux = NULL;
									cout << uni->mostarEscuelas();
									cout << '\t' << "DIGITE EL NUMERO DE LA ESCUELA" << endl;
									exepcionValor ex1;
									pos1 = ex1.validar(1, uni->getCantEscuelas());
									escuelaAux = uni->recuperarEscuelaPosicion(pos1);
									system("cls");
									cout << escuelaAux->mostrarCarreras();
									cout << "\t" << " DIGITE EL NUMERO DE LA CARRERA" << endl;
									exepcionValor ex2;
									pos2 = ex2.validar(1, escuelaAux->getCantCarreras());
									carreraAux = escuelaAux->recuperarCarreraPro(pos2);
									cout << carreraAux->mostrarPlanEstudiosEspecial();
									Sleep(5000);

								}
									  break;
								case 2: {
									int pos, cantGrupos, cupo;
									int contador = 0;
									string codigo, codigocurso, dias, horaInicio, horaFinal, idProfe;
									bool bandera = true;
									bool bandera2 = true;
									bool bandera3 = true;

									cout << "------------------------------------------------------------" << endl << endl;
									cout << uni->mostarEscuelas();
									cout << "Ingrese la posicion de la escuela... " << endl;
									exepcionValor a;
									pos = a.validar(1, uni->getCantEscuelas());
									escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos);
									do {


										system("cls");
										cout << "------------------------------------------------------------" << endl << endl;
										cout << escuelaAux->mostrarCarreras();
										cout << "Ingrese el codigo de la carrera... "; cin >> codigo;
										carrera* carrerraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigo);
										if (carrerraAux) {
											bandera = false;
											system("cls");
											do {
												cout << "-----------------------------------------------------------------" << endl;
												cout << carrerraAux->mostrarPlanEstudios();
												cout << "Ingrese el codigo del curso "; cin >> codigocurso;
												curso* cursoAux = carrerraAux->getTodosCursos()->buscarPorString(codigocurso);
												if (cursoAux) {
													bandera2 = false;
													system("cls");
													cout << '\t' << "ACTUALMENTE EXISTEN LOS SIGUIENTES GRUPOS DEL CURSO " << cursoAux->getNombreCurso() << endl << endl;
													cout << cursoAux->mostrarGruposAsignados();
													cout << "Cuantos grupos desea crear ?"; cin >> cantGrupos;
													do {
														system("cls");
														cout << "Ingrese el cupo " << endl;
														exepcionValor e;
														cupo = e.validar(1, 30);
														cout << "Ingrese los dias de clase ejemplo -> ( L- J) "; cin >> dias;
														cout << "Ingrese la hora de inicio (# : # #) "; cin >> horaInicio;
														cout << "Ingrese la hora de final (# : # #) "; cin >> horaFinal;

														grupo* grupoAux = new grupo(cupo, dias, horaInicio, horaFinal, cursoAux);
														grupoAux->setNRC();
														grupoAux->setNumeroGrupo();
														stringstream s;
														s << dias << '\t' << horaInicio << "-" << horaFinal;
														grupoAux->setHorario(s.str());





														system("cls");
														do {
															system("cls");
															cout << endl << endl << endl;
															cout << carrerraAux->mostrarProfesores();
															cout << endl;
															cout << "Ingrese el id del profesor encargado "; cin >> idProfe;
															profesor* profeAux = carrerraAux->getTodosProfesores()->buscarPorString(idProfe);

															string auxHorario = grupoAux->getHorario();
															if (profeAux) {


																if (profeAux->validarCreacionGrupo(auxHorario) == false) {

																	bandera3 = false;
																	cout << profeAux->getnombreUsu() << endl;

																	//seteo de partes
																	profeAux->agregarGruposPro(grupoAux);
																	cursoAux->agregaGrupoPro(grupoAux);
																	grupoAux->setCurso(cursoAux);
																	grupoAux->setProfesor(profeAux);
																	//nuevo 08-04
																	carrerraAux->agregarGrupoMatricula(grupoAux);
																	//

																	system("cls");
																	cout << endl << endl;
																	//

																	//
																	cout << "GRUPO CREADO EXITOSAMENTE !!" << endl;
																	Sleep(1000);
																}
																else {


																	cout << '\t' << "ERROR: EL PROFESOR TIENE UN CURSO A ESE HORARIO" << endl;
																	Sleep(3000);
																	bandera3 = true;

																}
															}
															else {


																cout << '\t' << "ERROR: EL ID ES INCORRECTO" << endl;
																Sleep(4000);
																bandera3 = true;

															}

														} while (bandera3 == true);








														contador++;
													} while (contador < cantGrupos);
													system("cls");
													cout << "GRUPOS CREADOS EXITOSAMENTE !!" << endl;
													cout << cursoAux->mostrarGruposAsignados();
													
													Sleep(4000);

												}
												else {
													cout << '\t' << "ERROR: Codigo Incorrecto " << endl;
												}
											} while (bandera2 == true);

										}
										else {
											cout << '\t' << "ERROR: Codigo Incorrecto " << endl;

										}
									} while (bandera == true);

								}
									  break;
								case 3: {
									int pos1, año;
									string codigoCarrera, periocidad, codigoCurso, nrc;
									bool flag1 = true;
									bool flag2 = true;
									bool flag3 = true;
									bool flag4 = true;
									ciclo* cicloAux = NULL;
									system("cls");
									cout << uni->mostarEscuelas();
									cout << '\t' << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE MATRICULAR EL CURSO" << endl;
									exepcionValor exepcion1;
									pos1 = exepcion1.validar(1, uni->getCantEscuelas());
									escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos1);

									do {
										system("cls");
										cout << escuelaAux->mostrarCarreras();
										cout << endl << endl;
										cout << "INGRESE EL CODIGO DE LA CARRERA "; cin >> codigoCarrera;
										carrera* carreraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigoCarrera);
										if (carreraAux) {
											flag1 = false;
											do {
												system("cls");
												cout << uni->mostrarCiclos();
												cout << endl << endl;
												cout << '\t' << "ESCOJA EN CUAL CICLO QUIERE MATRICULAR EL CURSO " << endl;
												cout << '\t' << "INGRESE LA EL PERIODO (I,II,III)...."; cin >> periocidad;
												cout << '\t' << "INGRESE EL ANNIO DEL CICLO... "; cin >> año;
												cicloAux = uni->buscarCicloEspecifico(periocidad, año);
												if (cicloAux) {
													flag2 = false;
													do {
														system("cls");
														cout << carreraAux->retornarCursoEspecificos(cicloAux->getAnio(), cicloAux->getPeriocidad());
														cout << endl << endl;
														cout << "Ingrese el CODIGO del curso "; cin >> codigoCurso;
														curso* cursoAux = carreraAux->getTodosCursos()->buscarPorString(codigoCurso);
														if (cursoAux) {
															flag3 = false;
															do {
																system("cls");
																cout << cursoAux->mostrarGruposAsignados();
																cout << endl << endl;
																cout << "Ingrese el NRC del grupo "; cin >> nrc;
																grupo* grupoAux = cursoAux->todosGrupos()->buscarPorString(nrc);
																if (grupoAux) {
																	flag4 = false;
																	system("cls");
																	cout << endl << endl;
																	cout << grupoAux->mostrarListadoEstudiantes();
																	Sleep(4000);
																	//fin
																}
																else {
																	cout << "ERROR: NRC INCORRECTO" << endl;
																	Sleep(2000);
																}
															} while (flag4 == true);

														}
														else {
															cout << "ERROR: CODIGO CURSO INCORRECTO" << endl;
															Sleep(2000);
														}
													} while (flag3 == true);



												}
												else {
													cout << "ERROR: CODIGO INCORRECTO" << endl;
													Sleep(2000);
												}
											} while (flag2 == true);

										}
										else
										{
											cout << '\t' << "ERROR: CODIGO INCORRECTO " << endl;
											Sleep(2000);
										}
									} while (flag1 == true);



								}
									  break;
								case 4: {

									string cedula, codigo;
									int pos1;
									bool puerta = true;
									bool puerta2 = true;

									cout << '\t' << "INGRESO DE PROFESORES" << endl;
									do {


										cout << '\t' << "INGRESE LA CEDULA DEL PROFESOR..."; cin >> cedula;
										usuario* a = uni->getTodosUsuarios()->buscarPorString(cedula);
										if (a) {
											puerta = false;
											profesor* profesorAux = exepcionCambioTipo::cambiarProfesor(a);
											cout << "SE RECUPERO A USUARIO DE LA BASE DATOS " << endl << endl;

											cout << '\t' << "Identificacion ->" << profesorAux->getidUsu() << endl;
											cout << '\t' << "Nombre ->" << profesorAux->getnombreUsu() << endl;
											cout << '\t' << "Telefono ->" << profesorAux->getCelular() << endl;
											cout << '\t' << "Grado Academico ->" << profesorAux->getGradoAcademico() << endl;
											Sleep(4000);
											system("cls");
											cout << uni->mostarEscuelas();
											cout << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE EMPADRONAR AL ESTUDIANTE  " << endl;
											exepcionValor exe1;
											pos1 = exe1.validar(1, uni->getCantEscuelas());

											escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos1);
											do {

												system("cls");
												cout << escuelaAux->mostrarCarreras();
												cout << "INGRESE EL CODIGO DE LA CARRERA "; cin >> codigo;
												carrera* carreraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigo);
												if (carreraAux) {
													puerta2 = false;
													carreraAux->agregarProfesorPro(profesorAux);
													cout << endl << endl;
													cout << '\t' << "EL profesor " << profesorAux->getnombreUsu() << " fue empadronado en :" << endl;
													cout << '\t' << "CARRERA -> " << carreraAux->getNombreCarrera() << endl;
													cout << '\t' << "ESCUELA-> " << escuelaAux->getNombreEscuela() << endl;
													Sleep(4000);


												}
												else {
													cout << '\t' << "ERROR: Codigo Incorrecto " << endl;
													Sleep(2000);
												}
											} while (puerta2 == true);
										}
										else
										{
											cout << "ERROR: Usuario no registrado en la base de datos" << endl;
										}
									} while (puerta == true);

								}
									  break;
								case 6: {


								}
									  break;
								};
							} while (opcion4 != 5);
						}
						else {
							cout << "PROHIBIDO EL INGRESO PARA  " << aux->getrolUsu() << endl;
							Sleep(1000);
						}

					}
						  break;
					case 4: {
						if (aux->getIndentificador() == 1 || aux->getIndentificador() == 3) {
							int opcion5;
							do {
								system("cls");
								cout << "-----------------------------------------------------------------------" << endl;
								cout << '\t' << "1- Proceso de matricula" << endl;
								cout << '\t' << "2- Consulta de matricula por estudiante " << endl;
								cout << '\t' << "3- Historial academico por estudiante" << endl;
								cout << '\t' << "4- Volver al menu principal " << endl << endl;
								cout << "-----------------------------------------------------------------------" << endl;
								exepcionValor e;
								opcion5 = e.validar(1, 6);

								system("cls");
								switch (opcion5) {
								case 1: {
									string iD, codigoCarrera;
									int pos1;
									bool flag1 = true;
									bool flag2 = true;
									if (aux->getIndentificador() == 1) {
										system("cls");
										cout << uni->mostarEscuelas();
										cout << '\t' << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE MATRICULAR EL CURSO" << endl;
										exepcionValor exepcion1;
										pos1 = exepcion1.validar(1, uni->getCantEscuelas());
										escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos1);
										do {
											system("cls");
											cout << escuelaAux->mostrarCarreras();
											cout << endl << endl;
											cout << "INGRESE EL CODIGO DE LA CARRERA "; cin >> codigoCarrera;
											carrera* carreraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigoCarrera);
											if (carreraAux) {
												flag1 = false;
												do {
													system("cls");
													cout << carreraAux->mostrarEstudiantesEmpadronados();
													cout << "Ingrese el ID del estudiante "; cin >> iD;
													estudiante* estudianteAux = carreraAux->getTodosEstudiantes()->buscarPorString(iD);
													if (estudianteAux) {
														flag2 = false;
														matricula::matricularEstudiante(uni, estudianteAux);
													}
													else {
														cout << "ERROR: Id incorrecto" << endl;
													}
												} while (flag2 == true);


											}
											else {
												cout << "Error : codigo equivocado" << endl;

											}
										} while (flag1 == true);
										
										
									}
									else {
										estudiante* estudianteAux = exepcionCambioTipo::cambiarEstudiante(aux);
										matricula::matricularEstudiante(uni, estudianteAux);
									}
									


								}
									  break;
								case 2: {
									string iD, codigoCarrera;
									int pos1;
									bool flag1 = true;
									bool flag2 = true;
									if (aux->getIndentificador() == 1) {
										system("cls");
										cout << uni->mostarEscuelas();
										cout << '\t' << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE MATRICULAR EL CURSO" << endl;
										exepcionValor exepcion1;
										pos1 = exepcion1.validar(1, uni->getCantEscuelas());
										escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos1);
										do {
											system("cls");
											cout << escuelaAux->mostrarCarreras();
											cout << endl << endl;
											cout << "INGRESE EL CODIGO DE LA CARRERA "; cin >> codigoCarrera;
											carrera* carreraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigoCarrera);
											if (carreraAux) {
												flag1 = false;
												do {
													system("cls");
													cout << carreraAux->mostrarEstudiantesEmpadronados();
													cout << "Ingrese el ID del estudiante "; cin >> iD;
													estudiante* estudianteAux = carreraAux->getTodosEstudiantes()->buscarPorString(iD);
													if (estudianteAux) {
														flag2 = false;
														matricula::consultaGeneralMatricula(uni, estudianteAux);
													}
													else {
														cout << "ERROR: Id incorrecto" << endl;
													}
												} while (flag2 == true);


											}
											else {
												cout << "Error : codigo equivocado" << endl;

											}
										} while (flag1 == true);


									}
									else {
										estudiante* estudianteAux = exepcionCambioTipo::cambiarEstudiante(aux);
										matricula::consultaGeneralMatricula(uni, estudianteAux);
									}




								}
									  break;
								case 3: {
									string iD, codigoCarrera;
									int pos1;
									bool flag1 = true;
									bool flag2 = true;
									if (aux->getIndentificador() == 1) {
										system("cls");
										cout << uni->mostarEscuelas();
										cout << '\t' << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE MATRICULAR EL CURSO" << endl;
										exepcionValor exepcion1;
										pos1 = exepcion1.validar(1, uni->getCantEscuelas());
										escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos1);
										do {
											system("cls");
											cout << escuelaAux->mostrarCarreras();
											cout << endl << endl;
											cout << "INGRESE EL CODIGO DE LA CARRERA "; cin >> codigoCarrera;
											carrera* carreraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigoCarrera);
											if (carreraAux) {
												flag1 = false;
												do {
													system("cls");
													cout << carreraAux->mostrarEstudiantesEmpadronados();
													cout << "Ingrese el ID del estudiante "; cin >> iD;
													estudiante* estudianteAux = carreraAux->getTodosEstudiantes()->buscarPorString(iD);
													if (estudianteAux) {
														flag2 = false;
														system("cls");
														matricula::historialAcademicoEstudiante(estudianteAux);
														system("pause");
													}
													else {
														cout << "ERROR: Id incorrecto" << endl;
													}
												} while (flag2 == true);


											}
											else {
												cout << "Error : codigo equivocado" << endl;

											}
										} while (flag1 == true);


									}
									else {
										estudiante* estudianteAux = exepcionCambioTipo::cambiarEstudiante(aux);
										system("cls");
										matricula::historialAcademicoEstudiante(estudianteAux);
										system("pause");
									}

								}
									  break;
								};
							} while (opcion5 != 4);
						}
						else {
							cout << "PROHIBIDO EL INGRESO PARA  " << aux->getrolUsu() << endl;
							Sleep(1000);
						}

					}
						  break;
					case 5: {
						if (aux->getIndentificador() == 1 || aux->getIndentificador() == 4) {
							int opcion6;
							do {
								system("cls");
								cout << "-----------------------------------------------------------------------" << endl;
								cout << '\t' << "1- Ingreso de notas" << endl;
								cout << '\t' << "2- Visualizar notas" << endl;
								cout << '\t' << "3- Volver al menu principal " << endl << endl;
								cout << "-----------------------------------------------------------------------" << endl;
								exepcionValor e;
								opcion6 = e.validar(1, 6);

								system("cls");
								switch (opcion6) {
								case 1: {
										string iD, codigoCarrera;
										int pos1;
										bool flag1 = true;
										bool flag2 = true;
										if (aux->getIndentificador() == 1) {
											system("cls");
											cout << uni->mostarEscuelas();
											cout << '\t' << "DIGITE EL NUMERO DE LA ESCUELA DONDE QUIERE MATRICULAR EL CURSO" << endl;
											exepcionValor exepcion1;
											pos1 = exepcion1.validar(1, uni->getCantEscuelas());
											escuela* escuelaAux = uni->recuperarEscuelaPosicion(pos1);
											do {
												system("cls");
												cout << escuelaAux->mostrarCarreras();
												cout << endl << endl;
												cout << "INGRESE EL CODIGO DE LA CARRERA "; cin >> codigoCarrera;
												carrera* carreraAux = escuelaAux->getTodasCarrerasEscuela()->buscarPorString(codigoCarrera);
												if (carreraAux) {
													flag1 = false;
													do {
														system("cls");
														cout << carreraAux->mostrarProfesores();
														cout << "Ingrese el ID del profesor "; cin >> iD;
														profesor* profesorAux = carreraAux->getTodosProfesores()->buscarPorString(iD);
														if (profesorAux) {
															flag2 = false;
															system("cls");


															string periocidad, nrc;
															int año, nota;
															ciclo* cicloAux = NULL;
															bool bandera1 = true;
															do {
																system("cls");
																cout << "----------------------INGRESAR NOTAS------------------------" << endl;
																cout << uni->mostrarCiclos();
																cout << endl << endl;
																cout << '\t' << "ESCOJA EN CUAL CICLO " << endl;
																cout << '\t' << "INGRESE LA EL PERIODO (I,II,III)...."; cin >> periocidad;
																cout << '\t' << "INGRESE EL ANNIO DEL CICLO... "; cin >> año;
																cicloAux = uni->buscarCicloEspecifico(periocidad, año);
																if (cicloAux) {
																	bandera1 = false;
																	system("cls");
																	cout << profesorAux->mostrarGruposEspecificos(año, periocidad);
																	cout << "INGRESE EL NRC DEL GRUPO "; cin >> nrc;
																	grupo* grupoAux = profesorAux->getTodosGruposAsigandos()->buscarPorString(nrc);
																	system("cls");
																	cout << grupoAux->mostrarListadoEstudiantes();

																	string codigoCurso = grupoAux->getCursoAsociado()->getCodigoCurso();

																	int cant = grupoAux->todosEstudiantes()->getCant();
																	for (int i = 0; i < cant; i++) {
																		estudiante* estudianteAux = grupoAux->todosEstudiantes()->recuperarElementoPorLugar(i + 1);


																		curso* cursoAux = estudianteAux->getTodosCursosMatriculados()->buscarPorString(codigoCurso);

																		cout << "Ingrese la calificacion del estudiante n." << i + 1 << ": "; cin >> nota;
																		cursoAux->setNotaFinal(nota);
																		estudianteAux->getHistorial()->agregarCursoAprobado(cursoAux);




																	}
																	system("cls");
																	cout << "Todas las notas fueron ingresadas correctamente !" << endl;
																	system("pause");

																}
																else {
																	cout << "ERROR: CICLO INCORRECTO" << endl;
																	Sleep(1000);
																}
															} while (bandera1 == true);
															system("pause");
														}
														else {
															cout << "ERROR: Id incorrecto" << endl;
														}
													} while (flag2 == true);


												}
												else {
													cout << "Error : codigo equivocado" << endl;

												}
											} while (flag1 == true);




										}
										else {

										profesor* profesorAux = exepcionCambioTipo::cambiarProfesor(aux);
										string periocidad, nrc;
										int año, nota;
										ciclo* cicloAux = NULL;
										bool bandera1 = true;
										do {
											system("cls");
											cout << "----------------------INGRESAR NOTAS------------------------" << endl;
											cout << uni->mostrarCiclos();
											cout << endl << endl;
											cout << '\t' << "ESCOJA EN CUAL CICLO " << endl;
											cout << '\t' << "INGRESE LA EL PERIODO (I,II,III)...."; cin >> periocidad;
											cout << '\t' << "INGRESE EL ANNIO DEL CICLO... "; cin >> año;
											cicloAux = uni->buscarCicloEspecifico(periocidad, año);
											if (cicloAux) {
												bandera1 = false;
												system("cls");
												cout << profesorAux->mostrarGruposEspecificos(año, periocidad);
												cout << "INGRESE EL NRC DEL GRUPO "; cin >> nrc;
												grupo* grupoAux = profesorAux->getTodosGruposAsigandos()->buscarPorString(nrc);
												system("cls");
												cout << grupoAux->mostrarListadoEstudiantes();

												string codigoCurso = grupoAux->getCursoAsociado()->getCodigoCurso();

												int cant = grupoAux->todosEstudiantes()->getCant();
												for (int i = 0; i < cant; i++) {
													estudiante* estudianteAux = grupoAux->todosEstudiantes()->recuperarElementoPorLugar(i + 1);


													curso* cursoAux = estudianteAux->getTodosCursosMatriculados()->buscarPorString(codigoCurso);

													cout << "Ingrese la calificacion del estudiante n." << i + 1 << ": "; cin >> nota;
													cursoAux->setNotaFinal(nota);
													estudianteAux->getHistorial()->agregarCursoAprobado(cursoAux);




												}
												system("cls");
												cout << "Todas las notas fueron ingresadas correctamente !" << endl;
												system("pause");

											}
											else {
												cout << "ERROR: CICLO INCORRECTO" << endl;
												Sleep(1000);
											}
										} while (bandera1 == true);


									}

								}
									  break;
								case 2: {
									system("pause");

								}
									  break;
								};
							} while (opcion6 != 3);
						}
						else {
							cout << "PROHIBIDO EL INGRESO PARA  " << aux->getrolUsu() << endl;
							Sleep(1000);
						}
					}
						  break;
					
						 

					};


				} while (opcionPricipal != 6);
			}
			else
			{
				system("cls");
				cout <<'\t'<<"ERROR: USUARIO INVALIDO " << endl;

			}

		}
			  break;
		case 2: {
			system("cls");
			cout << "--------------GRACIAS-------------" << endl;
		}

		}


	} while (opcionMenuInicio != 2);
	
	
	

	
	
	
	
	






	system("pause");
	return 0;
}
