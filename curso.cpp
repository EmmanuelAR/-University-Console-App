#include "curso.h"
curso::curso( string nom, string tipo, int credi, int horas, string est,ciclo* a,carrera* d){
	codigoCurso = "";
	nombreCurso = nom;
	tipoCurso = tipo;
	creditos = credi;
	horasLectivas = horas;
	estado = est;
	notaFinal = 100;
	cicloElectivo = a;
	resuladoFinal = false;
	carreraAsociada = d;
	//
	requisitos = new lista<curso>;
	grupos = new lista<grupo>;
	
}

curso::~curso(){
}
string curso::toString() {
	stringstream s;
	s << '\t' << codigoCurso << '\t' << nombreCurso << '\t' << creditos << endl;
	return s.str();
}

ostream& operator <<(ostream& out, const curso& p2) {
	out << p2.codigoCurso << '\t' << p2.nombreCurso << '\t' << p2.creditos << endl;
	return out;
}

void curso::agregarRequistosPro(curso* a){
	requisitos->agregarObj(a);
}
string curso::mostrarRequisitosAsignados(){
	stringstream s;
	s << requisitos->toStringLista();
	return s.str();
}
curso* curso::recuperarRequisitoPro(int pos){
	return requisitos->recuperarElementoPorLugar(pos);
}
//
void curso::agregaGrupoPro(grupo* a){
	
	grupos->agregarObj(a);

}
string curso::mostrarGruposAsignados(){
	stringstream s;
	s <<"------------------LISTAS DE GRUPOS DEL CURSO " << nombreCurso <<"----------------------------------------"<< endl << endl;

	s << '\t' << "CURSO" << '\t'<<'\t'<<'\t'<<'\t'<< "NCR" << '\t' <<"GRUPO"<<'\t'<< "PROFESOR" << '\t' << "CUPO" << '\t' << "CANT" << '\t' << "HORARIO" << endl;
	s << grupos->toStringLista();
	s << "---------------------------------------------------------------------------------------------------------" << endl;
	return s.str();
}
grupo* curso::recuperarGrupoPro(int pos){
	return grupos->recuperarElementoPorLugar(pos);
}



string curso::getCodigoCurso() {
	return this->codigoCurso;
}
string curso::getNombreCurso() {
	return this->nombreCurso;
}

string curso::getTipo()
{
	return tipoCurso;
}

int curso::getCreditos()
{
	return creditos;
}

int curso::getHoras()
{
	return horasLectivas;
}

string curso::getEstado()
{
	return estado;
}

void curso::setCarreraAsociada(carrera* a)
{
	carreraAsociada = a;
}


carrera* curso::getCarreraAsociada()
{
	return carreraAsociada;
}

ciclo* curso::getCicloAsociado()
{
	return cicloElectivo;
}

void curso::setCodigo() {

	string periocidad, codigoCarrera;
	static int a = 0;
	static int b = 1;


	periocidad = cicloElectivo->getPeriocidad();
	codigoCarrera = carreraAsociada->getCodigoCarrera();
	char guion = '-';
	stringstream codigoFinal;
	codigoFinal << codigoCarrera << guion << periocidad << a << b;
	codigoCurso = codigoFinal.str();

	if (b == 10) {
		b = 0;
		a++;
	}
	b++;
}

string curso::mostarRequisitos(){
	stringstream s;
	curso* cursoAux = NULL;
	int contador = 0;
	requisitos->iniciarlizarActual();
	if (requisitos->getCant() == 0) {
		s << "INGRESO A LA CARRERA";
	}
	else {
		while (contador < requisitos->getCant() ) {
			contador++;
			cursoAux = requisitos->getDato();
			s << cursoAux->getCodigoCurso();
			if (contador >= 1) {
				s << ",";
			}
			

			requisitos->siguienteNodo();
		}

	}
	return s.str();
}

string curso::cursoConRequisitos()
{
	stringstream s;
	string _requisitos = mostarRequisitos();
	s <<'\t'<< '\t'<<this->codigoCurso << '\t'<<'\t' << this->nombreCurso << '\t'<<'\t' << this->creditos << '\t'<<'\t' << _requisitos << endl;
	return s.str();
}

lista<grupo>* curso::todosGrupos()
{
	return grupos;
}


bool curso::operator==(string& a) {
	return (this->codigoCurso == a);
}

int curso::getCantGrupos()
{
	return grupos->getCant();
}

void curso::setResultadoFinal(bool a)
{
	resuladoFinal = a;
}

bool curso::getResultadoFinal()
{
	return resuladoFinal;
}

void curso::setNotaFinal(int nota)
{
	if (nota >= 7) {
		notaFinal = nota;
		setResultadoFinal(true); //aprobado
	}
	if (nota < 6) {
		notaFinal = nota;
		setResultadoFinal(false); //reprobado
	}
}

lista<curso>* curso::getTodosRequisitos()
{
	return requisitos;
}

int curso::getNota()
{
	return notaFinal;
}

void curso::setCodigoCopia(string codigo)
{
	codigoCurso = codigo;
}
