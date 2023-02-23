#include "Mylib.h"
extern const int max_paz_sk;

void pild(studentas &temp) {
  cout << "Iveskite varda ir pavarde: ";
  cin >> temp.vardas >> temp.pavarde;
  int p;
  cout << "Iveskite pazymius (maksimalus kiekis: " << max_paz_sk <<
    "). Po paskutinio pazymio iveskite tasko simboli '.' (pvz.: 5.): " << endl;
  while (cin >> p && temp.paz.size() < max_paz_sk) {
    temp.paz.push_back(p);
    if (p < 1 || p > 10) {
      cout << "Netinkamas pazymys." << endl;
    }
    if (cin.peek() == '.') {
      cin.ignore(1, '\n');
      break;
    }
  }
  if (cin.fail()) {
    cout << "Klaida" << endl;
}
  temp.gal_paz = 0;

  cout << "Iveskite egzamino paz.: ";
    while (!(cin >> temp.egz) || (temp.egz > 10 || temp.egz < 1)) {
      cout << "Klaida! Iveskite is naujo: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
    cout << "Duomenys irasyti" << endl;
  
if (cin.fail()) cout << "Klaida" << endl;
}

void spausd(const studentas &temp) {
  
  cout << left << setw(10) << temp.vardas << setw(15) << temp.pavarde;
  cout << fixed << setprecision(2) << temp.gal_paz << endl;
}

void galutinis_v(studentas &temp) {
  double vid = 0;

  for (int i = 0; i < max_paz_sk; i++)
    vid += temp.paz[i];

  vid = vid / max_paz_sk;

  temp.gal_paz = 0.4 * vid + 0.6 * temp.egz;
}

void galutinis_m(studentas &temp) {
  sort(temp.paz.begin(), temp.paz.end());
  double med = 0;
  int mid = max_paz_sk / 2;
  if(max_paz_sk % 2 == 0) med = (temp.paz[mid - 1] + temp.paz[mid]) / 2.0;
    else med = temp.paz[mid];
  
  temp.gal_paz = 0.4 * med + 0.6 * temp.egz;
}
