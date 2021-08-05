#include "grupo.h"
grupo::grupo( int cap, string dia, string Hinicio, string HFinal,curso* a){
	ncr = "";
	numeroGrupo = 0;
	profe = NULL;
	cursoAsociado = a;
	cupoDisponible = cap;
	dias = dia;
	horaIncio = Hinicio;
	horaFinal = HFinal;
	cupoOcupado = 0;
	estudiantesMatriculados = new lista<estudiante>;
	//
	horario = " ";
}
grupo::~grupo(){}
string grupo::toString() {
	stringstream s;
	s << '\t' << ncr << '\t' << numeroGrupo << '\t' << cupoDisponible << '\t' << cupoOcupado << '\t' << dias << '\t' << horaIncio << "-" << horaFinal << endl;
	return s.str();
}

ostream& operator <<(ostream& out, const grupo& p2) {
	out << p2.cursoAsociado->getCodigoCurso() << '\t' <<p2.cursoAsociado->getNombreCurso() << '\t' <<p2.ncr << '\t' << p2.numeroGrupo << '\t' <<p2.profe->getnombreUsu() << '\t'<<'\t' << p2.cupoDisponible << '\t' << p2.cupoOcupado << '\t' << p2.horario << endl;
	return out;
}

void grupo::setCurso( curso* a) {
	cursoAsociado = a;
}

string grupo::getCursoCodigo(){
	return cursoAsociado->getCodigoCurso();
}
string grupo::getNombreCurso(){
	return cursoAsociado->getNombreCurso();
}

curso* grupo::getCursoAsociado()
{
	return cursoAsociado;
}

void grupo::setProfesor(profesor* a)
{
	profe = a;
}

string grupo::getNombreProfesor() {
	return profe->getnombreUsu();
}

profesor* grupo::getProfesor()
{
	return profe;
}

void grupo::matricularEstuadinte(estudiante* a){
	if (cupoDisponible != 0) {
		estudiantesMatriculados->agregarObj(a);
		cupoOcupado++;
		cupoDisponible--;
	}
	//lanzar exepcion
}
string grupo::mostrarListadoEstudiantes(){
	stringstream s;
	s << "-----------------------------------------------------------------------" << endl;
	s << '\t' << "LISTADO DE ESTUDIANTES DEL CURSO " << cursoAsociado->getNombreCurso() << endl;
	s << "-----------------------------------------------------------------------" << endl;
	s << '\t' << "Grupo " << numeroGrupo << endl;
	s << '\t' << "NRC " << ncr << endl;
	s << "***********************************************************************" << endl;
	s << estudiantesMatriculados->toStringLista();
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}
estudiante* grupo::recuperarEstudiantePro(int ppos){
	return estudiantesMatriculados->recuperarElementoPorLugar(ppos);
}

void grupo::setHorario(string a)
{
	horario = a;
}

string grupo::getHorario()
{
	return horario;
}

void grupo::setNRC()
{

	static int b = 0;
	static int c = 0;
	static int d = 1;
	stringstream aux;
	aux  << b << c << d;
	ncr = aux.str();
	d++;
	if (d == 10) {
		d = 0;
		c++;
		if (c == 10) {
			c = 0;
			b++;
		}

		
	}


}

string grupo::getNrc()
{
	return ncr;
}

void grupo::setNumeroGrupo()
{
	static int a = 1;
	numeroGrupo = a;
	a++;
}

lista<estudiante>* grupo::todosEstudiantes()
{
	return estudiantesMatriculados;
}

int grupo::getNumeroGrupo()
{
	return numeroGrupo;
}

int grupo::getCupo()
{
	return cupoDisponible;
}

int grupo::getCantidad()
{
	return cupoOcupado;
}

bool grupo::operator==(string& a) {
	return (this->getNrc() == a);
}