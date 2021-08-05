#include "historialAcademico.h"
historialAcademico::historialAcademico(estudiante* ew) {
	e = ew;
	listaCursos = new lista<curso>;
}
historialAcademico::~historialAcademico() {

}

//metodos de la lista
void historialAcademico::agregarCursoAprobado(curso* a){
	listaCursos->agregarObj(a);

}
//
curso* historialAcademico::recuperarCursoAprobado(int pos){
	return listaCursos->recuperarElementoPorLugar(pos);
}
//
string historialAcademico::mostrarCursosAprobados(){
	stringstream s;
	s <<"------------------CURSOS APROBADOS DE " << e->getnombreUsu() <<"-------"<< endl;
	s << listaCursos->toStringLista();
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}
//
lista<curso>* historialAcademico::getTodosCursoAprobados(){
	return listaCursos;
}
//
curso* historialAcademico::buscarCursoEspecifico(string codigo){
	curso* aux = NULL;
	int contador = 0;

	listaCursos->iniciarlizarActual();
	while (contador < listaCursos->getCant()) {
		contador++;
		aux = listaCursos->getDato();
		if (aux->getCodigoCurso() == codigo) {
			return aux;

		}
		listaCursos->siguienteNodo();
	}
	return NULL;
}

bool historialAcademico::verificarMatriculado(string nombreCurso)
{
	if (listaCursos->getCant() != 0) {

		curso* cursoAux = NULL;
		listaCursos->iniciarlizarActual();
		int contador = 0;
		while (contador < listaCursos->getCant()) {
			contador++;
			cursoAux = listaCursos->getDato();
			if (cursoAux->getNombreCurso() == nombreCurso) {
				if (cursoAux->getResultadoFinal() == true) { //si esta aprobado
					return true;
				}


			}
			listaCursos->siguienteNodo();
		}
		return false; // no esta aprobado
	}
	return false; //si la lista esta vacia

}

bool historialAcademico::verificarRequisitos(lista<curso>* requisitos)
{


	bool bandera = false;
	lista<curso>* aprobados = cursosAprobados();
	if (aprobados != NULL) {

		
		int contador1 = 0;
		int contador2 = 0;
		curso* cursoAprobado = NULL;

		requisitos->iniciarlizarActual();
		while (contador1 < requisitos->getCant()) {
			bandera = false;
			contador1++;
			curso* cursoRequisitos = requisitos->getDato();
			//
			 contador2 = 0;
			 cursoAprobado = NULL;
			 aprobados->iniciarlizarActual();
			 while (contador2 < aprobados->getCant()) {
				 contador2++;
				 cursoAprobado = aprobados->getDato();

				 if (cursoRequisitos->getNombreCurso() == cursoAprobado->getNombreCurso()) {
					 bandera = true;
					 
				 }
				 aprobados->siguienteNodo();
			 }
			 if (bandera == false) {
				 return false;
			 }

			 requisitos->siguienteNodo();
		}

	}
	else {
		return false;
	}
	return true; // me deja matricular
}

lista<curso>* historialAcademico::cursosAprobados()
{
		lista<curso>* nuevaAprobados = NULL;
		int contador = 0;
		curso* cursoAux = NULL;
		listaCursos->iniciarlizarActual();

	if (listaCursos->getCant() != 0) {

		nuevaAprobados = new lista<curso>;
		while (contador < listaCursos->getCant()) {
			contador++;
			cursoAux = listaCursos->getDato();
			if (cursoAux->getResultadoFinal() == true) {
				nuevaAprobados->agregarObj(cursoAux);
			}
			listaCursos->siguienteNodo();
		}
	}
	return nuevaAprobados;
}

string historialAcademico::hitorialEspecial()
{
	stringstream s;
	s << "---------------------------------HISTORIAL ACADEMICO---------------------------" << endl<<endl;
	s << "Carrera: " << e->getProfesion()->getNombreCarrera() << endl;
	s << "Estudiante: " << e->getnombreUsu() << endl << endl;
	s << "CODIGO" << '\t' << "NOMBRE" <<'\t'<<'\t'<<"CREDITOS"<< '\t' << "NOTA FINAL" << '\t' << "CONDICION" << endl;
	curso* cursoAux = NULL;
	int contador = 0;
	listaCursos->iniciarlizarActual();
	while (contador < listaCursos->getCant()) {
		contador++;
		cursoAux = listaCursos->getDato();
		s << cursoAux->getCodigoCurso() << '\t' << cursoAux->getNombreCurso()<<'\t'<<cursoAux->getCreditos()<<'\t'<<'\t' << cursoAux->getNota()<<'\t'<<'\t';
		(cursoAux->getResultadoFinal()) ? s << "APROBADO" <<endl: s << "REPROBADO"<<endl;
		listaCursos->siguienteNodo();
	}
	return s.str();
}
