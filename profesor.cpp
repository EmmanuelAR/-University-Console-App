#include "profesor.h"
profesor::profesor(string id, string nom, string cla, string rol,int celu,string grado) : usuario(id, nom, cla, rol) {
	telefono = celu;
	gradoAcademico = grado;
	gruposAsiginados = new lista<grupo>;
	identificador = 4;

}
profesor::~profesor() {

}

int profesor::getCelular()
{
	return telefono;
}

string profesor::getGradoAcademico()
{
	return gradoAcademico;
}


//string profesor::toStringPersonal() {
//	stringstream s;
//	s <<usuario::toStringGeneral()<< '\t' << idUsu << '\t' << nombreUsu << '\t' << gradoAcademico << '\t' << telefono << endl;
//	return s.str();
//}

ostream& operator <<(ostream& out, const profesor& p2) {
	out << p2.idUsu << '\t' << p2.nombreUsu << '\t' << p2.gradoAcademico << '\t' << p2.telefono << endl;
	return out;
}

//---METODOS DE LA LISTA--- 
void profesor::agregarGruposPro(grupo* a) {
	gruposAsiginados->agregarObj(a);
}
string profesor::mostrarGruposAsignados() {
	stringstream s;
	s << '\t' << "-----LISTA DE GRUPOS DEL PROFESOR " << nombreUsu <<"------"<< endl;
	s << gruposAsiginados->toStringLista();
	s << '\t' << "-------------------------------------------------------" << endl;
	return s.str();
}
grupo* profesor::recuperarGrupoPosicion(int pos) {
	return gruposAsiginados->recuperarElementoPorLugar(pos);
}

bool profesor::validarCreacionGrupo(string a)
{
	grupo* aux = NULL;
	int contador = 0;

	gruposAsiginados->iniciarlizarActual();
	while (contador < gruposAsiginados->getCant()) {
		contador++;
		aux = gruposAsiginados->getDato();
		if (aux->getHorario() == a) {
			return true;

		}
		gruposAsiginados->siguienteNodo();
	}
	return false;
}

string profesor::mostrarGruposEspecificos(int año, string periocidad)
{
	stringstream s;
	s << "-----------------------------------------------------------------------" << endl;
	s << '\t' << "NRC" << '\t' << "NUMERO" << '\t' << "CURSO ASOCIADO" << '\t' << '\t' << "PROFESOR" << '\t' << "CUPO" << '\t' << "CANT" << '\t' << "HORARIO" << endl;
	grupo* grupoAux = NULL;
	int contador = 0;
	gruposAsiginados->iniciarlizarActual();
	while (contador < gruposAsiginados->getCant()) {
		contador++;

		grupoAux = gruposAsiginados->getDato();

		if (grupoAux->getCursoAsociado()->getCicloAsociado()->getAnio() == año && grupoAux->getCursoAsociado()->getCicloAsociado()->getPeriocidad() == periocidad) {

			s << '\t' << grupoAux->getNrc() << '\t' << grupoAux->getNumeroGrupo() << '\t' << grupoAux->getCursoCodigo() << "  " << grupoAux->getNombreCurso() << '\t' << grupoAux->getNombreProfesor() << '\t' << '\t' << grupoAux->getCupo() << '\t' << grupoAux->getCantidad() << '\t' << grupoAux->getHorario() << endl;
		}
		gruposAsiginados->siguienteNodo();

	}
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}

lista<grupo>* profesor::getTodosGruposAsigandos()
{
	return gruposAsiginados;
}
