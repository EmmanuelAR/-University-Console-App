#include"usuarios.h"
usuario::usuario(string id, string nom, string cla, string rol) {
	idUsu = id;
	nombreUsu = nom;
	claveUsu = cla;
	rolUsu = rol;
	estadoUsu = "ACTIVO";
	identificador = 0;
	
}
usuario::~usuario() {

}

string usuario::toStringGeneral() {
	stringstream s;
	s << '\t' << idUsu << '\t' << nombreUsu << '\t' << claveUsu << '\t' << rolUsu << endl;
	return s.str();
 }

string usuario::getidUsu() { return idUsu; }
string  usuario::getnombreUsu() { return nombreUsu; }
string  usuario::getclaveUsu() { return claveUsu; }
string  usuario::getrolUsu() { return rolUsu; }
string  usuario::getestadoUsu() { return estadoUsu; }

int usuario::getIndentificador()
{
	return identificador;
}

ostream& operator <<(ostream& out, const usuario& p2) {
	out << p2.idUsu << '\t' << p2.nombreUsu << '\t' << p2.claveUsu << '\t' << p2.rolUsu << endl;
	return out;
}

bool usuario::operator==(string& a){
	return (this->idUsu == a);
}
