#include "ciclo.h"
ciclo::ciclo(int anno, string perio, fecha* inicio, fecha* finall){
	año = anno;
	cicloNombre = "ciclo";
	periocidad = perio;
	fechaInicio = inicio;
	fechaFinal = finall;
}
ciclo::~ciclo(){}


string ciclo::toString(){
	stringstream s;
	s <<'\t'<< cicloNombre << '\t' << periocidad << '\t' << fechaInicio << '\t' << fechaFinal << endl;
	return s.str();
}

int ciclo::getAnio()
{
	return año;
}

string ciclo::getPeriocidad()
{
	return periocidad;
}

ostream& operator <<(ostream& out, const ciclo& p2) {
	out << p2.periocidad << "-" << p2.año << '\t' << p2.cicloNombre << '\t' << p2.fechaInicio->getDia() << "-" << p2.fechaInicio->getMes() << "-" << p2.fechaInicio->getAnnio() << '\t' << p2.fechaFinal->getDia() << "-" << p2.fechaFinal->getMes() << "-" << p2.fechaFinal->getAnnio() << endl;
	return out;
}