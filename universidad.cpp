#include "universidad.h"
universidad::universidad() {
	TodosUsuarios = new lista<usuario>;
	escuelasGeneral = new lista<escuela>;
	//
	estudiantesGeneral = new lista<estudiante>;
	profesorGeneral = new lista<profesor>;
	ciclosUniversidad = new lista<ciclo>;
	mallaCurricular = new lista<curso>;

}
universidad::~universidad(){
}

//metodos de las listas
//agregar
void universidad::agregarUsuariosPro(usuario* a){
	TodosUsuarios->agregarObj(a);
}
void universidad::agregarEscuelaPro(escuela* a) {
	escuelasGeneral->agregarObj(a);
}
//mostrar
string universidad::mostrarUsuarios(){
	stringstream s;
	s <<"-----------------LISTA DE USUARIOS DEL SISTEMA----------------------" << endl;
	s <<'\t'<< "ID"<< '\t'<<'\t' <<"NOMBRE" << '\t' << "CLAVE" << '\t'<<'\t' << "ROL" << endl;
	s << TodosUsuarios->toStringLista();
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}
string universidad::mostarEscuelas(){
	stringstream s;
	s <<"---------------------LISTA DE ESCUELAS DEL SISTEMA----------------------" << endl<<endl;
	s << escuelasGeneral->toStringLista();
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}

usuario* universidad::recuperarUsuarioPosicion(int pos) {
	return TodosUsuarios->recuperarElementoPorLugar(pos);
}
escuela* universidad::recuperarEscuelaPosicion(int pos) {
	return escuelasGeneral->recuperarElementoPorLugar(pos);
}

void universidad::agregarEstudiantesGeneral(estudiante* e){
	estudiantesGeneral->agregarObj(e);
}
void universidad::agregarProfesorGeneral(profesor* e){
	profesorGeneral->agregarObj(e);

}
void universidad::agregarCursoMalla(curso* e){
	mallaCurricular->agregarObj(e);
}
void universidad::agregarCiclo(ciclo* e){
	ciclosUniversidad->agregarObj(e);
}

estudiante* universidad::recuperarEstudiantePosicion(int pos){
	return estudiantesGeneral->recuperarElementoPorLugar(pos);
}
profesor* universidad::recuperarProfesorPosicion(int pos){
	return profesorGeneral->recuperarElementoPorLugar(pos);
}
ciclo* universidad::recuperarCicloPosicion(int pos){
	return ciclosUniversidad->recuperarElementoPorLugar(pos);
}

curso* universidad::recuperarCursoDeMallaPosicion(int pos) {
	return mallaCurricular->recuperarElementoPorLugar(pos);
}

string universidad::mostarEstudiantesGeneral() {
	stringstream s;
	s << '\t' << "------LISTA GENERAL DE ESTUDIANTES DE LA UNIVERSIDAD -------" << endl;
	s << estudiantesGeneral->toStringLista();
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}
string universidad::mostarProfesoresGeneral() {
	stringstream s;
	s << '\t' << "-----LISTA GENERAL DE PROFESORES DE LA UNIVERSIDAD--------" << endl;
	s << profesorGeneral->toStringLista();
	return s.str();
}
string universidad::mostarMalla() {
	stringstream s;
	s << '\t' << "----MALLA CURRICULAR-------" << endl;
	s << mallaCurricular->toStringLista();
	return s.str();
}
string universidad::mostrarCiclos() {
	stringstream s;
	s <<"---------------------LISTA DE CICLOS LA UNIVERSIDAD---------------------" << endl<<endl;
	s << '\t' << "CODIGO" << '\t' << "NOMBRE" << '\t' << "FECHA INICIO" << '\t' << "FECHA FINAL" << endl;
	s << ciclosUniversidad->toStringLista();
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}

int universidad::getCantUsuario()
{
	return TodosUsuarios->getCant();
}

int universidad::getCantEscuelas()
{
	return escuelasGeneral->getCant();
}

int universidad::getCantCiclos()
{
	return ciclosUniversidad->getCant();
}

lista<usuario>* universidad::getTodosUsuarios()
{
	return TodosUsuarios;
}

lista<escuela>* universidad::getTodasEscuelas()
{
	return escuelasGeneral;
}

usuario* universidad::buscarUsuarioEspecifico(string id, string clave){
	usuario* aux = NULL;
	int contador = 0;

	TodosUsuarios->iniciarlizarActual();
	while (contador < TodosUsuarios->getCant()) {
		contador++;
		aux = TodosUsuarios->getDato();
		if (aux->getidUsu() == id && aux->getclaveUsu() == clave) {
			return aux;

		}
		TodosUsuarios->siguienteNodo();
	}
	return NULL;
}

ciclo* universidad::buscarCicloEspecifico(string periocidad, int annio)
{
	ciclo* aux = NULL;
	int contador = 0;

	ciclosUniversidad->iniciarlizarActual();
	while (contador < ciclosUniversidad->getCant()) {
		contador++;
		aux = ciclosUniversidad->getDato();
		if (aux->getPeriocidad() == periocidad && aux->getAnio() == annio) {
			return aux;

		}
		ciclosUniversidad->siguienteNodo();
	}
	return NULL;
}

