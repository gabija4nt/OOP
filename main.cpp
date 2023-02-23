#include "Mylib.h"

const int max_paz_sk = 10;

struct studentas {
  string vardas = " ", pavarde = " ";
  int *paz = nullptr;
  int egz = 0;
  double gal_paz = 0;
};

void pild(studentas &temp) {
  cout << "Iveskite varda ir pavarde: ";
  cin >> temp.vardas >> temp.pavarde;

  int n = 0; // nd skaitiklis
  int mas[max_paz_sk] = {0};

  cout << "Iveskite pazymius (maksimalus kiekis: " << max_paz_sk <<
    "). Po paskutinio pazymio iveskite tasko simboli '.' (pvz.: 5.): " << endl;
  while (n < max_paz_sk && cin >> mas[n]) {
    if (mas[n] < 1 || mas[n] > 10) {
      cout << "Netinkamas pazymys." << endl;
    } else {
      ++n;
    }
    if (cin.peek() == '.') {
      cin.ignore(1, '\n');
      break;
    }
  }
  if (cin.fail()) {
    cout << "Klaida" << endl;
}
  

  temp.paz = new int[n];
  if (temp.paz == nullptr) {
    cout << "Klaida" << endl;
  }
  copy(mas, mas + n, temp.paz);
  temp.gal_paz = 0;

  if (n > 0) {
    cout << "Iveskite egzamino paz.: ";
    while (!(cin >> temp.egz) || (temp.egz > 10 || temp.egz < 1)) {
      cout << "Klaida! Iveskite is naujo: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    cout << "Duomenys irasyti" << endl;
    } else cout << "Duomenys neivesti" << endl;
}

void galutinis_v(studentas &temp) {
  double vid = 0;

  for (int i = 0; i < max_paz_sk; i++)
    vid += temp.paz[i];

  vid = vid / max_paz_sk;

  temp.gal_paz = 0.4 * vid + 0.6 * temp.egz;
}

void galutinis_m(studentas &temp) {
  sort(temp.paz, temp.paz + max_paz_sk);
  double med = 0;
  if(max_paz_sk % 2 == 0) {
        int mid = max_paz_sk / 2;
        med = (temp.paz[mid - 1] + temp.paz[mid]) / 2.0;
    }
    else {
        int mid = max_paz_sk / 2;
        med = temp.paz[mid];
    }
  
  temp.gal_paz = 0.4 * med + 0.6 * temp.egz;
}

void spausd(const studentas &temp) {
  cout << left << setw(10) << temp.vardas << setw(15) << temp.pavarde;
  cout << fixed << setprecision(2) << temp.gal_paz << endl;
  delete[] temp.paz;
}

int main() {
  int n = 1;
  studentas *grupe = new studentas[n];

  for (int i = 0; i < n; i++) pild(grupe[i]);

  char bud;
  cout << "Prasome pasirinkti pazymiu apdorojimo buda: vidurkis - v arba mediana - m: ";
    while (!(cin >> bud) || (bud != 'v' && bud != 'V' && bud != 'm' && bud != 'M')) {
  cout << "Klaida! Prasome pasirinkti pazymiu apdorojimo buda: vidurkis - v arba mediana - m: ";
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

  cout << left << setw(10) << "Vardas" << setw(15) << "Pavarde";

  if (bud == 'v' || bud == 'V') {
    for (int i = 0; i < n; i++)
      galutinis_v(grupe[i]);
    cout << left << "Galutinis (Vid.)" << endl;
    }
  if (bud == 'm' || bud == 'M') {
    for (int i = 0; i < n; i++)
      galutinis_m(grupe[i]);
    cout << left << "Galutinis (Med.)" << endl;
    }

  cout << "----------------------------------------------" << endl;
  for (int i = 0; i < n; i++)
    spausd(grupe[i]);

  delete[] grupe;
}
