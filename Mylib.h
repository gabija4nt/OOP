#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::fixed;
using std::string;
using std::copy;
using std::sort;
using std::numeric_limits;
using std::streamsize;
using std::vector;

const int max_paz_sk = 10;

struct studentas {
  string vardas = " ", pavarde = " ";
  vector<int> paz;
  int egz = 0;
  double gal_paz = 0;
};

void pild(studentas &temp);
void spausd(const studentas &temp);
void galutinis_v(studentas &temp);
void galutinis_m(studentas &temp);
