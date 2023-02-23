#include "Mylib.h"
extern const int max_paz_sk;

void pild(studentas &temp) {
  cout << "Iveskite studento varda ir pavarde: ";
  cin >> temp.vardas >> temp.pavarde;
  srand(time(NULL)); // seed the random number generator
  for (int i = 0; i < max_paz_sk; i++) {
    int grade = rand() % 11; // generate a random grade between 0 and 10
    temp.paz.push_back(grade);
    cout << "Pazymys " << i+1 << ": " << grade << endl;
  }
  int egz_paz = rand() % 11; // generate a random grade for the exam
  temp.egz = egz_paz;
  cout << "Egzamino rezultatas: " << egz_paz << endl;
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
