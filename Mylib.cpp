#include "Mylib.h"
#include "mix.h"

void pild(studentas &temp, vector<string> splited, string &outputas) {
  for (auto &i: splited) {
  std::istringstream iss(i);
  iss >> temp.vardas >> temp.pavarde;
  int pazym;
  while (iss >> pazym) {
        temp.paz.push_back(pazym);
    }
  temp.egz = temp.paz.back();
  temp.paz.pop_back();
  galutinis_v(temp);
  galutinis_m(temp);

  std::ostringstream oss;
  oss << left << setw(10) << temp.vardas << setw(15) << temp.pavarde;
  oss << setw(20) << fixed << setprecision(2) << temp.gal_paz_v << temp.gal_paz_m << endl;
  i = oss.str();
  i.compare(*splited.rbegin()) !=0 ? outputas+=i+"\n": outputas+=i ;
  }
//   cout << "Iveskite studento varda ir pavarde: ";
//   cin >> temp.vardas >> temp.pavarde;
//   srand(time(NULL)); // seed the random number generator
//   for (int i = 0; i < max_paz_sk; i++) {
//     int grade = rand() % 11; // generate a random grade between 0 and 10
//     temp.paz.push_back(grade);
//     cout << "Pazymys " << i+1 << ": " << grade << endl;
//   }
//   int egz_paz = rand() % 11; // generate a random grade for the exam
//   temp.egz = egz_paz;
//   cout << "Egzamino rezultatas: " << egz_paz << endl;
 }

// void spausd(const studentas &temp) {
  
//   cout << left << setw(10) << temp.vardas << setw(15) << temp.pavarde;
//   cout << setw(10) << fixed << setprecision(2) << temp.gal_paz_v << temp.gal_paz_m << endl;
// }

void galutinis_v(studentas &temp) {
  double vid = 0;

  for (int i = 0; i < temp.paz.size(); i++)
    vid += temp.paz[i];

  vid = vid / temp.paz.size();

  temp.gal_paz_v = 0.4 * vid + 0.6 * temp.egz;
}

void galutinis_m(studentas &temp) {
  sort(temp.paz.begin(), temp.paz.end());
  double med = 0;
  int mid = temp.paz.size() / 2;
  if(temp.paz.size() % 2 == 0) med = (temp.paz[mid - 1] + temp.paz[mid]) / 2.0;
    else med = temp.paz[mid];
  
  temp.gal_paz_m = 0.4 * med + 0.6 * temp.egz;
}