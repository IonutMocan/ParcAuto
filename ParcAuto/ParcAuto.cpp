#include <iostream>
#include <string>

#define NR_LOCURI_PARC 100

using namespace std;

class Masina {
	int numarLocuri;
	int putere;
	string marca;
	string numarInmatriculare;
	string tipCarburant;
	string natura;
public:
	Masina() {};
	Masina(int, int, string, string, string, string);

	bool acelasiModel(Masina);

	int getNrLocuri() { return numarLocuri; };
	int getPutere() { return putere; };
	string getMarca() { return marca; };
	string getNrInmatriculare() { return numarInmatriculare; };
	string getTipCarburant() { return tipCarburant; };
	string getNatura() { return natura; };
};

Masina::Masina(int nrL, int p, string m, string nrI, string tipC, string n) :
	numarLocuri(nrL),
	putere(p),
	marca(m),
	numarInmatriculare(nrI),
	tipCarburant(tipC),
	natura(n)
{}

bool Masina::acelasiModel(Masina masina) {
	if (masina.getNrLocuri() == this->getNrLocuri()
		&& masina.getPutere() == this->getPutere()
		&& masina.getMarca() == this->getMarca()
		&& masina.getNrInmatriculare() != this->getNrInmatriculare()
		&& masina.getTipCarburant() == this->getTipCarburant()
		&& masina.getNatura() == this->getNatura()) {

		return true;
	}

	return false;
}

class Parc {
	int nrMasini;
	Masina masini[NR_LOCURI_PARC + 1];
public:
	Parc() { nrMasini = 0; };
	int gaseste(string);
	void intrare(Masina);
	void iesire(string);
	void inlocuire(string, Masina);
};

int Parc::gaseste(string nrI) {
	for (int i = 1; i <= nrMasini; i++) {
		if (nrI == masini[i].getNrInmatriculare()) {
			return i;
		}
	}

	return 0;
}

void Parc::intrare(Masina masina) {
	if (!this->gaseste(masina.getNrInmatriculare())) {
		if (nrMasini + 1 <= NR_LOCURI_PARC) {
			nrMasini++;
			masini[nrMasini] = masina;

			cout << "Masina \"" + masina.getNrInmatriculare() + "\" a fost adaugata.";
		}
		else {
			cout << "Parcul este plin.\n";
		}
	}
	else {
		cout << "masina este deja in parc.\n";
	}
}

void Parc::iesire(string nrI) {
	bool iesita = false;
	int indexMasina = this->gaseste(nrI);

	if (indexMasina) {
		for (int j = indexMasina + 1; j > 1 && j <= nrMasini; j++) {
			masini[j - 1] = masini[j];
		}

		iesita = true;
	}

	if (!iesita) {
		cout << "Masina \"" + nrI + "\" nu este in Parc.\n";
	}
	else {
		cout << "Masina \"" + nrI + "\" a fost extrasa.\n";

		nrMasini--;
	}
}

void Parc::inlocuire(string nrI, Masina masina) {
	bool exista = false;
	bool inlocuit = false;
	int indexMasina = this->gaseste(nrI);

	if (indexMasina) {
		exista = true;

		if (masina.acelasiModel(masini[indexMasina])) {
			masini[indexMasina] = masina;
			inlocuit = true;

			cout << "Masina \"" + nrI + "\" a fost inlocuita cu \""
				+ masina.getNrInmatriculare() + "\".\n";
		}
		else {
			cout << "Masina nu este de acelasi model.\n";
		}
	}

	if (!exista && !inlocuit) {
		cout << "Masina " + nrI + " nu este in Parc.\n";
	}
}

int main()
{
	Parc parc;
	string input;

	cout << "Parc de automobile\n";

	do {
		cout << "\nAlege numarul corespunzator comenzii dorite:\n";
		cout << "[1] Intrare masina\n";
		cout << "[2] Iesire masina\n";
		cout << "[3] Inlocuire masina\n";
		cout << "[0] Terminare program\n";

		cout << "Comanda: ";
		cin >> input;

		if (input == "1") {
			int numarLocuri;
			int putere;
			string marca;
			string numarInmatriculare;
			string tipCarburant;
			string natura;

			cout << "Introdu caracteristicile masinii\n";

			cout << "Numar de locuri: ";
			cin >> numarLocuri;
			cout << "Puterea: ";
			cin >> putere;
			cout << "Marca: ";
			cin >> marca;
			cout << "Numar de inmatriculare: ";
			cin >> numarInmatriculare;
			cout << "Tip de carburator: ";
			cin >> tipCarburant;
			cout << "Natura: ";
			cin >> natura;

			parc.intrare(Masina(numarLocuri, putere, marca, numarInmatriculare,
				tipCarburant, natura));
		}
		else if (input == "2") {
			string nrI;

			cout << "Introdu numarul de inmatriculare a masinii: ";
			cin >> nrI;

			parc.iesire(nrI);
		}
		else if (input == "3") {
			string nrI;

			cout << "Introdu numarul de inmatriculare a masinii: ";
			cin >> nrI;

			int numarLocuri;
			int putere;
			string marca;
			string numarInmatriculare;
			string tipCarburant;
			string natura;

			cout << "Introdu caracteristicile masinii\n";

			cout << "Numar de locuri: ";
			cin >> numarLocuri;
			cout << "Puterea: ";
			cin >> putere;
			cout << "Marca: ";
			cin >> marca;
			cout << "Numar de inmatriculare: ";
			cin >> numarInmatriculare;
			cout << "Tip de carburator: ";
			cin >> tipCarburant;
			cout << "Natura: ";
			cin >> natura;

			parc.inlocuire(nrI, Masina(numarLocuri, putere, marca, numarInmatriculare,
				tipCarburant, natura));
		}
	} while (input != "0");
}




