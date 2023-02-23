#include "Mylib.h"

int main() {
  char x;
  vector<studentas> grupe;
  studentas temp;

  while (x != 'n' && x != 'N') {
  temp.paz.reserve(max_paz_sk);
  pild(temp);

  //uzpildo likusi vektoriu nuliais
  int num = max_paz_sk - temp.paz.size();
  for (int i = 0; i < num; i++) {
    temp.paz.push_back(0);
  }
    
  grupe.push_back(temp);
  temp.paz.clear();
  cout << "Noredami uzbaigti ivesti spauskite n \nNoredami testi spauskite bet kuri klavisa:";
  cin >> x;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

  char bud;
  cout << "Prasome pasirinkti pazymiu apdorojimo buda: vidurkis - v arba mediana - m: ";
  while (!(cin >> bud) || (bud != 'v' && bud != 'V' && bud != 'm' && bud != 'M')) {
    cout << "Klaida! Prasome pasirinkti pazymiu apdorojimo buda: vidurkis - v arba mediana - m: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  cout << left << setw(10) << "Vardas" << setw(15) << "Pavarde";

  if (bud == 'v' || bud == 'V') {
    for (auto &i: grupe) galutinis_v(i);
    cout << left << "Galutinis (Vid.)" << endl;
  }
  else {
    for (auto &i: grupe) galutinis_m(i);
    cout << left << "Galutinis (Med.)" << endl;
  }

  cout << "----------------------------------------------" << endl;
  for (const auto &i: grupe) spausd(i);

}
