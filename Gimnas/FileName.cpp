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
		nomTarifa = "tarifa_1";
	}
	double mostrarPreuMensual() const {
		return preuMensual; }
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
	double calcularQuota() const {
		return tarifa1.mostrarPreuMensual();
	}
};

class SociVIP : public Soci {
private:
	double descompteEntrenador;
public:
	SociVIP(string n, int id, Tarifa tarifa, double descompte) {
		nom = n;
		idSoci = id;
		tarifa1 = tarifa;
		descompteEntrenador = descompte;
	}
	double calcularQuota() const  {
		return tarifa1.mostrarPreuMensual() - descompteEntrenador;
	}
};

int main() {
	Soci soci_1;
	cout << "Quota soci normal: " << soci_1.calcularQuota() << endl;

	Tarifa tarifa_1;
	SociVIP soci_2("Ana", 20, tarifa_1, 3.0);
	cout << "Quota soci VIP: " << soci_2.calcularQuota() << endl;
}