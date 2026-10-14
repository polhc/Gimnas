#include <iostream>
#include <string>
using namespace std;

class Tarifa {
private:
	double preuMensual;
	string nomTarifa;
public:
	Tarifa() {
		preuMensual = 10;
		nomTarifa = "tarifa 1";
	}
	double preu_mensual() {
		return preuMensual;
	}
};

class Soci {
protected:
	string nom;
	int idSoci;
	Tarifa tarifa1;
public: 
	Soci() {
		nom = "soci1";
		idSoci = 10;
	}
	double calcular_quota() {
		return tarifa1.preu_mensual();
	}
};

class SociVIP: public Soci {
private:
	double descompteEntrenador;
public:
	SociVIP(string n, int id, Tarifa tarifa_1, double descompte) {
		nom = n;
		idSoci = id;
		tarifa1 = tarifa_1;
		descompteEntrenador = descompte;
	}
	double calcular_quota() {
		return tarifa1.preu_mensual() - descompteEntrenador;
	}
};

int main() {
	Soci soci_1;
	cout << "Quota soci normal: " << soci_1.calcular_quota() << endl;

	Tarifa tarifa_1;
	SociVIP soci_2("Ana", 20, tarifa_1, 3.0);
	cout << "Quota soci VIP: " << soci_2.calcular_quota() << endl;
}