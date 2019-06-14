/*? Program treba da ima osnovnu klasu TerminDogadjaja i cetiri izvedene klase: SamoJednom, Dnevno, Nedeljno i Mesecno.
? Zakazivanje nekog dogadaja treba da sadrži tekstualni opis dogadaja, npr. "Ispit iz OOP", datum i vreme pocetka, mesto dogadaja i (opciono) trajanje dogadaja.
? Treba definisati virtuelnu funkciju nastupa(int godina, int mesec, int dan), koja ispituje da li zadanog datuma nastupa neki dogadaj; npr. za mesecne dogadaje, proverava da li neki od njih nastupa tog dana u mesecu.
Nakon toga, funkcija puni STL vektor TerminiDogadjaja nizom dogadaja koji nastupaju toga dana.
? Definisati funkciju noviDogadjaj() koja omogucava korisniku unos novog dogadaja tako što bira tip dogadaja (jednokratni, dnevni, nedeljni, mesecni) i unosi opis, datum i vreme pocetka, mesto i trajanje dogadaja.
? Definisati funkciju dogadjaji() koja omogucava korisniku da unese datum i dobije sortiran spisak dogadaja koji se dešavaju odredenog dana ili u periodu izmedu dva datuma.
? U funkciji main() kreirati po tri dogadaja iz svake kategorije za dva razlicita datuma, a nakon toga prikazati sortiran spisak svih dogadaja u periodu od jednog do drugog datuma (ukljucno)
. Sortiranje izvršiti stabilnim metodom sortiranja iz biblioteke STL.*/



#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
using namespace std;

class TerminDogadjaja {
public:
	string imeDogadjaja;
	string mestoDogadjaja;
	int godinaPocetka;
	int mesecPocetka;
	int danPocetka;


	vector <TerminDogadjaja> terminDogadjaja;
	TerminDogadjaja(string mestoDogadjaja, string imeDogadjaja, int godinaPocetka, int mesecPocetka, int danPocetka) {

		this->imeDogadjaja = imeDogadjaja;
		this->mestoDogadjaja = mestoDogadjaja;
		this->godinaPocetka = godinaPocetka;
		this->mesecPocetka = mesecPocetka;
		this->danPocetka = danPocetka;

	}
	TerminDogadjaja() {



	}





	virtual void nastupa(int godina, int mesec, int dan) {
		for (auto dogadjaj : terminDogadjaja) {

			if (dogadjaj.godinaPocetka == godina && dogadjaj.mesecPocetka == mesec && dogadjaj.danPocetka == dan) {
				cout << dogadjaj.imeDogadjaja << " [" << dogadjaj.mestoDogadjaja << " - " << dogadjaj.danPocetka << "." << dogadjaj.mesecPocetka << "." << dogadjaj.godinaPocetka << "]";
			}

		}

	}






};



static TerminDogadjaja* dogadjaj;



class SamoJednom :public TerminDogadjaja {
	using TerminDogadjaja::TerminDogadjaja;
public:

	SamoJednom(string mestoDogadjaja, string imeDogadjaja, int godinaPocetka, int mesecPocetka, int danPocetka) : TerminDogadjaja(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka) {
		TerminDogadjaja dogadjaj(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka);
		terminDogadjaja.push_back(dogadjaj);//Ubacuje dogadjaj sa odredjenjim datumom
		//sort(terminDogadjaja.begin(), terminDogadjaja.end());
	}


};
class Dnevno :public TerminDogadjaja {
	using TerminDogadjaja::TerminDogadjaja;
public:
	Dnevno(string mestoDogadjaja, string imeDogadjaja, int godinaPocetka, int mesecPocetka, int danPocetka) : TerminDogadjaja(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka) {
		int counter = 1;
		for (int i = 1; i <= 30; i++) {//ubacuje dogadjaj za svaki dan, sa obzirom da mesec ima 30 dana, dogadjaj je samo za taj mesec
			if (i >= 30) {
				counter++; i = 30;
			}
			TerminDogadjaja dogadjaj(mestoDogadjaja, imeDogadjaja, godinaPocetka, counter, i);
			terminDogadjaja.push_back(dogadjaj);
		}

		//	sort(terminDogadjaja.begin(), terminDogadjaja.end());

	}

};
class Nedeljno :public TerminDogadjaja {
	using TerminDogadjaja::TerminDogadjaja;
public:
	Nedeljno(string mestoDogadjaja, string imeDogadjaja, int godinaPocetka, int mesecPocetka, int danPocetka) : TerminDogadjaja(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka) {
		for (int i = 1; i <= 30; i++) {
			if (i % 7 == 0) { // ubacuje dogadjaj na svakih 7 dana
				TerminDogadjaja dogadjaj(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, i);
				terminDogadjaja.push_back(dogadjaj);
			}

		}
		//sort(terminDogadjaja.begin(), terminDogadjaja.end());


	}

};

