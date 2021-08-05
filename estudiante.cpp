#include"estudiante.h"
#include"historialAcademico.h"
estudiante::estudiante(string id, string nom, string cla, string rol,int _telefono): usuario(id, nom, cla, rol) {
	profescion = NULL;
	bloque = new lista<grupo>;
	historialNotas = new historialAcademico(this);
	identificador = 3;
	telefono = _telefono;
	cursosMatriculados = new lista<curso>;

}
estudiante::~estudiante() {

}


ostream& operator <<(ostream& out, const estudiante& p2) {
	out << p2.idUsu << '\t'<<p2.nombreUsu<<endl;
	return out;
}

void estudiante::agregarGrupoAlBloque(grupo* a){
	bloque->agregarObj(a);
}



string estudiante::retornarGruposEspecificos(int año, string periocidad) {
	stringstream s;
	s << "-----------------------------------------------------------------------" << endl;
	s << "-----------------------IMFORME DE MATRICULA----------------------------" << endl<<endl;
	s << "Carrera: " << profescion->getNombreCarrera() << endl;
	s << "Estudiante: " << nombreUsu << endl << endl;
	s << "NRC" << '\t' << "NUMERO" << '\t' << "CURSO ASOCIADO" << '\t' << '\t' << "PROFESOR" << '\t' << "CUPO" << '\t' << "CANT" << '\t' << "HORARIO" << endl;
	grupo* grupoAux = NULL;
	int contador = 0;
	bloque->iniciarlizarActual();
	while (contador < bloque->getCant()) {
		contador++;

		grupoAux = bloque->getDato();

		if (grupoAux->getCursoAsociado()->getCicloAsociado()->getAnio() == año && grupoAux->getCursoAsociado()->getCicloAsociado()->getPeriocidad() == periocidad) {
			
			s  << grupoAux->getNrc() << '\t' << grupoAux->getNumeroGrupo() << '\t' << grupoAux->getCursoCodigo() << "  " << grupoAux->getNombreCurso() << '\t' << grupoAux->getNombreProfesor() << '\t' << '\t' << grupoAux->getCupo() << '\t' << grupoAux->getCantidad() << '\t' << grupoAux->getHorario() << endl;
		}
		bloque->siguienteNodo();

	}
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}




grupo* estudiante::recuperarGrupoPro(int pos){
	return bloque->recuperarElementoPorLugar(pos);
}

void estudiante::agregarCursoMatricula(curso* a)
{

	cursosMatriculados->agregarObj(a);
}

string estudiante::mostrarListadoCursoMatriculados()
{
	stringstream s;
	s << '\t' << "LISTA DE CURSOS DE " << nombreUsu << endl;
	s << cursosMatriculados->toStringLista();
	return s.str();
	
}

historialAcademico* estudiante::getHistorial()
{
	return historialNotas;
}

lista<curso>* estudiante::getTodosCursosMatriculados()
{
	return cursosMatriculados;
}



void estudiante::setProfesion(carrera* a){
	profescion = a;
}
carrera* estudiante::getProfesion(){
	return profescion;
}

int estudiante::getTelefono()
{
	return telefono;
}

bool estudiante::verificarGrupoYaMatriculado(string _nrc)
{
	grupo* grupoAux = NULL;
	grupoAux = bloque->buscarPorString(_nrc);
	if (grupoAux) {
		return true;
	}
	return false;
}


