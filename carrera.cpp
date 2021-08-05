#include "carrera.h"
carrera::carrera(string cod, string nom, string grad, string facu) {
	codigoCarre = cod;
	nombreCarre = nom;
	grado = grad;
	facultad = facu;
	estado = "INACTIVO";
	listaEstudiantesDeCarrera = new lista<estudiante>; 
	listaProfesoresDeCarrera = new lista<profesor>;
	planDeEstudios = new lista<curso>;
	listaGruposMatricula = new lista<grupo>;
}
carrera::~carrera() {

}
string carrera::toString() {
	stringstream s;
	
	s << '\t' << codigoCarre << '\t' << nombreCarre << '\t' << grado << '\t' << facultad << '\t' << estado << endl;
	return s.str();
}



string carrera::getCodigoCarrera()
{
	return codigoCarre;
}

string carrera::getNombreCarrera()
{
	return nombreCarre;
}

ostream& operator <<(ostream& out, const carrera& p2) {
	 
	out << p2.codigoCarre<<'\t'<< p2.nombreCarre<<'\t'<<p2.grado << '\t' << p2.facultad<<endl;
	return out;
}




void carrera::agregarEstudinatesPro(estudiante* a) {
	listaEstudiantesDeCarrera->agregarObj(a);
}


string carrera::mostrarEstudiantesEmpadronados() {
	stringstream s;
	s << '\t' << "ESTUDIANTES EMPADRONADOS EN  "<< nombreCarre << endl;
	s << listaEstudiantesDeCarrera->toStringLista();
	return s.str();
}
estudiante* carrera::recuperarEstuadintePro(int pos) {
	return listaEstudiantesDeCarrera->recuperarElementoPorLugar(pos);
}

void carrera::agregarProfesorPro(profesor* a) {
	listaProfesoresDeCarrera->agregarObj(a);
}
string carrera::mostrarProfesores() {
	stringstream s;
	s << '\t' << "PROFESORES EMPADRONADOS EN" << nombreCarre << endl;
	s << listaProfesoresDeCarrera->toStringLista();
	return s.str();
}
profesor* carrera::recuperarProfesorPro(int pos) {
	return listaProfesoresDeCarrera->recuperarElementoPorLugar(pos);
}

void carrera::agregarCursoPlan(curso* a) {
	planDeEstudios->agregarObj(a);
}
string carrera::mostrarPlanEstudios(){
	stringstream s;
	s << '\t' << "PLAN DE ESTUDIOS DE " << nombreCarre << endl;
	s << planDeEstudios->toStringLista();
	return s.str();
}
curso* carrera::recuperarCursoPro(int pos){
	return planDeEstudios->recuperarElementoPorLugar(pos);
}



bool carrera::operator==(string& a) {
	return (this->codigoCarre == a);
}


string carrera::mostrarPlanEstudiosEspecial(){
	stringstream s;
	s << '\t' <<'\t'<<'\t'<< "PLAN DE ESTUDIOS DE " << nombreCarre << endl << endl;
	s << '\t' <<'\t'<< "CODIGO" << '\t'<<'\t' << "NOMBRE" << '\t'<<'\t' << "CREDITOS" << '\t'<<'\t' << "REQUISITOS" << endl;
	planDeEstudios->iniciarlizarActual();
	int contador = 0;
	curso* cursoAux = NULL;
	while (contador < planDeEstudios->getCant()) {
		contador++;
		cursoAux = planDeEstudios->getDato();

		s << cursoAux->cursoConRequisitos()<<endl;
		planDeEstudios->siguienteNodo();
	}
	return s.str();
}

lista<curso>* carrera::getTodosCursos()
{
	return planDeEstudios;
}

lista<profesor>* carrera::getTodosProfesores()
{
	return listaProfesoresDeCarrera;
}

lista<grupo>* carrera::getTodosgrupo()
{
	return listaGruposMatricula;
}

lista<estudiante>* carrera::getTodosEstudiantes()
{
	return listaEstudiantesDeCarrera ;
}

string carrera::retornarCursoEspecificos(int año, string periocidad)
{
	stringstream s;
	s << "-----------------------------------------------------------------------" << endl;
	s << '\t' << "CODIGO" << '\t' << "NOMBRE CURSO" << '\t'<<'\t' << "CANT GRUPOS" << endl;
	curso* cursoAux = NULL;
	int contador = 0;
	planDeEstudios->iniciarlizarActual();
	while (contador < planDeEstudios->getCant()) {
		contador++;

		cursoAux = planDeEstudios->getDato();

		if (cursoAux->getCicloAsociado()->getAnio() == año && cursoAux->getCicloAsociado()->getPeriocidad() == periocidad) {
			s <<'\t'<< cursoAux->getCodigoCurso()   << '\t' << cursoAux->getNombreCurso() << '\t' << cursoAux->getCantGrupos() << endl;
		}
		planDeEstudios->siguienteNodo();

	}
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}

void carrera::agregarGrupoMatricula(grupo* a) {

	listaGruposMatricula->agregarObj(a);

}
string carrera::mostrarGruposMatricula() {
	stringstream s;
	s << listaGruposMatricula->toStringLista();
	return s.str();
}
grupo* carrera::recuperarGrupoPro(int pos) {
	return listaGruposMatricula->recuperarElementoPorLugar(pos);
}


string carrera::retornarGruposEspecificos(int año, string periocidad){
	stringstream s;
	s << "-----------------------------------------------------------------------" << endl;
	s << '\t' << "NRC" << '\t' << "NUMERO" << '\t' << "CURSO ASOCIADO" << '\t' << '\t' << "PROFESOR" << '\t' << "CUPO" << '\t' << "CANT" << '\t' << "HORARIO" << endl;
	grupo* grupoAux = NULL;
	int contador = 0;
	listaGruposMatricula->iniciarlizarActual();
	while (contador < listaGruposMatricula->getCant()) {
		contador++;

		grupoAux = listaGruposMatricula->getDato();

		if (grupoAux->getCursoAsociado()->getCicloAsociado()->getAnio() == año && grupoAux->getCursoAsociado()->getCicloAsociado()->getPeriocidad() == periocidad) {
			
			s << '\t' << grupoAux->getNrc()<<'\t'<<grupoAux->getNumeroGrupo()<<'\t'<<grupoAux->getCursoCodigo()<<"  "<<grupoAux->getNombreCurso()<<'\t'<<grupoAux->getNombreProfesor()<<'\t'<<'\t'<<grupoAux->getCupo()<<'\t'<<grupoAux->getCantidad()<<'\t'<<grupoAux->getHorario()<< endl;
		}
		listaGruposMatricula->siguienteNodo();

	}
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}