class Mesecno :public TerminDogadjaja {
	using TerminDogadjaja::TerminDogadjaja;


public:
	Mesecno(string mestoDogadjaja, string imeDogadjaja, int godinaPocetka, int mesecPocetka, int danPocetka) : TerminDogadjaja(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka) {
		int counter = mesecPocetka;
		for (int i = 1; i <= 360; i++) {

			if (i == 30) { // ubacuje dogadjaj na svakih mesec dana sa obzirom da godina ima 360 dana a da mesec ima 30 dana, i vazi do kraja godine
				counter++;
				TerminDogadjaja dogadjaj(mestoDogadjaja, imeDogadjaja, godinaPocetka, counter, danPocetka);
				terminDogadjaja.push_back(dogadjaj);
			}
			else {
				break;
			}

		}
	}
};





vector<TerminDogadjaja> dogadjajiVector;
bool compare(TerminDogadjaja  d1, TerminDogadjaja  d2)//funkcija koja uporedjuje
{
	// All cases when true should be returned 
	if (d1.godinaPocetka < d2.godinaPocetka)
		return true;
	if (d1.godinaPocetka == d2.godinaPocetka && d1.mesecPocetka < d2.mesecPocetka)
		return true;
	if (d1.godinaPocetka == d2.godinaPocetka && d1.mesecPocetka == d2.mesecPocetka &&
		d1.danPocetka < d2.danPocetka)
		return true;

	// If none of the above cases satisfy, return false 
	return false;
}
void  dogadjaji() {
	sort(dogadjajiVector.begin(), dogadjajiVector.end(), compare);
	for (auto t = dogadjajiVector.begin(); t != dogadjajiVector.end(); ++t) {
		cout << t->imeDogadjaja << " [" << t->mestoDogadjaja << " - " << t->danPocetka << "." << t->mesecPocetka << "." << t->godinaPocetka << "]" << endl;
	}



}

void noviDogadjaj() {
	string mestoDogadjaja;
	string imeDogadjaja;
	int godinaPocetka;
	int mesecPocetka;
	int danPocetka;
	int tip;
	cout << "Unesite mesto dogadjaja";
	cin >> mestoDogadjaja;
	cout << "Unesite mesto imeDogadjaja";
	cin >> imeDogadjaja;
	cout << "Unesite godinaPocetka";
	cin >> godinaPocetka;
	cout << "Unesite mesto mesecPocetka";
	cin >> mesecPocetka;
	cout << "Unesite mesto danPocetka";
	cin >> danPocetka;
	cout << "Unesite tip dogadjaja 1.Mesecni 2.Jednokratni 3.Nedeljni 4.Dnevni";
	cin >> tip;

	switch (tip) {
	case 1:
		dogadjaj = new Mesecno(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka);
		break;
	case 2:
		dogadjaj = new SamoJednom(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka);
		break;
	case 3:
		dogadjaj = new Nedeljno(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka);
		break;
	case 4:
		dogadjaj = new Dnevno(mestoDogadjaja, imeDogadjaja, godinaPocetka, mesecPocetka, danPocetka);
		break;


	}

}




int main() {
	//ubacivanje vectora unutar klase TerminDogadjaja u dogadjajiVector

	dogadjaj = new Dnevno("Budjenje", "Beograd", 1, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new Dnevno("Idi na posao", "Beograd", 1, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new Dnevno("Vrati se kuci", "Beograd", 1, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());


	dogadjaj = new SamoJednom("Rodjendan", "Beograd", 19, 8, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new SamoJednom("Ispit", "Beograd", 19, 6, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new SamoJednom("Nova godina", "Beograd", 31, 12, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());

	dogadjaj = new Mesecno("Novi mesec", "Beograd", 1, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new Mesecno("Idi u kupovinu", "Beograd", 10, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new Mesecno("Idi u kupovinu", "Beograd", 21, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());

	dogadjaj = new Nedeljno("Nova nedelja", "Beograd", 1, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new Nedeljno("Vikend", "Beograd", 10, 1, 2019);

	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());
	dogadjaj = new Nedeljno("Sredi stan", "Beograd", 21, 1, 2019);
	dogadjajiVector.insert(dogadjajiVector.end(), dogadjaj->terminDogadjaja.begin(), dogadjaj->terminDogadjaja.end());





	bool kraj = false;


	while (true) {
		int opcija;

		//std::sort(sviDogadjaji.begin, sviDogadjaji.end);
		cout << "1.Prikazi dogadjaje 2. Dodaj dogadjaj  3.Proveri datum 4. exit" << endl;
		cin >> opcija;

		switch (opcija) {
		case 1:
			dogadjaji();
			break;
		case 2:
			noviDogadjaj();
			break;
		case 3:
			cout << "Unesite godinu mesec i dan";
			int godina, mesec, dan;
			cin >> godina;
			cin >> mesec;
			cin >> dan;
			dogadjaj->nastupa(godina, mesec, dan);
			break;
		case 4:
			kraj = true;
			return EXIT_SUCCESS;
			break;
		default:
			continue;
			break;
		}







	}

}

