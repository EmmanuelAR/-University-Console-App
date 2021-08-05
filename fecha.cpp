#include "fecha.h"

fecha::fecha(int _dia, int _mes, int _annio){
	dia = _dia;
	mes = _mes;
	annio = _annio;
}

fecha::~fecha()
{

}

int fecha::comparaFecha(fecha* fecha1, fecha* fecha2){
	if (fecha1->annio != fecha2->annio)
		return fecha1->annio - fecha2->annio;

	else if (fecha1->mes != fecha2->mes)
		return fecha1->mes - fecha2->mes;

	else return fecha1->dia - fecha2->dia;
}

int fecha::getDia()
{
	return dia;
}

int fecha::getMes()
{
	return mes;
}

int fecha::getAnnio()
{
	return annio;
}

ostream& operator <<(ostream& out, const fecha& p2) {
	out << p2.dia << "-" << p2.mes << "-" << p2.annio << endl;
	return out;
}