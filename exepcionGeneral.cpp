#include "exepcionGeneral.h"

exepcionRango::exepcionRango(int minim, int max) {
	minimo = minim;
	maximo = max;
}


string exepcionRango::toString() const {
	stringstream s;
	s << "EL VALOR DEBE DE ESTAR ENTRE ";
	s << minimo << " y " << maximo;
	return s.str();
}

exepcionRangoInferior::exepcionRangoInferior(int min, int max, int valorr)
	: exepcionRango(min, max) {
	valor = valorr;
}

string exepcionRangoInferior::toString() const {
	stringstream s;
	s << "EL VALOR " << valor << "  QUE USTED DIJITO ES MENOR QUE EL MINIMO " << endl;
	s << exepcionRango::toString(); //llama  al del padre
	return s.str();
}
void exepcionRangoInferior::setValor(int val) {
	valor = val;
}


exepcionRangoSuperior::exepcionRangoSuperior(int min, int max, int valorr)
	: exepcionRango(min, max) {
	valor = valorr;
}

string exepcionRangoSuperior::toString() const {
	stringstream s;
	s << "EL VALOR " << valor << " QUE USTED DIJITO ES MAYOR QUE EL MAXIMO ADMITiDO " << endl;
	s << exepcionRango::toString(); //llama  al del padre
	return s.str();
}
void exepcionRangoSuperior::setValor(int val) {
	valor = val;
}

string exepcionValor::toString() const {
	return "EL VALOR DIJITADO NO ES UN NUMERO ENTERO ";
}

int exepcionValor::validar(int min, int max) {
	int r;
	bool finalizado = false;
	while (!finalizado)
	{
		try { //bloque intento
			cout << '\t' << "DIGITE UN NUMERO... ";
			 r = obtenerValor(min, max); // si no retorna nada manda a los cach
			finalizado = true;

		}
		catch (exepcionRango * e) {
			cout << e->toString() << endl;
		}
		catch (exepcionValor * v) {
			cout << "OCURRIO UN ERROR" << endl;
			cout << v->toString()<<endl;

		}
		if (!finalizado)
		{
			//limpiar variables 
			cin.clear();
			cin.ignore(255, '\n');

		}

	}
	return r;
}

int exepcionValor::obtenerValor(int min, int max) {
	//aqui lanzo las exepciones
	int x;
	//exepcionRango* ex;
	//exepcionValor* exx;
	if (cin >> x) { //el valor r es valido 
		if (x < min) {
		
			//throw  ex = new exepcionRangoInferior(MIN, max, x);
			throw new exepcionRangoInferior(min, max, x);
		}
		if (x > max) {

			//throw  ex = new exepcionRangoSuperior(MIN, max, x);
			throw new exepcionRangoSuperior(min, max, x);
		}
		return x;
	}
	else
	{
		throw  new exepcionValor();
	}
}

string exepcionValor::validarContra1(){
	bool finalizado = false;
	string contra = "";
	while (!finalizado){
		try {
			cout << "Ingrese la clave (1 MAYUSCULA, MINIMI 6 CARACTERES) ";
			contra = validarTamContra();
			finalizado = true;
		}
		catch (string contra) {
			cout << "FORMATO DE CONTRASEÑA INVALIDOA" << endl;
		}
		if (!finalizado) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return contra;
}


bool exepcionValor::Mayusculas(string palabra) {
	int contador = 0;
	for (int i = 0; i < palabra.size(); i++) {
		if (isupper(palabra[i])) {
			contador++;
		}
	}
	if (contador < 1) {
		return false;
	}
	else {
		return true;
	}
}



string exepcionValor::validarTamContra(){
	string contra = "";
	cin >> contra;
	if (contra.length() < 6 || Mayusculas(contra) == false) {
		throw contra;
	}
	else {
		return contra;
	}
}

estudiante* exepcionCambioTipo::cambiarEstudiante(usuario* a){
	estudiante* nuevoEstudiante = dynamic_cast <estudiante*>(a);
	if (nuevoEstudiante) {
		return nuevoEstudiante;
	}
	else
	{
		cout << "Transformacion invalida" << endl;
		return nullptr;
	}
}

profesor* exepcionCambioTipo::cambiarProfesor(usuario* a)
{
	profesor* nuevoProfesor = dynamic_cast <profesor*>(a);
	if (nuevoProfesor) {
		
		return nuevoProfesor;
	}
	else
	{
		cout << "Transformacion invalida" << endl;
		return nullptr;
	}
}
