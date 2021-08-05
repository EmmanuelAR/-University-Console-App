#include "escuela.h"
escuela::escuela(string nom) {
	nombre = nom;
	 listaCarrerasDeEscuela = new lista<carrera>;
}
escuela::~escuela(){}

string escuela::toString(){
	stringstream s;
	s << '\t' << nombre << endl;
	return s.str();
}

string escuela::getNombreEscuela()
{
	return nombre;
}

ostream& operator <<(ostream& out, const escuela& p2) {
	out << p2.nombre<< endl;
	return out;
}

void  escuela::agregarCarrerasPro(carrera* a){
	listaCarrerasDeEscuela->agregarObj(a);
}
string escuela::mostrarCarreras(){
	stringstream s;
	s <<"-----------------CARRERAS DE LA ESCUELA DE "<<nombre <<"-------------"<< endl<<endl;
	s << '\t' << "CODIGO " << '\t' << "NOMBRE" << '\t'<<'\t' << "GRADO" << '\t'<<'\t' << "FACULTAD" << endl;
	s << listaCarrerasDeEscuela->toStringLista();
	s << "-----------------------------------------------------------------------" << endl;
	return s.str();
}

carrera* escuela::recuperarCarreraPro(int pos) {
	return listaCarrerasDeEscuela->recuperarElementoPorLugar(pos);
}

int escuela::getCantCarreras()
{
	return listaCarrerasDeEscuela->getCant();
}

lista<carrera>* escuela::getTodasCarrerasEscuela()
{
	return listaCarrerasDeEscuela;
}
